from collections import defaultdict
import pandas as pd
import json
from pandas.io.json import json_normalize
from numpy import *


class FL:
    # HELPER FUNCTIONS
    @staticmethod
    def friendly(actor1, actor2):
        return actor1.team_name == actor2.team_name


def retrieve_json(filename, name=''):
    with open('datatables\\' + filename + '.json') as f:
        dict_train = json.load(f)
    # noinspection PyTypeChecker
    df = pd.DataFrame.from_dict(json_normalize(dict_train), orient='columns')
    if name != '':
        print(df[df["Name"] == "Sentry"])
        return df[df["Name"] == "Sentry"]
    print(df)
    return df


class Player:
    team_name = None
    money = 0
    actors = set()
    start_location = 0

    def __init__(self, team_name, start_location):
        self.team_name = team_name
        self.start_location = start_location
        self.initial_spawn()

    def initial_spawn(self):
        # spawn initial buildings and characters
        self.actors.add(TownHall("TownHall", self.team_name, self.start_location))
        self.actors.add(NPC("NPC", self.team_name, self.start_location + 1))

    def calculate_score(self):
        return sum(actor.Value for actor in self.actors)


class Tile:
    actors = []


class Grid:
    def __init__(self, num):
        self.num = num
        self.tiles = [Tile() for i in range(num)]

    def get_actors(self, location):
        return self.tiles[location].actors


class UnitProductionComponent:
    def __init__(self, parent, unit_types):
        self.parent = parent
        self.unit_types = unit_types
        self.current_production_time = 0  # production time of current unit
        self.producing_units = []

    # produces unit by index from array
    def construct_unit(self, class_name):
        character_temp = eval(class_name)(class_name, self.parent.team_name, self.parent.location)

        production_time = character_temp.production_time
        if production_time > self.current_production_time:
            # spawn character and reset timer
            self.producing_units.pop()
            # spawn character
            character = eval(class_name)(class_name, self.parent.team_name, self.parent.location)
            a = Action(character)
            a.spawn_here(class_name, class_name, self.parent.team_name, self.parent.location)
        else:
            self.current_production_time += 1


class MyActor:
    # config variables
    td_my_actor = None
    health = None
    vision = None
    production_time = None
    refund_factor = None
    production_cost = None
    value = None
    # variables
    location = ()
    current_production_time = 0  # amount that this building / character has been produced

    def __init__(self, name, team_name, location):
        self.name = name
        self.team_name = team_name
        self.location = location
        # read td_myactor
        self.td_my_actor = retrieve_json('td_myactor', name)
        self.health = self.td_my_actor["Health"]
        self.vision = self.td_my_actor["Vision"]
        self.production_time = self.td_my_actor["ProductionTime"]
        # self.production_cost = self.td_my_actor["ProductionCost"] ## TODO production cost is nested dictionary in
        # TODO json file - dataframe cannot read it??
        self.tech_requirements = self.td_my_actor["TechRequirements"]
        self.value = self.td_my_actor["Value"]

    def manage_hp(self, in_health):
        self.health += in_health

    def update(self):
        pass

    def __del__(self):
        print("Actor destroyed")


class BuildingMaster(MyActor):
    # config variables
    max_employees = None
    max_residents = None
    max_build_amount = None

    # variables
    occupants = []
    employees = []

    def __init__(self, name, team_name, location):
        super().__init__(name, team_name, location)
        self.max_employees = self.td_my_actor["MaxEmployees"]
        self.max_residents = self.td_my_actor["MaxResidents"]
        self.max_build_amount = self.td_my_actor["MaxBuildAmount"]
        self.unit_production_component = None


class TownHall(BuildingMaster):
    unit_types = ["NPC"]

    def __init__(self, name, team_name, location):
        super().__init__(name, team_name, location)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)


class AttackComponent:
    def __init__(self, name):
        # attack parameters
        self.td_attack = retrieve_json('td_attack', name)
        self.cooldown = self.td_attack["Cooldown"]
        self.damage = self.td_attack["Damage"]
        self.range = self.td_attack["Range"]
        self.acquisition_radius = self.td_attack["AcquisitionRadius"]
        self.critical_damage = self.td_attack["CriticalDamage"]


class Barracks(BuildingMaster):
    unit_types = ["RifleInfantry"]

    def __init__(self, name, team_name, production_time):
        super().__init__(name, team_name, production_time)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)


