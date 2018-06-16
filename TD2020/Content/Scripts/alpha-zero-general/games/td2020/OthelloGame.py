from __future__ import print_function
import sys

import numpy as np

from .OthelloLogic import Board
import copy

sys.path.append('..')

MAX_ACTORS_ON_TILE = 4  # Predefined so neural network can receive fixed array


class OthelloGame:
    def __init__(self, n):

        self.n = n

        self.saved_world = Board(self.n)  # todo - here is saved world used for all kinds of stuff like accessing actors if only numeric board has been given --- DUNNO

    def getInitBoard(self):
        # return initial board (numpy board)
        print("board initialized")
        self.saved_world = Board(self.n)  # TODO

        return self.saved_world

    def getBoardSize(self):
        # (a,b) tuple
        return self.n, self.n

    def getActionSize(self):
        # return number of actions
        # same output length as getValidMoves
        return self.n * self.n * MAX_ACTORS_ON_TILE * len(self.saved_world.ALL_ACTIONS)

    def getNextState(self, board, player: int, action: int):

        if type(board) is np.ndarray:
            board = self.saved_world  # TODO

        # create copy of old world and execute actions on new one

        print("iteration", str(board.iteration))

        new_world: Board = copy.deepcopy(board)

        player = new_world.players[player]

        # beware that first value is random prefix (number 1) to prevent from trimming leading 0 when x position is 0
        # try:
        print("printing action in getNextState", action)
        if action == -1:
            print("Error - action not set in Search mcts")

        neki1 = 496 / len(board.ALL_ACTIONS)
        print(neki1)
        a = neki1 % len(board.ALL_ACTIONS)

        neki2 = neki1 / board.MAX_ACTORS_ON_TILE
        print(neki2)
        b = neki2 % board.MAX_ACTORS_ON_TILE

        neki3 = neki2 / board.width
        print(neki3)
        c = neki3 % board.width

        neki4 = neki3 / board.height
        d = neki4 % board.height
        #####################################################################################################

        ## TODO - lazy way witohut modulos
        index = 0
        # convert object board to numpy array
        for y in range(board.height):

            for x in range(board.width):

                for actor_index in range(board.MAX_ACTORS_ON_TILE):

                    for action_str, action_int in board.ALL_ACTIONS.items():

                        if index == action:
                            a = x
                            b = y
                            c = board.MAX_ACTORS_ON_TILE - actor_index - 1  # TODO - fora je ker je index 3 un ke ga prvo najde namest 0 - maybe odštejem tko pa dela???'
                            d = action_int
                            break
                        index += 1
                    #####################################################################################################

        print("printing moduled values", a, b, c, d)

        # action_arr = [int(digit) for digit in str(action)]
        # x = int(action_arr[1])
        # y = int(action_arr[2])
        # actor_index = int(action_arr[3])
        # action_str = board.ALL_ACTIONS_INT[int(str(action_arr[4]) + str(action_arr[5]))]

        x = a
        y = b
        actor_index = c
        action_str = board.ALL_ACTIONS_INT[d]

        bbb = new_world[7][7].actors[0]
        actor = new_world[x][y].actors[actor_index]
        actor.update(new_world, action_str)

        # TODO - updating iteration here
        new_world.iteration += 1

        self.saved_world = new_world  # TODO
        # except Exception :
        #    print("not valid action: ", str(action))
        return new_world, -player.name

    def getValidMoves(self, board, player: int) -> np.array:

        if type(board) is np.ndarray:
            board = self.saved_world  # TODO

        # return a fixed size binary vector
        from games.td2020.src.Actors import MyActor
        valid_moves: list = []

        for y in range(board.height):
            for x in range(board.width):
                some_arr: list = []
                for actor_index in range(board.MAX_ACTORS_ON_TILE):

                    # check if actor exists on this tile, if its of class MyActor and if its friendly
                    if actor_index < len(board[x][y].actors) and issubclass(type(board[x][y].actors[actor_index]), MyActor) and board[x][y].actors[actor_index].player == player:
                        # ok this is this players myactor
                        print("actor index in getValid moves", actor_index)
                        actor = board[x][y].actors[actor_index]
                        valid_moves.extend(actor.action_manager.count_num_valid_moves(board))
                    else:
                        # here empty space
                        some_arr.extend([0] * len(board.ALL_ACTIONS))

                valid_moves.extend(some_arr)

        print("printing valid moves", valid_moves)
        return np.array(valid_moves)

    def getGameEnded(self, canonical_board: np.ndarray, player: int) -> float:
        # return 0 if not ended, 1 if player 1 won, -1 if player 1 lost
        # player = 1
        if self.saved_world.timeout():
            print("Timeouted")
            return 1e-4


        if len(self.saved_world.players[player].actors) == 0:  # TODO - checking agains saved world and not canonical board -may be different
            return -player
        if len(self.saved_world.players[-player].actors) == 0:
            return player

        return 0

    def getCanonicalForm(self, board, player: int) -> np.ndarray:
        # return state if player==1, else return -state if player==-1

        if type(board) is np.ndarray:  # TODO - done -> object to array
            return player * board

        from games.td2020.src.Actors import MyActor

        numeric_board: list = []
        # convert object board to numpy array
        for y in range(board.height):

            board_row: list = []
            for x in range(board.width):
                board_row_actors: list = []
                for actor_index in range(board.MAX_ACTORS_ON_TILE):  # Todo - a tle vrnem 4d array kjer so notr actionsi ali 3d kjer so notr actorji

                    ## check if its not granite
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
                        for action_str, action_int in board.ALL_ACTIONS.items():
                            if actor.action_manager.can_execute_action(action_str, board):
                                board_row_actors_actions.append(action_int)
                            else:
                                board_row_actors_actions.append(0)
                    else:

                        board_row_actors_actions.append([0] * len(board.ALL_ACTIONS))  # empty actions for empty actors and minerals
                    board_row_actors = np.array(board_row_actors).flatten()
                    # board_row_actors.append(board_row_actors_actions)
                    board_row_actors = np.append(board_row_actors, board_row_actors_actions)

                    # todo - END OTHER OPTION WITH 4D

                board_row.append(board_row_actors)

            numeric_board.append(board_row)

        numeric_board = np.array(numeric_board).tolist()
        print("Printing numeric board of length:", len(numeric_board), "\n", numeric_board)

        return player * np.array(numeric_board)

    def getSymmetries(self, canonical_board: np.ndarray, pi: np.array) -> np.ndarray:
        # mirror, rotational
        # assert (len(pi) == self.n ** 2 + 1)  # 1 for pass # todo -this assert is wrong - it should be 8x8x4x2 - because pi = 512 which is 8*8*4*2

        # pi_board = np.reshape(pi[:-1], (self.n, self.n)) #todo reshape?

        pi_board = np.reshape(pi, (8, 8, 4, 2))  # todo reshape? -- is this correct???????? dunno

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

    def stringRepresentation(self, canonical_board: np.ndarray) -> bytes:
        # 8x8 numpy array (canonical board)
        return np.array(canonical_board).tostring()

    @staticmethod
    def getScore(board, player):
        return board.players[player].calculate_score()


def display(board):
    board.obj_board.display_obj()
    board.num_board.display()
