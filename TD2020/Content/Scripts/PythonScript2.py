from config_file import LEARN_ARGS
from systems.Coach import Coach
from games.td2020.Game import Game
from games.td2020.tensorflow.NNet import NNetWrapper as NNet

g = Game(LEARN_ARGS)
nnet = NNet(g)