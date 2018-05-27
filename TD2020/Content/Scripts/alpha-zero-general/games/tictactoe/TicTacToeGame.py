from __future__ import print_function
import sys
from Game import Game
from .TicTacToeLogic import Board
import numpy as np

sys.path.append('..')
"""
Game class implementation for the game of TicTacToe.
Based on the OthelloGame then getGameEnded() was adapted to new rules.

Author: Evgeny Tyurin, github.com/evg-tyurin
Date: Jan 5, 2018.

Based on the OthelloGame by Surag Nair.
"""


class TicTacToeGame(Game):
    def __init__(self, n=3):
        super().__init__()
        self.n = n

    def getInitBoard(self):
        # return initial board (numpy board)
        return Board(self.n)

    def getBoardSize(self) -> tuple:
        # (a,b) tuple
        return self.n, self.n

    def getActionSize(self) -> int:
        # return number of actions
        return self.n * self.n + 1

    def getNextState(self, board, player: int, action: int):
        if type(board) is not np.ndarray:  # TODO - IS THIS OK ??????
            board = board.num_board.pieces

        # if player takes action on board, return next (board,player)
        # action must be a valid move
        if action == self.n * self.n:
            return board, -player
        b = Board(self.n)
        b.num_board.pieces = np.copy(board)
        move = (int(action / self.n), action % self.n)
        b.execute_move(move, player)

        return b, -player

    def getValidMoves(self, board, player: int) -> np.array:
        # return a fixed size binary vector
        valids = [0] * self.getActionSize()
        b = Board(self.n)
        b.num_board.pieces = np.copy(board)
        legalMoves = b.get_legal_moves(player)
        if len(legalMoves) == 0:
            valids[-1] = 1
            return np.array(valids)
        for x, y in legalMoves:
            valids[self.n * x + y] = 1
        return np.array(valids)

    def getGameEnded(self, board, player: int) -> float:

        if type(board) is not np.ndarray:  # TODO - IS THIS OK ??????
            board = board.num_board.pieces

        # return 0 if not ended, 1 if player 1 won, -1 if player 1 lost
        # player = 1
        b = Board(self.n)
        b.num_board.pieces = np.copy(board)

        if b.is_win(player):
            return 1
        if b.is_win(-player):
            return -1
        if b.has_legal_moves():
            return 0
        # draw has a very little value 
        return 1e-4

    def getCanonicalForm(self, board, player: int) -> np.ndarray:
        # return state if player==1, else return -state if player==-1

        if type(board) is np.ndarray:  # TODO - IS THIS OK ??????
            return player * board

        return player * np.array(board.num_board.pieces)

    def getSymmetries(self, canonical_board: np.ndarray, pi: np.array) -> np.ndarray:
        # mirror, rotational
        assert (len(pi) == self.n ** 2 + 1)  # 1 for pass
        pi_board = np.reshape(pi[:-1], (self.n, self.n))
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


def display(board):
    n = board.num_board.shape[0]

    print("   ", end="")
    for y in range(n):
        print(y, "", end="")
    print("")
    print("  ", end="")
    for _ in range(n):
        print("-", end="-")
    print("--")
    for y in range(n):
        print(y, "|", end="")  # print the row #
        for x in range(n):
            piece = board.num_board[y][x]  # get the piece to print
            if piece == -1:
                print("X ", end="")
            elif piece == 1:
                print("O ", end="")
            else:
                if x == n:
                    print("-", end="")
                else:
                    print("- ", end="")
        print("|")

    print("  ", end="")
    for _ in range(n):
        print("-", end="-")
    print("--")
