import copy
from typing import List, Tuple

import numpy as np

from config_file import MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN, PLAYER1WIN, PLAYER2WIN, TIMEOUT_TICKS
from games.td2020.src.Board import Board
from games.td2020.src.FunctionLibrary import action_into_array
from systems.types import ValidMoves, CanonicalBoard, StrPresentation, StateEncoding, Pi, ActionEncoding


class Game:
    def __init__(self, args) -> None:
        self.args = args
        self.width = args.width
        self.height = args.height
        self.fps = args.fps

    @property
    def get_init_board(self) -> Board:
        """
        :return: game board of class Board
        USED: Arena - init world
              Learn - init world
              Get Action - init world
        """
        return Board(self.args)

    @property
    def get_board_size(self) -> Tuple[int, int, int]:
        """
        :return: width, height, max_actors_on_tile
        USED:
            keras
                TD2020NNet- init - get board dimensions to build model
            tensorflow
                TD2020NNet - init - get board dimensions to build model
                NNet -> to create tensorflow session

        """
        return self.width, self.height, MAX_ACTORS_ON_TILE

    @property
    def get_action_size(self) -> int:
        """
        :return:  width * height * max_actors_on_tile * all_actions
        """
        # return self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN
        return self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN + 1  # IN ORG CODE HE ADDED + 1

    @staticmethod
    def get_next_state(board: Board, player: int, action: int) -> Tuple[Board, int]:
        """
        create copy of old world and execute actions on new one
        :param board:
        :param player:
        :param action:
        :return:
        """
        new_world: Board = copy.deepcopy(board)

        player = new_world.players[player]

        x, y, actor_index, action_int, action_str = action_into_array(new_world, action)
        # print("------------- ACTION ----------------------------", x, y, actor_index, action_str)

        actor = new_world[x][y].actors[actor_index]
        actor.update(new_world, action_str)

        # updating timeout game iteration here
        new_world.iteration += 1

        return new_world, -player.name

    @staticmethod
    def get_valid_moves(board: Board, player: int) -> ValidMoves:
        """
        :param board:
        :param player:
        :return: fixed size binary vector
        # USED - MCTS - to mask all invalid moves
        """
        from games.td2020.src.Actors import MyActor
        valid_moves: List[int] = []
        for y in range(board.height):
            for x in range(board.width):
                some_arr: List[int] = []
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
        valid_moves.append(0)  # TODO - added so because getNumActions returns +1 because he added it so "get_symmetries" can be returning + [pi[-1]]
        return np.array(valid_moves)

    @staticmethod
    def get_game_ended(board: Board, player) -> float:
        """
        :param board:
        :return: return 0 if not ended, 1 if player 1 won, -1 if player 1 lost, 1e-4 if timeout
        """

        if len(board.players[player].actors) >= 10:
            return 1
        if len(board.players[-player].actors) >= 10:
            return -1

        #if eval(PLAYER1WIN):
        #    return 1
        #if eval(PLAYER2WIN):
        #    return -1
        if board.iteration > TIMEOUT_TICKS:
            # print("Timeouted")
            # TODO - NEW CODE - RETURN value for their benefit
            if len(board.players[player].actors) > len(board.players[-player].actors):
                return 0.0001
            else:
                return -0.0001
        #    # return -0.00000001
        return 0

    @staticmethod
    def get_canonical_form(board: Board, player: int) -> CanonicalBoard:
        from games.td2020.src.Actors import MyActor

        # return state if player==1, else return -state if player==-1
        numeric_board: List[List[List[int]]] = []
        # convert object board to numpy array
        for y in range(board.height):

            board_row: List[List[int]] = []
            for x in range(board.width):
                board_row_actors: List[int] = []
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
    def get_symmetries(canonical_board: CanonicalBoard, pi: Pi) -> List[Tuple[StateEncoding, Pi]]:
        """
        :param canonical_board: current board in numeric presentation
        :param pi: Pi - List[float] aka action probabilities
        :return: 8 boards that are mirrored and rotated by 90 degrees
         rot90 + fip,
         rot90,
         rot180 + flip
         rot180,
         rot270 + flip
         rot270,
         rot360 + flip
         rot360
        USED 1 PLACE - Coach - Execute episode - to get nnet_train examples
        """

        # TODO - CHECK if symmetries can be added in some other way and if they are correctly applied !!! because of 4 DIM ARRAY!!


        # mirror, rotational
        # new_pi of shape (width, height, num_actors_per_tile, num_all_actions)
        pi_board: ActionEncoding = np.reshape(pi[:-1], (canonical_board.shape[0], canonical_board.shape[1], MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN))

        l: List[Tuple[StateEncoding, Pi]] = []

        for i in range(1, 5):
            for j in [True, False]:
                # new_b of shape (width, height, num_actors_per_tile)
                new_b: StateEncoding = np.rot90(canonical_board, i)  # rotate i-times
                # new_pi of shape (width, height, num_actors_per_tile, num_all_actions)

                new_pi: ActionEncoding = np.rot90(pi_board, i)
                if j:
                    new_b: StateEncoding = np.fliplr(new_b)  # mirror that rotated board

                    new_pi: ActionEncoding = np.fliplr(new_pi)
                # l += [(new_b, list(np.array(new_pi).ravel()))]  # TODO - this is new -LINE BELOW WAS RETURNING 385 instead of 384 - FIGURE IT OUT WHAT THAT +pi[-1] was
                l += [(new_b, list(new_pi.ravel()) + [pi[-1]])]  # ravel is a contiguous flattened array
        return l

    @staticmethod
    def string_representation(canonical_board: CanonicalBoard) -> StrPresentation:
        """
        :param canonical_board: 8x8 numpy array (canonical board)
        :return: 8x8 numpy array (canonical board) string
        USED: Coach - get action probability (get counts of each action in given state - which is now string)
              MCTS - _search (to get state in string representation)
        """
        return canonical_board.tostring()

    @staticmethod
    def get_score(board: Board, player: int) -> float:
        """
        :param board: current board
        :param player: current player
        :return: calculated score
        USED - by greedy player to get best score
        """
        return board.players[player].calculate_score()
