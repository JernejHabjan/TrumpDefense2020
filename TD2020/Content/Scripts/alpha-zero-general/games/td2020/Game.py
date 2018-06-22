from __future__ import print_function
import sys

import numpy as np

from systems.utils import DotDict
from games.td2020.src.Board import Board
import copy


from games.td2020.src.config_file import *

sys.path.append('..')


class Game:
    def __init__(self, args: DotDict):
        self.args = args
        self.width = args.width
        self.height = args.height
        self.fps = args.fps
        # self.saved_world = Board(width, height)  # todo - here is saved world used for all kinds of stuff like accessing actors if only numeric board has been given --- DUNNO
        self.verbose = args.verbose


    def getInitBoard(self):
        # return initial board (numpy board)
        # print("board initialized")

        return Board(self.args)

    def getBoardSize(self):
        # (a,b) tuple
        # return self.n, self.n
        return self.width, self.height, MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN

    def getActionSize(self):
        # return number of actions
        # same output length as getValidMoves
        return self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN

    @staticmethod
    def actionIntoArr(board, action: int) -> list:
        # this parses action like "450" into position x,y and actor index on board and action int what action that is
        index = 0
        # convert object board to numpy array
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
    def actionInttoArrModulo(board, action: int) -> list:
        # todo - optional
        return []

    @staticmethod
    def arrIntoAction(board, action_array: list) -> int:
        # to get from array like  ['1', '1', '0', '0', 'npc'] index of action like "25"
        counter = 0
        for y in range(board.height):

            for x in range(board.width):
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    for action_str, action_int in ALL_ACTIONS.items():

                        if action_array[2] == str(y) and action_array[1] == str(x) and action_array[3] == str(actor_index) and action_array[4] == action_str:
                            return counter
                        else:
                            counter += 1
        return -1

    def getNextState(self, board, player: int, action: int):

        # if type(board) is np.ndarray:
        #     print_e("Error - get next state retrieved ndarray")
        #     board = self.saved_world  # TODO

        # create copy of old world and execute actions on new one

        # print("iteration", str(board.iteration))

        new_world: Board = copy.deepcopy(board)

        player = new_world.players[player]

        # beware that first value is random prefix (number 1) to prevent from trimming leading 0 when x position is 0
        # try:
        # print("printing action in getNextState", action)

        action_into_arr_array = self.actionIntoArr(new_world, action)
        x = action_into_arr_array[0]
        y = action_into_arr_array[1]
        actor_index = action_into_arr_array[2]
        action_str = ALL_ACTIONS_INT[action_into_arr_array[3]]
        # print("------------- ACTION ----------------------------", x, y, actor_index, action_str)

        actor = new_world[x][y].actors[actor_index]
        actor.update(new_world, action_str)

        # TODO - updating iteration here
        new_world.iteration += 1

        # self.saved_world = new_world  # TODO
        # except Exception :
        #    print("not valid action: ", str(action))
        return new_world, -player.name

    @staticmethod
    def getValidMoves(board, player: int) -> np.array:

        # if type(board) is np.ndarray:
        #     print_e("Error - get valid moves retrieved ndarray")
        #     board = self.saved_world  # TODO

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
    def getGameEnded(board, player: int) -> float:
        # return 0 if not ended, 1 if player 1 won, -1 if player 1 lost
        # player = 1

        if len(board.players[player].actors) >= 3:
            # print("_____________________________________ PLAYER " + str(player) + " HAS REACHED END CONDITION ______________________________________")

            return player

        if len(board.players[-player].actors) >= 3:
            # print("_____________________________________ PLAYER " + str(player) + " HAS REACHED END CONDITION ______________________________________")

            return -player

        if board.timeout():
            # print("Timeouted")
            return 1e-4

        # if len(self.saved_world.players[player].actors) == 0:  # TODO - checking agains saved world and not canonical board -may be different
        #     return -player
        # if len(self.saved_world.players[-player].actors) == 0:
        #     return player

        # lets create custom win condition - build 3 npcs:

        return 0

    @staticmethod
    def getCanonicalForm(board, player: int) -> np.ndarray:
        # return state if player==1, else return -state if player==-1

        # if type(board) is np.ndarray:  # TODO - done -> object to array
        #     return player * board

        from games.td2020.src.Actors import MyActor

        numeric_board: list = []
        # convert object board to numpy array
        for y in range(board.height):

            board_row: list = []
            for x in range(board.width):
                board_row_actors: list = []
                for actor_index in range(MAX_ACTORS_ON_TILE):  # Todo - a tle vrnem 4d array kjer so notr actionsi ali 3d kjer so notr actorji

                    # check if its not granite
                    # if actor_index < len(board[x][y].actors) and issubclass(type(board[x][y].actors[actor_index]), MyActor):
                    #    # actor found on this tile, append actors value
                    #    actor = board[x][y].actors[actor_index]
                    #    board_row_actors.append(actor.player * actor.numeric_value)  # todo - possible problem - because values may be compared with "action" which consists of huge int - 11343 and cannot be found in this array ??
                    # elif actor_index < len(board[x][y].actors):
                    #    # this may be minerals !!!
                    #    actor = board[x][y].actors[actor_index]
                    #    board_row_actors.append( actor.numeric_value)
                    #
                    # else:
                    #    # no actors found on this tile - append 0
                    #    board_row_actors.append(0)

                    # todo -- OTHER OPTION WITH 4D
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

                    # todo - END OTHER OPTION WITH 4D

                board_row.append(board_row_actors)

            numeric_board.append(board_row)

        numeric_board = np.array(numeric_board).tolist()
        # print("Printing numeric board of length:", len(numeric_board), "\n", numeric_board)
        # print("printing canonical board",np.array(numeric_board))
        return np.array(numeric_board)

    def getSymmetries(self, canonical_board: np.ndarray, pi: np.array) -> np.ndarray:
        # mirror, rotational
        # assert (len(pi) == self.n ** 2 + 1)  # 1 for pass # todo -this assert is wrong - it should be 8x8x4x2 - because pi = 512 which is 8*8*4*2

        # pi_board = np.reshape(pi[:-1], (self.n, self.n)) #todo reshape?

        pi_board = np.reshape(pi, (self.width, self.height, MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN))  # todo reshape? -- is this correct???????? dunno

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
    def getScore(board, player):
        return board.players[player].calculate_score()


def display(board):
    board.display()
