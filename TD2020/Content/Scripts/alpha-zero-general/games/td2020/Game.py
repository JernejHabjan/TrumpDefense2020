from __future__ import print_function
import copy
import sys
import numpy as np
from games.td2020.src.Board import Board
from games.td2020.src.config_file import *
from systems.utils import DotDict

sys.path.append('..')


class Game:
    def __init__(self, args: DotDict):
        self.args = args
        self.width = args.width
        self.height = args.height
        self.fps = args.fps
        self.verbose = args.verbose

    def getInitBoard(self) -> Board:
        return Board(self.args)

    def getBoardSize(self) -> tuple:
        return self.width, self.height, MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN

    def getActionSize(self) -> int:
        return self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN

    @staticmethod
    def actionIntoArr(board: Board, action: int) -> list:
        # this parses action like "450" into position x,y and actor index on board and action int what action that is
        index = 0
        for y in range(board.height):
            for x in range(board.width):
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    for action_str, action_int in ALL_ACTIONS.items():
                        if index == action:
                            a = x
                            b = y
                            c = actor_index
                            d = action_int
                            return [a, b, c, d]
                        index += 1
        print("ERROR - action is not valid - too big number to exist in this grid")
        return []

    # noinspection PyUnusedLocal
    @staticmethod
    def _action_into_arr_modulo(board: Board, action: int) -> list:
        # todo - optional
        return []

    @staticmethod
    def arr_into_action(board: Board, action_array: list) -> int:
        # to get from array like  ['1', '1', '0', '0', 'npc'] index of action like "25"
        counter = 0
        for y in range(board.height):
            for x in range(board.width):
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    for action_str, action_int in ALL_ACTIONS.items():
                        if str(action_array[1]) == str(x) and str(action_array[2]) == str(y) and str(action_array[3]) == str(actor_index) and action_array[4] == action_str:
                            return counter
                        else:
                            counter += 1
        return -1

    def getNextState(self, board: Board, player: int, action: int):

        # create copy of old world and execute actions on new one
        new_world: Board = copy.deepcopy(board)

        player = new_world.players[player]

        # beware that first value is random prefix (number 1) to prevent from trimming leading 0 when x position is 0
        action_into_arr_array = self.actionIntoArr(new_world, action)
        x = action_into_arr_array[0]
        y = action_into_arr_array[1]
        actor_index = action_into_arr_array[2]
        action_str = ALL_ACTIONS_INT[action_into_arr_array[3]]
        # print("------------- ACTION ----------------------------", x, y, actor_index, action_str)

        actor = new_world[x][y].actors[actor_index]
        actor.update(new_world, action_str)

        # updating timeout game iteration here
        new_world.iteration += 1

        return new_world, -player.name

    @staticmethod
    def getValidMoves(board: Board, player: int) -> np.array:
        # return a fixed size binary vector
        from games.td2020.src.Actors import MyActor
        valid_moves: list = []
        for y in range(board.height):
            for x in range(board.width):
                some_arr: list = []
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    # check if actor exists on this tile, if its of class MyActor and if its friendly
                    if actor_index < len(board[x][y].actors) and issubclass(type(board[x][y].actors[actor_index]), MyActor) and board[x][y].actors[actor_index].player == player:
                        # ok this is this players myactor
                        actor = board[x][y].actors[actor_index]
                        valid_moves.extend(actor.action_manager.count_num_valid_moves(board))
                    else:
                        # here empty space
                        some_arr.extend([0] * ALL_ACTIONS_LEN)
                valid_moves.extend(some_arr)
        # print("printing valid moves", valid_moves)
        return np.array(valid_moves)

    @staticmethod
    def getGameEnded(board: Board) -> float:
        # return 0 if not ended, 1 if player 1 won, -1 if player 1 lost

        # lets create custom win condition - build 3 npcs:
        if len(board.players[1].actors) >= 3:
            return 1
        if len(board.players[-1].actors) >= 3:
            return -1
        if board.timeout():
            # print("Timeouted")
            return 1e-4

        # # Final rules - learning to defeat other player
        # if len(self.saved_world.players[player].actors) == 0:
        #     return -player
        # if len(self.saved_world.players[-player].actors) == 0:
        #     return player

        return 0

    @staticmethod
    def getCanonicalForm(board: Board, player: int) -> np.ndarray:
        # return state if player==1, else return -state if player==-1

        from games.td2020.src.Actors import MyActor
        numeric_board: list = []
        # convert object board to numpy array
        for y in range(board.height):

            board_row: list = []
            for x in range(board.width):
                board_row_actors: list = []
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    board_row_actors_actions: list = []
                    # check if its not granite
                    if actor_index < len(board[x][y].actors) and issubclass(type(board[x][y].actors[actor_index]), MyActor):
                        actor = board[x][y].actors[actor_index]

                        for action_str, action_int in ALL_ACTIONS.items():
                            if actor.action_manager.can_execute_action(action_str, board):

                                # return positive numbers for this player, negative for other player
                                if actor.player == player:
                                    board_row_actors_actions.append(action_int)
                                else:
                                    board_row_actors_actions.append(-action_int)
                            else:
                                board_row_actors_actions.append(0)
                    else:

                        board_row_actors_actions.append([0] * len(ALL_ACTIONS))  # empty actions for empty actors and minerals
                    board_row_actors = np.array(board_row_actors).flatten()
                    # board_row_actors.append(board_row_actors_actions)
                    board_row_actors = np.append(board_row_actors, board_row_actors_actions)

                board_row.append(board_row_actors)

            numeric_board.append(board_row)

        numeric_board = np.array(numeric_board).tolist()

        return np.array(numeric_board)

    @staticmethod
    def getSymmetries(canonical_board: np.ndarray, pi: np.array) -> np.ndarray:
        # mirror, rotational
        pi_board = np.reshape(pi, (canonical_board.shape[0], canonical_board.shape[1], MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN))

        l = []

        for i in range(1, 5):
            for j in [True, False]:
                new_b = np.rot90(canonical_board, i)
                new_pi = np.rot90(pi_board, i)
                if j:
                    new_b = np.fliplr(new_b)

                    new_pi = np.fliplr(new_pi)
                l += [(new_b, list(new_pi.ravel()) + [pi[-1]])]

        return l

    @staticmethod
    def stringRepresentation(canonical_board: np.ndarray) -> bytes:
        # 8x8 numpy array (canonical board)
        return np.array(canonical_board).tostring()

    @staticmethod
    def getScore(board: Board, player: int) -> float:
        return board.players[player].calculate_score()


def display(board: Board):
    board.display()
