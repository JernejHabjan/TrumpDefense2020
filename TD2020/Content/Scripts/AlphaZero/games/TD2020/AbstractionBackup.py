import json
import random
from collections import defaultdict
import pygame
import pandas as pd
from numpy import *
from pandas.io.json import json_normalize


# PROTOTYPING

class Game: pass


class Tile: pass


def friendly(actor1, actor2):
    return actor1.team_name == actor2.team_name


def retrieve_json(filename, row_name=None):
    with open('datatables\\' + filename + '.json') as f:
        dict_train = json.load(f)
    # noinspection PyTypeChecker
    df = pd.DataFrame.from_dict(json_normalize(dict_train), orient='columns')
    if row_name:
        # print(df[df["Name"] == row_name])
        return df[df["Name"] == row_name]
    # print(df)
    return df


class Player:
    def __init__(self, world_ref: Game, team_name: str, start_location: Tile):
        self.world_ref = world_ref
        self.team_name = team_name
        self.start_location = start_location

        print("CHECKING START LOCATION CLASS" + str(type(self.start_location)))

        # set variables
        self.money = 0
        self.actors = []

        # spawn
        self.initial_spawn()

    def initial_spawn(self):
        print("initial spawn")
        # spawn initial buildings and characters
        town_hall = TownHall(self, "TownHall", self.team_name, self.start_location)
        rifle_infantry = RifleInfantry(self, "RifleInfantry", self.team_name, self.start_location)
        town_hall.health = town_hall.max_health
        self.actors.append(town_hall)
        self.actors.append(rifle_infantry)
        print(size(self.actors))

    def calculate_score(self):
        for actor in self.actors:
            print("actor of type" + str(type(actor)))
        return sum(actor.value for actor in self.actors)


class Tile:
    def __init__(self, location: int):
        self.location = location
        self.actors = []


class Grid:
    def __init__(self, num: int):
        self.num = num
        self.tiles = [Tile(i) for i in range(num)]

    def get_actors(self, location):
        return self.tiles[location].actors


class GeneralActor:
    def __init__(self, name: str, tile: Tile):
        self.name = name
        self.tile = tile


class MyActor(GeneralActor):

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(name, tile)
        self.player = player
        self.team_name = team_name
        # read td_myactor

        self.td_my_actor: pd.DataFrame = retrieve_json('td_myactor', name)
        self.max_health = self.td_my_actor["MaxHealth"].values[0]
        self.vision: int = self.td_my_actor["Vision"].values[0]
        self.production_time: int = self.td_my_actor["ProductionTime"].values[0]
        self.production_cost: int = 50  # TODO - temp 50
        # self.production_cost = self.td_my_actor["ProductionCost"].values[0] ## TODO production cost is nested dictionary in
        # TODO json file - dataframe cannot read it??
        self.tech_requirements = self.td_my_actor["TechRequirements"].values[0]
        self.value = self.td_my_actor["Value"].values[0]

        # variables
        self.current_production_time: int = 0  # amount that this building / character has been produced
        self.health = self.max_health * 0.1  # 10%

    def update(self):
        pass

    def __del__(self):
        pass
        # print("Actor destroyed")


class BuildingMaster(MyActor):

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        # config variables

        self.max_employees: int = self.td_my_actor["MaxEmployees"].values[0]
        self.max_residents: int = self.td_my_actor["MaxResidents"].values[0]
        self.max_build_amount: int = self.td_my_actor["MaxBuildAmount"].values[0]


class UnitProductionComponent:
    def __init__(self, parent: BuildingMaster, unit_types: list):
        self.parent = parent
        self.unit_types = unit_types
        self.current_production_time: int = 0  # production time of current unit
        self.producing_units: list = []

    # produces unit by index from array
    def construct_unit(self, class_name):  ## TODO -- TLE NEKI FALI KER USAKIČ CREATAM NOVGA CHARACTERJA NE PA IZ QUEUE
        print("started constructing unit " + class_name)
        character_temp: MyActor = eval(class_name)(self.parent.player, class_name, self.parent.team_name,
                                                   self.parent.tile)
        self.producing_units.append(character_temp)

    def update(self):
        print("running unit production component update")
        if size(self.producing_units) <= 0:
            return

        if self.current_production_time >= self.producing_units[0].production_time:

            print("finished updating unit production")
            # spawn character and reset timer
            character = self.producing_units.pop()  # todo - not sure if poping right one
            # spawn character - by adding it to player
            self.parent.player.actors.append(character)
        else:
            print(
                "continuing constructing unit " + str(type(self.producing_units[0])) + " with construction time " + str(
                    self.current_production_time) + " of " + str(self.producing_units[0].production_time))

            self.current_production_time += 1


class TownHall(BuildingMaster):
    unit_types = ["NPC"]

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

    def update(self):
        self.unit_production_component.update()