class Sentry(BuildingMaster):
    def __init__(self, name, team_name, production_time):
        super().__init__(name, team_name, production_time)
        self.attack_component = AttackComponent(self.name)


class Character(MyActor):
    is_busy = False

    def __init__(self, name, team_name, location):
        super().__init__(name, team_name, location)
        self.current_building = None  # building we are currently in


class NPC(Character):
    gather_amount = 0  # currently holding resources
    max_gather_amount = 20  # max of how much can hold resources

    def __init__(self, name, team_name, location):
        super().__init__(name, team_name, location)


class RangedUnit(Character):
    def __init__(self, name, team_name, location):
        super().__init__(name, team_name, location)
        self.attack_component = AttackComponent(self.name)


class Action:
    def __init__(self, actor):
        self.actions = {"idle", "up", "down", "right", "left", "mine", "return", "attack", "npc",
                        "rifle_infantry", "town_hall", "barracks", "sentry", "continue_building"}
        self.actor = actor

    def execute_move(self, new_location, actor=None):
        actors = game.world.get_actors(new_location)
        for actor in actors:
            if FL.friendly(self.actor, actor):
                # move it there
                game.world.tiles[new_location].actors.append(self.actor)
                self.actor.location = new_location
            # if not friendly
            else:
                self.attack(self, actor)

        else:
            game.world.tiles[new_location].actors.append(self.actor)
            self.actor.location = new_location

    @staticmethod
    def attack(self, actor):
        if actor.health > 0:
            actor.manage_hp(-self.actor.damage)
        else:
            # remove him
            game.world.tiles[actor.location].remove(actor)
            del actor
            # check if maybe it was last building
            game.check_end_condition()

    def manage_hp(self, in_health):
        self.actor.health += in_health

    # ACTIONS

    def up(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.location + 8)

    def down(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.location - 8)

    def right(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.location + 1)

    def left(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.location - 1)

    def idle(self):
        pass

    def mine_at_location(self, resource):
        if type(self.actor) is NPC and self.actor.gather_amount < self.actor.max_gather_amount:
            if self.actor.location == resource.location:
                resource.amount -= resource.gather_amount
                self.actor.gather_amount += resource.gather_amount

    def return_resources(self, mine):
        if self.actor.location == mine.location:
            # TODO --ADD MONEY HERE
            self.actor.gather_amount = 0

    def spawn_here(self, class_name, name, team_name, location):  # spawns construction proxy or unit when completed
        building = eval(class_name)(name, team_name, location)
        self.actor.location.actors.append(building)

    def continue_building(self, building):  # continues building building for + 1 time
        if self.actor.location == building.location:
            if building.current_production_time < building.production_time:
                building.current_production_time += 1


class ResourcesMaster:
    location = ()
    amount = 0
    name = ''

    def __init__(self, location, amount=2000):
        self.location = location
        self.amount = amount
        self.td_resource = retrieve_json('td_resource', self.name)
        self.gather_amount = self.td_resource["Capacity"]


class Granite(ResourcesMaster):
    name = 'Granite'

    def __init__(self, location):
        super().__init__(location, amount=2000)


class Game:
    players = defaultdict(list)
    world = None

    iteration = 0  # game iteration

    # team names can include also multiple instances of team names- if there are two players with same team name,
    # both are appended to same team
    def __init__(self, team_names, timeout, world_size=64, ):  # timeout is number of moves to timeout
        self.world = Grid(world_size)
        self.timeout = timeout
        # init
        self.spawn_players(world_size, team_names)
        self.start_tick()

    def spawn_players(self, world_size, team_names):
        spawn_locations = linspace(0, world_size, size(team_names))
        for i, team_name in enumerate(team_names):
            self.players[team_name].append(Player(team_name, spawn_locations[i]))

    def start_tick(self):
        while True:
            if self.check_timeout() == -1 or self.check_end_condition() == -1:
                return -1

            # run tick on all actors

            for team in self.players.values():
                for player in team:
                    for actor in player.actors:
                        actor.update()

    def check_end_condition(self):
        for team_name, players in self.players.items():
            for player in players:
                if not len(player.actors):
                    print("Player of team " + team_name + " lost")
                    print("---> GAME END <---")
                    return -1

    def check_timeout(self):
        if self.iteration > self.timeout:
            print("---> TIMEOUT <---")
            return -1
        # update iteration
        self.iteration += 1


game = Game(["Team 1", "Team 2"], 10000)
