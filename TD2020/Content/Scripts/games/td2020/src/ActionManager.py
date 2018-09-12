from typing import List

import numpy as np

from config_file import MAX_ACTORS_ON_TILE, ALL_ACTIONS
from games.td2020.src import Actors
from games.td2020.src import Board
from games.td2020.src.FunctionLibrary import friendly, dist, get_nearest_instance_of_class, can_add_unit, get_valid_nearby_coordinates


class ActionManager:

    def __init__(self, actor: 'Actors.MyActor', actions: List[str]) -> None:

        self.actions: List[str] = actions
        self.actor: 'Actors.MyActor' = actor
        self.enemy_actor: 'Actors.MyActor' = None

        self.ATTACK_COMPONENT_PRIORITY = 1  # priority of attacking actor with attack component rather than one without attack component

    # ACTIONS

    def _choose_enemy(self, board: 'Board.Board') -> None:

        """
        choose nearest enemy, where priority are those with attack component by constant factor
        :param board:
        :return:
        """
        print("choosing enemy")

        nearest_enemy: 'Actors.MyActor' = None
        nearest_enemy_dist: float = np.inf
        # negate player so we are choosing opponents enemies
        for actor in board.players[-self.actor.player].actors:
            distance: float = dist(self.actor, actor)

            if hasattr(actor, "attack_component"):
                distance -= self.ATTACK_COMPONENT_PRIORITY

            if distance < nearest_enemy_dist:
                nearest_enemy_dist = distance
                nearest_enemy = actor

        self.enemy_actor = nearest_enemy

    def _attack(self, board: Board) -> None:
        print("Attacking enemy " + str(type(self.enemy_actor)))

        enemy: 'Actors.MyActor' = self.enemy_actor
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

            self.enemy_actor = None

    def _npc(self, board: Board) -> None:
        self.actor.unit_production_component.construct_unit("NPC", board)

    def _rifle_infantry(self, board: Board) -> None:
        self.actor.unit_production_component.construct_unit("RifleInfantry", board)

    def _town_hall(self, board: Board) -> None:
        self._spawn_here("TownHall", board)

    def _barracks(self, board: Board) -> None:
        self._spawn_here("Barracks", board)

    def _sentry(self, board: Board) -> None:
        self._spawn_here("Sentry", board)

    def _mining_shack(self, board: Board) -> None:
        self._spawn_here("MiningShack", board)

    def _up(self, board: Board) -> None:
        self._execute_move(self.actor.x, self.actor.y - 1, board)

    def _down(self, board: Board) -> None:
        self._execute_move(self.actor.x, self.actor.y + 1, board)

    def _right(self, board: Board) -> None:
        self._execute_move(self.actor.x + 1, self.actor.y, board)

    def _left(self, board: Board) -> None:
        self._execute_move(self.actor.x - 1, self.actor.y, board)

    def _idle(self, board: Board) -> None:
        pass

    def _mine_resources(self, board: Board) -> None:

        from games.td2020.src.Actors import ResourcesMaster  # this here is needed as is - i think - TODO CHECK ČE LAHKO DRGAČ DA DAŠ 'Actors.ResourcesMaster' TO NOTR v get_nearst_instance_of_class
        resource: ResourcesMaster = get_nearest_instance_of_class(board, self.actor.x, self.actor.y, ResourcesMaster)

        resource.amount -= resource.gather_amount
        self.actor.gather_amount += resource.gather_amount

    def _return_resources(self, board: Board) -> None:
        # add money
        board.players[self.actor.player].money += self.actor.gather_amount
        # reset gather amount
        self.actor.gather_amount = 0
        print("new money amount " + str(board.players[self.actor.player].money))

    # noinspection PyUnresolvedReferences
    def _continue_building(self, board: Board) -> None:
        """
        continues building building for +1 time
        :param board:
        :return:
        """
        # get building to construct on this tile

        from games.td2020.src.Actors import BuildingMaster
        building: BuildingMaster = get_nearest_instance_of_class(board, self.actor.y, self.actor.y, BuildingMaster, opts="actor.current_production_time < actor.production_time")
        # continue building this building you are standing on
        print("Continue building ")

        building.current_production_time += 1

        # increment building health to cover 100% when completely built if building is not damaged while being built
        remaining_initial = building.max_health * 0.9  # 10% of building hp is added at spawn construction proxy
        increment = remaining_initial / building.production_time
        building.health += increment

    def execute_action(self, action, board: Board) -> None:
        """
        :param action:
        :param board:
        :return:
        USED: Actors - MyActor - update
        """
        if self.can_execute_action(action, board):
            self.actor.current_action = action
            # print("Executing " + action + " by", type(self.actor).__name__)
            eval("self._" + action + "(board)")

    # noinspection PyUnusedLocal
    def can_execute_action(self, action: str, board: Board) -> int:
        production_percent = float(self.actor.current_production_time) / float(self.actor.production_time)  # value between 0 and 1
        if production_percent == 1:
            # print("checking if action " + action + " can be executed...")
            can_execute = eval("self._can_" + action + "(board)")
            # print("executed: " + str(can_execute))
            return 1 if can_execute else 0
        else:
            print("cannot execute action - not constructed to max")
            return 0

    # noinspection PyUnusedLocal,PyMethodMayBeStatic
    def _can_idle(self, board: Board) -> bool:
        return True

    def _can_up(self, board: Board) -> bool:
        return self._can_execute_move(self.actor.x, self.actor.y - 1, board)

    def _can_down(self, board: Board) -> bool:
        return self._can_execute_move(self.actor.x, self.actor.y + 1, board)

    def _can_right(self, board: Board) -> bool:
        return self._can_execute_move(self.actor.x + 1, self.actor.y, board)

    def _can_left(self, board: Board) -> bool:
        return self._can_execute_move(self.actor.x - 1, self.actor.y, board)

    def _can_mine_resources(self, board: Board) -> bool:
        from games.td2020.src.Actors import ResourcesMaster
        # find if there are any resources on this location
        resource: ResourcesMaster = get_nearest_instance_of_class(board, self.actor.x, self.actor.y, ResourcesMaster)

        from games.td2020.src.Actors import NPC
        return resource is not None and isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount

    def _can_return_resources(self, board: Board) -> bool:
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # find if there are any mines on this location
        resource_deposit_actor = None
        for x, y in get_valid_nearby_coordinates(board, self.actor.x, self.actor.y):
            for actor in board[x][y].actors:
                if hasattr(actor, 'resources_deposit_component'):
                    resource_deposit_actor = actor
                    break
        # no mines found on this location - return

        return resource_deposit_actor is not None and friendly(resource_deposit_actor, self.actor)

    # noinspection PyUnusedLocal
    def _can_choose_enemy(self, board: Board) -> bool:
        return hasattr(self.actor, 'attack_component')

    # noinspection PyUnusedLocal
    def _can_attack(self, board: Board) -> bool:
        # check if enemy has been chosen:
        # check if we can attack
        # check range
        return self.enemy_actor is not None and hasattr(self.actor, 'attack_component') and dist(self.actor, self.enemy_actor) <= self.actor.attack_component.range

    def _can_npc(self, board: Board) -> bool:
        return self._can_character_spawn("NPC", board)

    def _can_rifle_infantry(self, board: Board) -> bool:
        return self._can_character_spawn("RifleInfantry", board)

    def _can_town_hall(self, board: Board) -> bool:
        return self._can_spawn_here(board, "TownHall")

    def _can_barracks(self, board: Board) -> bool:
        return self._can_spawn_here(board, "Barracks")

    def _can_sentry(self, board: Board):
        return self._can_spawn_here(board, "Sentry")

    def _can_mining_shack(self, board: Board) -> bool:
        return self._can_spawn_here(board, "MiningShack")

    def _can_continue_building(self, board: Board) -> bool:
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        from games.td2020.src.Actors import BuildingMaster
        return True if get_nearest_instance_of_class(board, self.actor.y, self.actor.y, BuildingMaster, opts="actor.current_production_time < actor.production_time") else False

    # HELPER METHODS
    def _execute_move(self, new_x: int, new_y: int, board: Board) -> None:
        # print("moving from ", self.actor.x, self.actor.y, " to new location", new_x, new_y)
        # remove from old tile
        board[self.actor.x][self.actor.y].actors.remove(self.actor)

        # add to new tile
        board[new_x][new_y].actors.append(self.actor)
        self.actor.x, self.actor.y = new_x, new_y

    def _spawn_here(self, name: str, board: Board) -> None:  # spawns construction proxy
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack
        if self._can_spawn_here(board, name):
            building: BuildingMaster = eval(name)(self.actor.player, self.actor.x, self.actor.y)
            # pay
            board.players[self.actor.player].money -= building.production_cost

            building.spawn(board, self.actor.x, self.actor.y)
            print("spawned new building - adding to player actors" + str(type(building)))

        else:
            print("not enough money")

    def _can_execute_move(self, new_x: int, new_y: int, board: Board) -> bool:
        from games.td2020.src.Actors import Character

        return 0 <= new_x < board.width and 0 <= new_y < board.height and issubclass(type(self.actor), Character) and len(board[new_x][new_y].actors) < MAX_ACTORS_ON_TILE

    def _can_spawn_here(self, board: Board, name: str) -> bool:
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack

        # check if here no buildings exist yet

        if not can_add_unit(board, self.actor.x, self.actor.y, is_building=True):
            return False

        # get production cost of this

        building: BuildingMaster = eval(name)(self.actor.player, self.actor.x, self.actor.y)

        # check if we can pay for construction proxy
        # noinspection PyUnresolvedReferences
        return board.players[self.actor.player].money >= building.production_cost

    def _can_character_spawn(self, name: str, board: Board) -> bool:
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import RifleInfantry, NPC, Character
        character_temp: Character = eval(name)(0, 0, 0)

        return hasattr(self.actor, 'unit_production_component') and name in self.actor.unit_production_component.unit_types and board.players[self.actor.player].money >= character_temp.production_cost and can_add_unit(board, self.actor.x, self.actor.y)

    def count_num_valid_moves(self, board: Board) -> List[int]:
        """
        :param board:
        :return:
        USED: Game - get valid moves - to append how many valid moves can this actor perform
        """
        num_valid_moves: list = []
        for action_str in ALL_ACTIONS.keys():
            if self.can_execute_action(action_str, board):
                # print("can execute action str: ", action_str)
                num_valid_moves.append(1)
            else:
                num_valid_moves.append(0)
        return num_valid_moves
