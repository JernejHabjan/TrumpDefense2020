from config_file import LEARN_ARGS
from systems.Coach import Coach
from games.td2020.Game import Game
from games.td2020.keras.NNet import NNetWrapper as NNet

g = Game(LEARN_ARGS)
nnet = NNet(g)

if LEARN_ARGS.load_model:
    nnet.load_checkpoint(LEARN_ARGS.load_folder_file[0], LEARN_ARGS.load_folder_file[1])

c = Coach(g, nnet, LEARN_ARGS)
if LEARN_ARGS.load_model:
    print("Load trainExamples from file")
    c.loadTrainExamples()
c.learn()
