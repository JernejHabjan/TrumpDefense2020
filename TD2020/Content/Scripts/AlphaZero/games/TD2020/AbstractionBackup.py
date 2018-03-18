"""
Current money							(int)
Grid tile size							(vector)


0_Base
    Current Position (tile / xy) 		(vector)
    Current Health						(int)
    Move per turn 						(float)
    Damage per turn 					(int)
    Current executing action (constructing building, gathering resources, attacking, idle...)	(??????????????????????????????????)
BuildingMaster
    current position (tile /xy)    		(vector)
    current hp							(int)
    current producing units (array 0_base characterju in progression top characterja - to je za NPC in za Conscripte) (?????????????????????????)
    rally location					 	(vector)
    damage per turn						(int)
Construction site
    current position					(vector)
    current hp							(int)
    Progression							(float - percent)
Resources
    Position 							(vector)
    currently remaining resources		(int)
"""

from queue import *
import numpy as np

grid = None


class Tile:
    actors = []

    def actors(self):
        return self.actors


class Grid:
    def __init__(self, num):
        self.num = num
        self.tiles = [Tile() for i in range(num)]

    def actor(self, location):
        return self.tiles[location].actors()


class Resources:
    def __init__(self, amount):
        self.amount = amount


class UnitProductionComponent:
    def __init__(self, unit_types):
        self.unit_types = unit_types
        self.current_production_time = 0  # production time of current unit
        self.producing_units = Queue()

    # produces unit by index from array
    def construct_unit(self, type):
        character = Character(type)
        production_time = character.production_time
        if production_time > self.current_production_time:
            # spawn character and reset timer
            self.producing_units.pop().spawn(self.current_position, self.rally_position)
        else:
            self.current_production_time += 1


class Unit:
    def __init__(self, team_name, production_time):
        self.team_name = team_name
        self.current_position = ()
        self.production_time = production_time
        self.hp = 0

    def manage_hp(self, in_hp):
        self.hp += in_hp


class BuildingMaster(Unit):
    def __init__(self, team_name, production_time, current_position, rally_position, hp, damage):
        super.__init__(team_name, production_time)
        self.current_position = current_position
        self.rally_position = rally_position
        self.hp = hp
        self.occupants = ()
        self.damage = damage
        self.unit_production_component = None

    def enter(self, actor):
        self.occupants.add(actor)

    def exit(self, actor):
        self.occupants.remove(actor)


class TownHall(BuildingMaster):
    unit_types = ["NPC"]

    def __init__(self):
        self.unit_production_component = UnitProductionComponent(self.unit_types)

class Barracks(BuildingMaster):
    unit_types = ["Ranged"]
    def __init__(self):
        self.unit_production_component = UnitProductionComponent(self.unit_types)

class Character(Unit):
    def __init__(self, current_position, rally_position, hp, damage):
        self.current_position = current_position
        self.rally_position = rally_position
        self.hp = hp
        self.damage = damage
        self.current_building = None  # building we are currently in

    ##### HELPER FUNCITONS
    def friendly(self, actor):
        return self.team_name == actor.team_name


class UnitAction:
    def __init__(self, unit):
        self.actions = ["none", "move", "harvest", "return", "produce", "attack"]
        self.unit = unit

    def execute_move(self, new_location, actor=None):
        actor = grid.getActor(new_location)
        if actor:
            if self.unit.friendly(actor):
                try:
                    building = actor  # as BuildingMaster
                    self.current_building = building
                    self.current_building.enter(actor)
                except:
                    print("not building master")
            else:
                self.attack(actor)
        else:
            self.current_position = new_location

    def attack(self, actor):
        actor.manage_hp(-self.unit.damage)

    def manage_hp(self, in_hp):
        self.hp += in_hp

    ###### ACTIONS
    def up(self):
        self.execute_move(self.current_position + 8)

    def down(self):
        self.execute_move(self.current_position - 8)

    def right(self):
        self.execute_move(self.current_position + 1)

    def left(self):
        self.execute_move(self.current_position - 1)

    def idle(self):
        pass

    def mine_at_location(self):
        pass

    def build_construction_office_at_location(self):
        pass

    def build_house_at_location(self):
        pass

    def build_mining_shack_at_location(self):
        pass

    def build_barracks_at_location(self):
        pass


class Startup():
    grid = Grid(64)
    # init resources
    grid.tiles[0] = Resources(200)
    grid.tiles[63] = Resources(200)

    # init players
    grid.tiles[1] = TownHall()
    grid.tiles[62] = TownHall()
