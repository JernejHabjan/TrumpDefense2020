from __future__ import print_function

import random
import sys

from numpy import size

from Game import Game
from td2020.src.ActionManager import ActionManager
from td2020.src.Grid import Grid
from td2020.src.Player import Player

sys.path.append('..')

# noinspection PyTypeChecker
NUM_ALL_ACTIONS = size(ActionManager(None, None).actions)
class TD2020Game(Game):
    """
        This class specifies the base Game class. To define your own game, subclass
        this class and implement the functions below. This works when the game is
        two-player, adversarial and turn-based.

        Use 1 for player1 and -1 for player2.

        See othello/OthelloGame.py for an example implementation.
        """

    def __init__(self):
        super().__init__()
        self._base_board = Grid(num=64)

    def getInitBoard(self):
        """
        Returns:
            startBoard: a representation of the board (ideally this is the form that will be the input to your neural network)
        """

        return self._base_board.tiles

    def getBoardSize(self):
        """
        Returns:
            (x,y): a tuple of board dimensions
        """
        return 8, 8

    def getActionSize(self) -> int:
        """
        Returns:
            actionSize: number of all possible actions
        """
        player:Player = None # TODO - THIS MUST BE CURRENT PLAYER
        return size(player.actors) * NUM_ALL_ACTIONS




    def getNextState(self, board, player, action):
        """
        Input:
            board: current board
            player: current player (1 or -1)
            action: action taken by current player

        Returns:
            nextBoard: board after applying action
            nextPlayer: player who plays in the next turn (should be -player)
        """



    def getValidMoves(self, board, player):
        """
        Input:
            board: current board
            player: current player

        Returns:
            validMoves: a binary vector of length self.getActionSize(), 1 for
                        moves that are valid from the current board and player,
                        0 for invalid moves
        """
        pass

    def getGameEnded(self, board, player):
        """
        Input:
            board: current board
            player: current player (1 or -1)

        Returns:
            r: 0 if game has not ended. 1 if player won, -1 if player lost,
               small non-zero value for draw.

        """
        pass

    def getCanonicalForm(self, board, player):
        """
        Input:
            board: current board
            player: current player (1 or -1)

        Returns:
            canonicalBoard: returns canonical form of board. The canonical form
                            should be independent of player. For e.g. in chess,
                            the canonical form can be chosen to be from the pov
                            of white. When the player is white, we can return
                            board as is. When the player is black, we can invert
                            the colors and return the board.
        """
        pass

    def getSymmetries(self, board, pi):
        """
        Input:
            board: current board
            pi: policy vector of size self.getActionSize()

        Returns:
            symmForms: a list of [(board,pi)] where each tuple is a symmetrical
                       form of the board and the corresponding pi vector. This
                       is used when training the neural network from examples.
        """
        pass

    def stringRepresentation(self, board):
        """
        Input:
            board: current board

        Returns:
            boardString: a quick conversion of board to a string format.
                         Required by MCTS for hashing.
        """
        pass
