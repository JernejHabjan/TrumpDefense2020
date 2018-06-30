import numpy as np
from games.td2020.Game import Game
from systems.MCTS import MCTS
from games.td2020.keras.NNet import NNetWrapper as NNet
from systems.utils import DotDict


def create_board(board):
    # todo fill board here from UE4 for both players and assign this AI player as player 1
    return 1


args = DotDict({
    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': True,
    'fps': 1,
})
g = Game(args)
board = g.getInitBoard()
# board = create_board(board)

# systems
n1 = NNet(g)
n1.load_checkpoint('./temp/', 'temp.pth.tar')
args1 = DotDict({'numMCTSSims': 50, 'cpuct': 1.0})
mcts1 = MCTS(g, n1, args1)


# nnet player
def nnp(x, player): return np.argmax(mcts1.getActionProb(x, player, temp=0))


# get best action
best_action = nnp(board, 1)  # current player as player 1 - it depends on how you create board
print("get_action.py", "printing best action:", best_action)
# todo - do something with this best action
