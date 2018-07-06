from systems import Arena
from systems.MCTS import MCTS
from games.td2020.Game import Game, display
from games.td2020.Players import RandomPlayer, HumanPlayer, GreedyPlayer
from games.td2020.keras.NNet import NNetWrapper as NNet

import numpy as np
from systems.utils import *
import os

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""
args = DotDict({
    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': True,
    'fps': 60,
})
g = Game(args)


# all players
rp = RandomPlayer(g).play
gp = GreedyPlayer(g).play
hp = HumanPlayer(g).play
# systems
n1 = NNet(g)
n1.load_checkpoint(os.path.expanduser('~\\TD2020\\saved_models\\'), 'temp.pth.tar')
