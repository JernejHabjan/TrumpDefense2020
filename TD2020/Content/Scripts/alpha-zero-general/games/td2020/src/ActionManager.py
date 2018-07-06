import numpy as np

from config_file import MAX_ACTORS_ON_TILE, ALL_ACTIONS
from games.td2020.src.FunctionLibrary import friendly, dist
from games.td2020.src.Board import Board


class ActionManager:

    def __init__(self, actor, actions):
        from games.td2020.src.Actors import MyActor

        self.actions = actions
        self.actor: MyActor = actor
        self.enemy_actor: MyActor = None

        self.ATTACK_COMPONENT_PRIORITY = 1  # priority of attacking actor with attack component rather than one without attack component

    # ACTIONS

    def choose_enemy(self, board: Board):
        print("choosing enemy")

        # choose nearest enemy, where priority are those with attack component by constant factor

        nearest_enemy = None
        nearest_enemy_dist = np.inf
        # negate player so we are choosing opponents enemies
        for actor in board.players[-self.actor.player].actors:
            distance = dist(self.actor, actor)

            if hasattr(actor, "attack_component"):
                distance -= self.ATTACK_COMPONENT_PRIORITY

            if distance < nearest_enemy_dist:
                nearest_enemy_dist = distance
                nearest_enemy = actor

        self.enemy_actor = nearest_enemy

    def attack(self, board: Board):

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
            if enemy in board.players[enemy.player].actors:
                board.players[enemy.player].actors.remove(enemy)

            if enemy in board[enemy.x][enemy.y].actors:
                board[enemy.x][enemy.y].actors.remove(enemy)

            del enemy

    def npc(self, board: Board):

        self.actor.unit_production_component.construct_unit("NPC", board)

    def rifle_infantry(self, board: Board):

        self.actor.unit_production_component.construct_unit("RifleInfantry", board)

    def town_hall(self, board: Board):
        self._spawn_here("TownHall", board)

    def barracks(self, board: Board):
        self._spawn_here("Barracks", board)

    def sentry(self, board: Board):
        self._spawn_here("Sentry", board)

    def mining_shack(self, board: Board):
        self._spawn_here("MiningShack", board)

    def up(self, board: Board):

        self._execute_move(self.actor.x, self.actor.y - 1, board)

    def down(self, board: Board):

        self._execute_move(self.actor.x, self.actor.y + 1, board)

    def right(self, board: Board):

        self._execute_move(self.actor.x + 1, self.actor.y, board)

    def left(self, board: Board):

        self._execute_move(self.actor.x - 1, self.actor.y, board)

    def idle(self, board: Board):
        pass

    def mine_resources(self, board: Board):

        from games.td2020.src.Actors import ResourcesMaster

        resource = None
        for actor in board[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break

        print("successfully mined resources")
        resource.amount -= resource.gather_amount
        self.actor.gather_amount += resource.gather_amount

    def return_resources(self, board: Board):

        # add money
        board.players[self.actor.player].money += self.actor.gather_amount
        # reset gather amount
        self.actor.gather_amount = 0
        print("new money amount " + str(board.players[self.actor.player].money))

    def continue_building(self, board: Board):  # continues building building for +1 time
        # get building to construct on this tile

        from games.td2020.src.Actors import MyActor
        building: MyActor = None
        for actor in board[self.actor.x][self.actor.y].actors:
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

    def execute_action(self, action, board: Board):
        if self.can_execute_action(action, board):
            self.actor.current_action = action
            # print("Executing " + action + " by", type(self.actor).__name__)
            eval("self." + action + "(board)")

    # noinspection PyUnusedLocal
    def can_execute_action(self, action: str, board: Board):
        production_percent = float(self.actor.current_production_time) / float(self.actor.production_time)  # value between 0 and 1
        if production_percent == 1:
            # print("checking if action " + action + " can be executed...")
            can_execute = eval("self.can_" + action + "(board)")
            # print("executed: " + str(can_execute))
            return can_execute
        else:
            print("cannot execute action - not constructed to max")
            return False

    # noinspection PyUnusedLocal,PyMethodMayBeStatic
    def can_idle(self, board: Board):
        return True

    def can_up(self, board: Board):
        return self._can_execute_move(self.actor.x, self.actor.y - 1, board)

    def can_down(self, board: Board):
        return self._can_execute_move(self.actor.x, self.actor.y + 1, board)

    def can_right(self, board: Board):
        return self._can_execute_move(self.actor.x + 1, self.actor.y, board)

    def can_left(self, board: Board):
        return self._can_execute_move(self.actor.x - 1, self.actor.y, board)

    def can_mine_resources(self, board: Board):
        from games.td2020.src.Actors import ResourcesMaster
        # find if there are any resources on this location
        resource = None
        for actor in board[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break
        # no resources found on this location - return

        from games.td2020.src.Actors import NPC
        return resource is not None and isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount

    def can_return_resources(self, board: Board):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # find if there are any mines on this location
        resource_deposit_actor = None
        for actor in board[self.actor.x][self.actor.y].actors:
            if hasattr(actor, 'resources_deposit_component'):
                resource_deposit_actor = actor
                break
        # no mines found on this location - return

        return resource_deposit_actor is not None and friendly(resource_deposit_actor, self.actor)

    # noinspection PyUnusedLocal
    def can_choose_enemy(self, board: Board):
        return hasattr(self.actor, 'attack_component')

    # noinspection PyUnusedLocal
    def can_attack(self, board: Board):
        # check if enemy has been chosen:
        # check if we can attack
        # check range
        return self.enemy_actor is not None and hasattr(self.actor, 'attack_component') and dist(self.actor, self.enemy_actor) <= self.actor.attack_component.range

    def can_npc(self, board: Board):
        return self._can_character_spawn("NPC", board)

    def can_rifle_infantry(self, board: Board):
        return self._can_character_spawn("RifleInfantry", board)

    def can_town_hall(self, board: Board):
        return self._can_spawn_here(board, "TownHall")

    def can_barracks(self, board: Board):
        return self._can_spawn_here(board, "Barracks")

    def can_sentry(self, board: Board):
        return self._can_spawn_here(board, "Sentry")

    def can_mining_shack(self, board: Board):
        return self._can_spawn_here(board, "MiningShack")

    def can_continue_building(self, board: Board):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False
        for actor in board[self.actor.x][self.actor.y].actors:
            from games.td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster) and friendly(actor, self.actor):
                # we found building on this tile and its friendly
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    return True
        return False

    # HELPER METHODS
    def _execute_move(self, new_x: int, new_y: int, board: Board):
        # print("moving from ", self.actor.x, self.actor.y, " to new location", new_x, new_y)
        # remove from old tile
        board[self.actor.x][self.actor.y].actors.remove(self.actor)

        # add to new tile
        board[new_x][new_y].actors.append(self.actor)
        self.actor.x, self.actor.y = new_x, new_y

    def _spawn_here(self, name: str, board: Board):  # spawns construction proxy
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack
        if self._can_spawn_here(board, name):
            building = eval(name)(self.actor.player, self.actor.x, self.actor.y)
            # pay
            board.players[self.actor.player].money -= building.production_cost

            building.spawn(board)
            print("spawned new building - adding to player actors" + str(type(building)))

        else:
            print("not enough money")

    def _can_execute_move(self, new_x: int, new_y: int, board: Board):
        from games.td2020.src.Actors import Character

        return 0 <= new_x < board.width and 0 <= new_y < board.height and issubclass(type(self.actor), Character) and len(board[new_x][new_y].actors) < MAX_ACTORS_ON_TILE

    def _can_spawn_here(self, board: Board, name: str):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack

        # check if here no buildings exist yet
        building_exists_on_tile = any(isinstance(actor, BuildingMaster) for actor in board[self.actor.x][self.actor.y].actors)

        if building_exists_on_tile:
            print("buildings already exist on this tile. Returning False")
            return False

        if len(board[self.actor.x][self.actor.y].actors) == MAX_ACTORS_ON_TILE:
            print("cannot spawn here - " + str(MAX_ACTORS_ON_TILE) + " already on tile")
            return False

        # get production cost of this

        building = eval(name)(self.actor.player, self.actor.x, self.actor.y)

        print("checking cost...")
        # check if we can pay for construction proxy
        return board.players[self.actor.player].money >= building.production_cost

    def _can_character_spawn(self, name: str, board: Board):
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import RifleInfantry, NPC
        character_temp = eval(name)(0, 0, 0)

        return hasattr(self.actor, 'unit_production_component') and name in self.actor.unit_production_component.unit_types and board.players[self.actor.player].money >= character_temp.production_cost and len(board[self.actor.x][self.actor.y].actors) < MAX_ACTORS_ON_TILE

    def count_num_valid_moves(self, board: Board) -> list:
        num_valid_moves: list = []
        for action_str in ALL_ACTIONS.keys():
            if self.can_execute_action(action_str, board):
                # print("can execute action str: ", action_str)
                num_valid_moves.append(1)
            else:
                num_valid_moves.append(0)
        return num_valid_moves