class AttackComponent:
    def __init__(self, name: str):
        # attack parameters
        self.td_attack: pd.DataFrame = retrieve_json('td_attack', name)
        self.cooldown = self.td_attack["Cooldown"].values[0]
        self.damage = 10  # TODO TEMP
        # self.damage = self.td_attack["Damage"].values[0] ## TODO DAMAGE IS AGAIN DICTINARY - REPLACING WITH TEMP
        self.range = self.td_attack["Range"].values[0]
        self.acquisition_radius = self.td_attack["AcquisitionRadius"].values[0]
        self.critical_damage = 2  # TODO TEMP
        # self.critical_damage = self.td_attack["CriticalDamage"].values[0] ## TODO AGAIN DICT


class Barracks(BuildingMaster):
    unit_types = ["RifleInfantry"]

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

    def update(self):
        self.unit_production_component.update()


class Sentry(BuildingMaster):
    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        self.attack_component = AttackComponent(self.name)


class Character(MyActor):
    is_busy = False

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        # set health to max after spawn
        self.health = self.max_health


class NPC(Character):
    gather_amount = 0  # currently holding resources
    max_gather_amount = 20  # max of how much can hold resources

    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)


class RifleInfantry(Character):
    def __init__(self, player: Player, name: str, team_name: str, tile: Tile):
        super().__init__(player, name, team_name, tile)
        self.attack_component = AttackComponent(self.name)


class Action:
    def __init__(self, actor: MyActor, other_actor: GeneralActor):
        # print("init")
        #
        self.actions = ["idle", "up", "down", "right", "left", "mine_resources", "return_resources", "attack", "npc",
                        "rifle_infantry", "town_hall", "barracks", "sentry", "continue_building"]
        self.actions = ["attack"]
        self.actor = actor
        self.other_actor = other_actor

        # print("printing loc" + str(self.actor.tile))
        print("NEW ACTION BY " + actor.name)

    def execute_move(self, new_location: int, actor: MyActor = None):  # TODO move
        actors = game.world.get_actors(new_location)
        for actor in actors:
            if friendly(self.actor, actor):
                # move it there
                game.world.tiles[new_location].actors.append(self.actor)
                self.actor.tile = new_location
            # if not friendly
            else:
                self.attack()

        else:
            game.world.tiles[new_location].actors.append(self.actor)
            self.actor.tile = new_location

    def attack(self):

        # check if we can attack
        if not hasattr(self.actor, 'attack_component'):
            return

        # TODO -check if in range - beware that range is circular, but here im subtracting twho numbers in array
        # if(self.actor.attack_component.range < abs(self.actor.tile.location - self.other_actor.tile.location)):
        #    print("not in range")
        #    return

        print("ATTACKING ENEMY " + self.other_actor.name)

        enemy = self.other_actor
        if enemy.health > 0:
            print("DAMAGE " + str(self.actor.attack_component.damage))
            print("enemy health ->" + str(enemy.health) + " of max " + str(enemy.max_health))
            enemy.health -= self.actor.attack_component.damage

        # after damaging him check if he is dead
        if enemy.health <= 0:
            print("ENEMY KILLED" + str(type(enemy)) + " of team " + enemy.player.team_name)

            # remove him
            # enemy.tile.actors.remove(enemy) # Todo - remove him from world
            enemy.player.actors.remove(enemy)

            # temp area

            for actor in enemy.player.actors:
                print("actors left: " + str(type(actor)))

            # end temp area
            del enemy

            # check if maybe it was last building
            self.actor.player.world_ref.check_end_condition()

    def npc(self):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("NPC")

    def rifle_infantry(self):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("RifleInfantry")

    def town_hall(self):
        self.spawn_here("TownHall")

    def barracks(self):
        self.spawn_here("Barracks")

    def sentry(self):
        self.spawn_here("Sentry")

    # ACTIONS

    def up(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.tile.location + 8)

    def down(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.tile.location - 8)

    def right(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.tile.location + 1)

    def left(self):
        if type(self.actor) is Character:
            self.execute_move(self.actor.tile.location - 1)

    def idle(self):
        pass

    def mine_resources(self):
        resource = self.other_actor
        if type(self.actor) is NPC and type(
                resource) is ResourcesMaster and self.actor.gather_amount < self.actor.max_gather_amount:
            if self.actor.tile == resource.location:
                resource.amount -= resource.gather_amount
                self.actor.gather_amount += resource.gather_amount

    def return_resources(self):
        mine = self.other_actor
        if self.actor.tile == mine.tile and type(self.actor) is NPC:
            # add money
            self.actor.player.money += self.actor.gather_amount
            # reset gather amount
            self.actor.gather_amount = 0

    def spawn_here(self, name: str):  # spawns construction proxy

        # get production cost of this actor
        td_my_actor: pd.DataFrame = retrieve_json('td_myactor', name)
        production_cost: int = 50  # TODO - temp 50
        # production_cost = self.td_my_actor["ProductionCost"].values[0] ## TODO production cost is nested dictionary in
        # TODO json file - dataframe cannot read it??

        # check if we can pay for construction proxy
        if self.actor.player.money >= production_cost:
            # pay
            self.actor.player.money -= production_cost

            building = eval(name)(self.actor.player, name, self.actor.team_name, self.actor.tile)
            print("checking spawn here location class" + str(type(self.actor.tile)))

            self.actor.tile.actors.append(building)
            print("spawned new building - adding to player actors")
            self.actor.player.actors.append(building)
        else:
            print("not enough money")

    def continue_building(self):  # continues building building for +1 time
        building = self.other_actor
        if self.actor.tile == building.tile:
            if building.current_production_time < building.production_time:
                building.current_production_time += 1
                # todo -increment health - to cover whole 100% when built to max - same as sc2

    def execute_action(self, action):
        # print("Executing " + action)
        eval("self." + action + "()")


