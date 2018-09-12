import numpy as np

from config_file import GET_ACTION_ARGS, LEARN_ARGS
from games.td2020.Game import Game
from games.td2020.keras.NNet import NNetWrapper as NNet
from games.td2020.src.Board import Board
from systems.mcts import MCTS


# noinspection PyUnusedLocal
def fill_board(board: Board, json_args):
    # todo fill board here from UE4 for both players and assign this AI player as player 1
    return board


def get_action(json_args):
    g = Game(GET_ACTION_ARGS)
    board: Board = g.get_init_board
    board = fill_board(board, json_args)

    # systems
    n1 = NNet(g)
    n1.load_checkpoint(LEARN_ARGS.checkpoint, 'best.pth.tar')
    mcts1 = MCTS(g, n1, GET_ACTION_ARGS)

    # nnet player
    def nnp(x, player): return np.argmax(mcts1.get_action_prob(x, player, temp=0))

    # get best action
    best_action = nnp(board, 1)  # current player as player 1 - it depends on how you create board
    print("get_action.py", "printing best action:", best_action)
    # todo - do something with this best action
