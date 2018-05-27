import Arena
from MCTS import MCTS
from games.tictactoe.TicTacToeGame import TicTacToeGame, display
from games.tictactoe.TicTacToePlayers import RandomPlayer, HumanTicTacToePlayer  # ,GreedyTicTacToePlay
from games.tictactoe.keras.NNet import NNetWrapper as NNet

import numpy as np
from utils import *

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""

g = TicTacToeGame(6)

# all players
rp = RandomPlayer(g).play
# gp = GreedyOthelloPlayer(g).play
hp = HumanTicTacToePlayer(g).play

# nnet players
n1 = NNet(g)
n1.load_checkpoint('./pretrained_models/tictactoe/keras/', 'best-25eps-25sim-10epch.pth.tar')
args1 = DotDict({'numMCTSSims': 50, 'cpuct': 1.0})
mcts1 = MCTS(g, n1, args1)


# nnet player
def n1p(x): return np.argmax(mcts1.getActionProb(x, temp=0))


# n2 = NNet(g)
# n2.load_checkpoint('/dev/8x50x25/','best.pth.tar')
# args2 = DotDict({'numMCTSSims': 25, 'cpuct':1.0})
# mcts2 = MCTS(g, n2, args2)games.
# n2p = lambda x: np.argmax(mcts2.getActionProb(x, temp=0))

arena = Arena.Arena(n1p, hp, g, display=display)
print(arena.playGames(2, verbose=True))