class ResourcesMaster(GeneralActor):
    def __init__(self, name: str, location: Tile, amount: int = 2000):
        super().__init__(name, location)
        self.amount = amount
        self.td_resource: pd.DataFrame = retrieve_json('td_resource', self.name)
        self.gather_amount: int = self.td_resource["Capacity"].values[0]


class Granite(ResourcesMaster):

    def __init__(self, location: Tile):
        super().__init__("Granite", location, amount=2000)


class Game:

    # team names can include also multiple instances of team names- if there are two players with same team name,
    # both are appended to same team
    def __init__(self, team_names: list, timeout: int, world_size: int = 64):  # timeout is number of moves to timeout
        self.world = Grid(world_size)
        self.timeout = timeout
        self.players = defaultdict(list)
        self.iteration: int = 0  # game iteration
        # init

        #### VISUALSSSSSSSS
        pygame.init()
        display_width, display_height = 800, 800
        black = (0, 0, 0)
        white = (255, 255, 255)
        red = (255, 0, 0)
        # https://youtu.be/ZFo4mtLJEWs?t=634

        carImg = pygame.image.load('racecar.jpg')

        def car(x, y):
            game_display.blit(carImg, (x, y))

        def text_objects(text, font):
            text_surface = font.render(text, True, black)
            return text_surface, text_surface.get_rect()

        def message_display(game_display, text, position, size):
            large_text = pygame.font.Font('Cyberbit.ttf', size)
            text_surf, text_rect = text_objects(text, large_text)
            text_rect.center = position
            game_display.blit(text_surf, text_rect)

        game_display = pygame.display.set_mode((display_width, display_height))
        pygame.display.set_caption('TD2020 Python game')
        clock = pygame.time.Clock()
        crashed = False
        while not crashed:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    crashed = True
                print(event)

            game_display.fill(white)
            # car(x,y)
            for i in range(50, 850, 100):
                for j in range(50, 850, 100):
                    pygame.draw.circle(game_display, red, (i, j), 40)
                    message_display(game_display, u"🤑", (i, j), 40)


            pygame.display.update()
            clock.tick(60)
        pygame.quit()

        ## END VISUALSSSSSSSSS

        self.spawn_world(world_size)
        self.spawn_players(world_size, team_names)
        self.start_tick()

        # here end game occurred so check scoring who won
        for team in self.players.values():
            for player in team:
                for actor in player.actors:
                    print(type(actor).__name__)
                print(player.team_name + " got score of " + str(player.calculate_score()))

    def spawn_world(self, world_size: int):
        # spawn granite
        self.world.tiles[int(world_size / 2)].actors.append(Granite(self.world.tiles[int(world_size / 2)]))

    def spawn_players(self, world_size: int, team_names: list):
        spawn_padding: int = 4
        spawn_locations: float = linspace(spawn_padding, world_size - spawn_padding, size(team_names))
        for i, team_name in enumerate(team_names):
            spawn_location = int(spawn_locations[i])

            print("added player from " + team_name + " on spawn " + str(spawn_location))
            self.players[team_name].append(Player(self, team_name, self.world.tiles[spawn_location]))

    def start_tick(self):
        while True:
            if self.check_timeout() == -1 or self.check_end_condition() == -1:
                return -1

            # run tick on all actors
            for team in self.players.values():
                print("TEAM" + str(team))
                for player in team:
                    print(" ______________ TEAM " + player.team_name + "_______________")
                    for actor in player.actors:
                        # if actor.health <= 0:
                        #    print("HELATH IS LOVER THAT 0")
                        #    continue
                        # print("health " + str(actor.health))
                        #
                        for actor in player.actors:
                            print("BEFORE EXECUTING ACTION " + str(type(actor)))

                        actor.update()

                        # print(" CHECKING ACTORS LOC" + str(actor.location) + str(type(actor)))

                        # get enemy
                        enemy = None
                        for enemy_team in self.players.values():

                            for enemy_player in enemy_team:
                                if enemy_player != player:
                                    enemy = random.choice(enemy_player.actors)
                        # end get enemy

                        action = Action(actor,
                                        enemy)  # TODO - here select OTHER ACTOR FOR SECOND ACTOR  - for like attack or mine or etc!!!
                        # choose random action
                        action.execute_action(random.choice(action.actions))

    def check_end_condition(self):
        for team_name, players in self.players.items():
            for player in players:
                print("Player of team " + team_name + " has " + str(size(player.actors)) + " actors.")
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


game = Game(["Team 1", "Team 2"], 7)
