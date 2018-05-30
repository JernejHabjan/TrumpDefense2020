from __future__ import print_function

import random
import sys

from numpy import size

from Game import Game
from .src.Game import Game as srcGame
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

    def __init__(self, width=8, height=8):
        super().__init__()

        self.width, self.height = width,height

        self.src_game = srcGame(timeout_ticks=999999999, visuals=False, fps=0, exit_after_end=False)


    def getInitBoard(self):
        """
        Returns:
            startBoard: a representation of the board (ideally this is the form that will be the input to your neural network)
        """

        world: Grid = Grid(self.width, self.height)

        # init
        # world objects are bound only to world grid, but player objects have tile location stored in player
        from td2020.src.Actors import Granite
        # spawn granite
        granite = Granite(int(self.width / 2), int(self.height / 2))
        world[int(self.width / 2)][int(self.height / 2)].actors.append(granite)
        # spawn players in world with their initial pieces
        world.spawn_players()

        return world

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
        player: Player = None  # TODO - THIS MUST BE CURRENT PLAYER
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

        self.src_game.world = self.src_game.getNextState(board,player,action) # todo - do i really assign new world to it?






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


def display(board):
    # todo - make prefix of which team the piece is on board. If pieces of both teams are on same tile, make special suffix
    display_str = ["".join(["-----"] * board.width)]

    for i in range(board.width):

        for j in range(board.height):

            tile = board[i][j]
            if size(tile.actors) > 1:
                display_str.append(".**.")
            elif size(tile.actors) == 1:
                display_str.append(tile.actors[0].short_name)
            else:
                display_str.append("    ")
            display_str.append("|")

        # print("".join(row_str))
        display_str.append("\n")
        if i < board.height:
            #    print( "".join(["-----"]*board.width))

            display_str.append("".join(["-----"] * board.width) + "\n")
    print("".join(display_str))
