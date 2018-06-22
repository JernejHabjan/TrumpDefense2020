import numpy as np

from games.td2020.src.FunctionLibrary import friendly, dist
from games.td2020.src.Board import Board
from games.td2020.src.config_file import *


class ActionManager:

    def __init__(self, actor, actions):
        from games.td2020.src.Actors import MyActor

        self.actions = actions
        self.actor: MyActor = actor
        self.enemy_actor: MyActor = None

        self.ATTACK_COMPONENT_PRIORITY = 1  # priority of attacking actor with attack component rather than one without attack component

    # ACTIONS

    def choose_enemy(self, world: Board):
        print("choosing enemy")

        # choose nearest enemy, where priority are those with attack component by constant factor

        nearest_enemy = None
        nearest_enemy_dist = np.inf
        # negate player so we are choosing opponents enemies
        for actor in world.players[-self.actor.player].actors:
            distance = dist(self.actor, actor)

            if hasattr(actor, "attack_component"):
                distance -= self.ATTACK_COMPONENT_PRIORITY

            if distance < nearest_enemy_dist:
                nearest_enemy_dist = distance
                nearest_enemy = actor

        self.enemy_actor = nearest_enemy

    def attack(self, world: Board):

        print("Attacking enemy " + str(type(self.enemy_actor)))

        enemy = self.enemy_actor
        if enemy.health > 0:
            # print("DAMAGE " + str(self.actor.attack_component.damage))
            # print("enemy health ->" + str(enemy.health) + " of max " + str(enemy.max_health))
            enemy.health -= self.actor.attack_component.damage

        # after damaging him check if he is dead
        if enemy.health <= 0:
            print("Enemy killed" + str(type(enemy)) + " of team " + str(enemy.player))

            # remove him
            if enemy in world.players[enemy.player].actors:
                world.players[enemy.player].actors.remove(enemy)

            if enemy in world[enemy.x][enemy.y].actors:
                world[enemy.x][enemy.y].actors.remove(enemy)

            del enemy

    def npc(self, world: Board):

        self.actor.unit_production_component.construct_unit("NPC", world)

    def rifle_infantry(self, world: Board):

        self.actor.unit_production_component.construct_unit("RifleInfantry", world)

    def town_hall(self, world: Board):
        self._spawn_here("TownHall", world)

    def barracks(self, world: Board):
        self._spawn_here("Barracks", world)

    def sentry(self, world: Board):
        self._spawn_here("Sentry", world)

    def mining_shack(self, world: Board):
        self._spawn_here("MiningShack", world)

    def up(self, world: Board):

        self._execute_move(self.actor.x, self.actor.y - 1, world)

    def down(self, world: Board):

        self._execute_move(self.actor.x, self.actor.y + 1, world)

    def right(self, world: Board):

        self._execute_move(self.actor.x + 1, self.actor.y, world)

    def left(self, world: Board):

        self._execute_move(self.actor.x - 1, self.actor.y, world)

    def idle(self, world: Board):
        pass

    def mine_resources(self, world: Board):

        from games.td2020.src.Actors import ResourcesMaster

        resource = None
        for actor in world[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break

        print("successfully mined resources")
        resource.amount -= resource.gather_amount
        self.actor.gather_amount += resource.gather_amount

    def return_resources(self, world: Board):

        # add money
        world.players[self.actor.player].money += self.actor.gather_amount
        # reset gather amount
        self.actor.gather_amount = 0
        print("new money amount " + str(world.players[self.actor.player].money))

    def continue_building(self, world: Board):  # continues building building for +1 time
        # get building to construct on this tile

        from games.td2020.src.Actors import MyActor
        building: MyActor = None
        for actor in world[self.actor.x][self.actor.y].actors:
            from games.td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster) and friendly(actor, self.actor):
                # we found building on this tile
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    building = actor
                    break

        # continue building this building you are standing on
        print("Continue building ")

        building.current_production_time += 1

        # increment building health to cover 100% when completely built if building is not damaged while being built
        remaining_initial = building.max_health * 0.9  # 10% of building hp is added at spawn construction proxy
        increment = remaining_initial / building.production_time
        building.health += increment

    def execute_action(self, action, world: Board):
        if self.can_execute_action(action, world):
            self.actor.current_action = action
            # print("Executing " + action + " by", type(self.actor).__name__)
            eval("self." + action + "(world)")

    # ACTION CHECKING

    # noinspection PyUnusedLocal
    def can_execute_action(self, action: str, world: Board):
        production_percent = float(self.actor.current_production_time) / float(self.actor.production_time)  # value between 0 and 1
        if production_percent == 1:
            # print("checking if action " + action + " can be executed...")
            can_execute = eval("self.can_" + action + "(world)")
            # print("executed: " + str(can_execute))
            return can_execute
        else:
            print("cannot execute action - not constructed to max")
            return False

    # noinspection PyUnusedLocal,PyMethodMayBeStatic
    def can_idle(self, world: Board):
        return True

    def can_up(self, world: Board):
        return self._can_execute_move(self.actor.x, self.actor.y - 1, world)

    def can_down(self, world: Board):
        return self._can_execute_move(self.actor.x, self.actor.y + 1, world)

    def can_right(self, world: Board):
        return self._can_execute_move(self.actor.x + 1, self.actor.y, world)

    def can_left(self, world: Board):
        return self._can_execute_move(self.actor.x - 1, self.actor.y, world)

    def can_mine_resources(self, world: Board):
        from games.td2020.src.Actors import ResourcesMaster
        # find if there are any resources on this location
        resource = None
        for actor in world[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break
        # no resources found on this location - return

        from games.td2020.src.Actors import NPC
        return resource is not None and isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount

    def can_return_resources(self, world: Board):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # find if there are any mines on this location
        resource_deposit_actor = None
        for actor in world[self.actor.x][self.actor.y].actors:
            if hasattr(actor, 'resources_deposit_component'):
                resource_deposit_actor = actor
                break
        # no mines found on this location - return

        return resource_deposit_actor is not None and friendly(resource_deposit_actor, self.actor)

    # noinspection PyUnusedLocal
    def can_choose_enemy(self, world: Board):
        return hasattr(self.actor, 'attack_component')

    # noinspection PyUnusedLocal
    def can_attack(self, world: Board):
        # check if enemy has been chosen:
        # check if we can attack
        # check range
        return self.enemy_actor is not None and hasattr(self.actor, 'attack_component') and dist(self.actor, self.enemy_actor) <= self.actor.attack_component.range

    def can_npc(self, world: Board):
        return self._can_character_spawn("NPC", world)

    def can_rifle_infantry(self, world: Board):
        return self._can_character_spawn("RifleInfantry", world)

    def can_town_hall(self, world: Board):
        return self._can_spawn_here(world, "TownHall")

    def can_barracks(self, world: Board):
        return self._can_spawn_here(world, "Barracks")

    def can_sentry(self, world: Board):
        return self._can_spawn_here(world, "Sentry")

    def can_mining_shack(self, world: Board):
        return self._can_spawn_here(world, "MiningShack")

    def can_continue_building(self, world: Board):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False
        for actor in world[self.actor.x][self.actor.y].actors:
            from games.td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster) and friendly(actor, self.actor):
                # we found building on this tile and its friendly
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    return True
        return False

    # HELPER METHODS
    def _execute_move(self, new_x: int, new_y: int, world: Board):
        # print("moving from ", self.actor.x, self.actor.y, " to new location", new_x, new_y)
        # remove from old tile
        world[self.actor.x][self.actor.y].actors.remove(self.actor)

        # add to new tile
        world[new_x][new_y].actors.append(self.actor)
        self.actor.x, self.actor.y = new_x, new_y

    def _spawn_here(self, name: str, world: Board):  # spawns construction proxy
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack
        if self._can_spawn_here(world, name):
            building = eval(name)(self.actor.player, self.actor.x, self.actor.y)
            # pay
            world.players[self.actor.player].money -= building.production_cost

            building.spawn(world)
            print("spawned new building - adding to player actors" + str(type(building)))

        else:
            print("not enough money")

    def _can_execute_move(self, new_x: int, new_y: int, world: Board):
        from games.td2020.src.Actors import Character

        return 0 <= new_x < world.width and 0 <= new_y < world.height and issubclass(type(self.actor), Character) and len(world[new_x][new_y].actors) < MAX_ACTORS_ON_TILE

    def _can_spawn_here(self, world: Board, name: str):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack

        # check if here no buildings exist yet
        building_exists_on_tile = any(isinstance(actor, BuildingMaster) for actor in world[self.actor.x][self.actor.y].actors)

        if building_exists_on_tile:
            print("buildings already exist on this tile. Returning False")
            return False

        if len(world[self.actor.x][self.actor.y].actors) == MAX_ACTORS_ON_TILE:
            print("cannot spawn here - " + str(MAX_ACTORS_ON_TILE) + " already on tile")
            return False

        # get production cost of this

        building = eval(name)(self.actor.player, self.actor.x, self.actor.y)

        print("checking cost...")
        # check if we can pay for construction proxy
        return world.players[self.actor.player].money >= building.production_cost

    def _can_character_spawn(self, name: str, world: Board):
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import RifleInfantry, NPC
        character_temp = eval(name)(0, 0, 0)

        return hasattr(self.actor, 'unit_production_component') and name in self.actor.unit_production_component.unit_types and world.players[self.actor.player].money >= character_temp.production_cost and len(
            world[self.actor.x][self.actor.y].actors) < MAX_ACTORS_ON_TILE

    def count_num_valid_moves(self, world: Board) -> list:
        num_valid_moves: list = []
        for action_str in ALL_ACTIONS.keys():
            if self.can_execute_action(action_str, world):
                # print("can execute action str: ", action_str)
                num_valid_moves.append(1)
            else:
                num_valid_moves.append(0)
        return num_valid_moves
