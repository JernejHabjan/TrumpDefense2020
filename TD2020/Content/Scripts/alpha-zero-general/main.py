from Coach import Coach
from games.othello.OthelloGame import OthelloGame as Game
from games.othello.keras.NNet import NNetWrapper as NNet

from games.td2020.OthelloGame import OthelloGame as Game
from games.td2020.keras.NNet import NNetWrapper as NNet

from utils import *

# install packages:
# conda install tensorflow
# conda install keras
# conda install -c anaconda graphviz
# conda install pydot


args = DotDict({
    'numIters': 100,
    'numEps': 100,
    'tempThreshold': 15,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 25,
    'arenaCompare': 30,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('/dev/models/8x100x50', 'best.pth.tar'),
    'numItersForTrainExamplesHistory': 20,
})

args = DotDict({
    'numIters':1,
    'numEps': 1,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 2,
    'arenaCompare': 1,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('./pretrained_models/othello/keras/', '6x6 checkpoint_145.pth.tar'),
    'numItersForTrainExamplesHistory': 20,
})

if __name__ == "__main__":

    g = Game(8)
    nnet = NNet(g)

    if args.load_model:
        nnet.load_checkpoint(args.load_folder_file[0], args.load_folder_file[1])

    c = Coach(g, nnet, args)
    if args.load_model:
        print("Load trainExamples from file")
        c.loadTrainExamples()
    c.learn()
