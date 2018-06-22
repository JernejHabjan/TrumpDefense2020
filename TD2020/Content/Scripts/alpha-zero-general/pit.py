from systems import Arena
from systems.MCTS import MCTS
from games.td2020.Game import Game, display
from games.td2020.Players import RandomPlayer, HumanPlayer, GreedyPlayer
from games.td2020.keras.NNet import NNetWrapper as NNet

import numpy as np
from systems.utils import *

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""
args = DotDict({
    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': True,
    'fps': 1,
})
g = Game(args)

# all players
rp = RandomPlayer(g).play
gp = GreedyPlayer(g).play
hp = HumanPlayer(g).play

# systems
n1 = NNet(g)
n1.load_checkpoint('./temp/', 'best.pth.tar')
args1 = DotDict({'numMCTSSims': 50, 'cpuct': 1.0})
mcts1 = MCTS(g, n1, args1)


# nnet player
def nnp(x, player): return np.argmax(mcts1.getActionProb(x, player, temp=0))


# n2 = NNet(g)
# n2.load_checkpoint('/dev/8x50x25/','best.pth.tar')
# args2 = DotDict({'numMCTSSims': 25, 'cpuct':1.0})
# mcts2 = MCTS(g, n2, args2)games.
# n2p = lambda x: np.argmax(mcts2.getActionProb(x, temp=0))

arena = Arena.Arena(hp, nnp, g, display=display)
print(arena.playGames(2, args.verbose))
