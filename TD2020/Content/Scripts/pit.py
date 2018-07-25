from config_file import PATH, PIT_ARGS
from systems import Arena
from systems.MCTS import MCTS
from games.td2020.Game import Game, display
from games.td2020.Players import RandomPlayer, HumanPlayer, GreedyPlayer
from games.td2020.tensorflow.NNet import NNetWrapper as NNet

import numpy as np

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""

g = Game(PIT_ARGS)

# all players
rp = RandomPlayer(g).play
gp = GreedyPlayer(g).play
hp = HumanPlayer(g).play

# systems
n1 = NNet(g)
n1.load_checkpoint(PATH, 'temp.pth.tar')
mcts1 = MCTS(g, n1, PIT_ARGS)


# nnet player
def nnp(x, player): return np.argmax(mcts1.getActionProb(x, player, temp=0))


arena = Arena.Arena(hp, nnp, g, display=display)
print(arena.playGames(2, PIT_ARGS.verbose))
