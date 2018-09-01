from __future__ import print_function
import copy
import sys
import numpy as np

from config_file import MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN, ALL_ACTIONS_INT, PLAYER1WIN, PLAYER2WIN
from games.td2020.src.Board import Board
from games.td2020.src.FunctionLibrary import action_into_array

from systems.utils import DotDict

sys.path.append('..')


class Game:
    def __init__(self, args: DotDict):
        self.args = args
        self.width = args.width
        self.height = args.height
        self.fps = args.fps

    def getInitBoard(self) -> Board:
        return Board(self.args)

    def getBoardSize(self) -> tuple:
        return self.width, self.height, MAX_ACTORS_ON_TILE

    def getActionSize(self) -> int:
        return self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN

    @staticmethod
    def getNextState(board: Board, player: int, action: int):

        # create copy of old world and execute actions on new one
        new_world: Board = copy.deepcopy(board)

        player = new_world.players[player]

        action_into_arr_array = action_into_array(new_world, action)
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

        if eval(PLAYER1WIN):
            return 1
        if eval(PLAYER2WIN):
            return -1
        if board.timeout():
            # print("Timeouted")
            return 1e-4

        return 0

    @staticmethod
    def getCanonicalForm(board: Board, player: int) -> np.ndarray:
        from games.td2020.src.Actors import MyActor

        # return state if player==1, else return -state if player==-1
        numeric_board: list = []
        # convert object board to numpy array
        for y in range(board.height):

            board_row: list = []
            for x in range(board.width):
                board_row_actors: list = []
                for actor_index in range(MAX_ACTORS_ON_TILE):
                    if actor_index < len(board[x][y].actors):

                        actor = board[x][y].actors[actor_index]

                        if issubclass(type(board[x][y].actors[actor_index]), MyActor):
                            board_row_actors.append(actor.player * actor.numeric_value * player)
                        else:
                            # this is neutral unit
                            board_row_actors.append(actor.numeric_value)  # Minerals with numeric value 0
                    else:
                        # this is empty field
                        board_row_actors.append(0)
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
