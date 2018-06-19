import os
import sys

from tensorflow.python.keras.callbacks import TensorBoard
import numpy as np
from keras.utils import plot_model

from NeuralNet import NeuralNet
from utils import *
from .OthelloNNet import OthelloNNet as ONNet

sys.path.append('..')
args = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 10,
    'batch_size': 64,
    'cuda': False,
    'num_channels': 512,
})


class NNetWrapper(NeuralNet):
    def __init__(self, game):
        super().__init__(game)
        self.nnet = ONNet(game, args)
        self.board_x, self.board_y = game.getBoardSize()
        self.action_size = game.getActionSize()

        self.tensorboard = TensorBoard(log_dir='_Files\\models\\logs' + type(self.nnet).__name__, histogram_freq=0,
                                       write_graph=True, write_images=True)
        # plot_model(self.nnet.model, to_file='_Files\\models\\' + type(self.nnet).__name__ + '_model_plot.png', show_shapes=True, show_layer_names=True)

    def train(self, examples):
        """
        examples: list of examples, each example is of form (board, pi, v)
        """
        input_boards, target_pis, target_vs = list(zip(*examples))
        input_boards = np.asarray(input_boards)
        target_pis = np.asarray(target_pis)
        target_vs = np.asarray(target_vs)


        print("printing input_boards shape", np.array(input_boards).shape)
        print("printing target_pis shape", np.array(target_pis).shape)
        print("printing target_vs shape", np.array(target_vs).shape)


        self.nnet.model.fit(x=input_boards, y=[target_pis, target_vs], batch_size=args.batch_size, epochs=args.epochs,
                            callbacks=[self.tensorboard])

    def predict(self, board):
        """
        board: np array with board
        """
        # timing
        # start = time.time()

        # preparing input
        board = board[np.newaxis, :, :]

        # board now looks like this:

        """
        [[[ 0  0 -1 -1 -1  0]
          [-1  0  0 -1  1  0]
          [-1 -1  1  1  1  0]
          [ 0 -1 -1  1  1  1]
          [ 1  0 -1 -1 -1  0]
          [ 0  0  0  0  0  0]]]
        """
        print("printing board size ", np.size(board))


        # run
        pi, v = self.nnet.model.predict(board)

        """
        (p, v) =  fθ(s). The vector of move probabilities p represents the probability of selecting each move 
        a (including pass), pa =  Pr(a| s). The value v is a scalar evaluation, 
        estimating the probability of the current player winning from position s. 
        This neural network combines the roles of both policy network and value network into a single architecture.
      
        """

        # pi
        """
        [[0.02746242 0.02707437 0.02764788 0.02681001 0.02677481 0.02675962
          0.0273278  0.02735244 0.02695592 0.02734742 0.02751813 0.02691889
          0.02725385 0.02682924 0.0266784  0.0269696  0.02661146 0.02708981
          0.02687783 0.02713573 0.02734824 0.02724144 0.02627023 0.02678316
          0.02695782 0.02669897 0.02704076 0.02702231 0.02679938 0.02750883
          0.0265832  0.02694086 0.02727489 0.02701169 0.02712642 0.02693347
          0.02706279]]
        """
        # v
        """
        [[0.00579279]]
        """

        # print('PREDICTION TIME TAKEN : {0:03f}'.format(time.time()-start))
        return pi[0], v[0]

    def save_checkpoint(self, folder='checkpoint', filename='checkpoint.pth.tar'):
        filepath = os.path.join(folder, filename)
        if not os.path.exists(folder):
            print("Checkpoint Directory does not exist! Making directory {}".format(folder))
            os.mkdir(folder)
        else:
            print("Checkpoint Directory exists! ")
        self.nnet.model.save_weights(filepath)

    def load_checkpoint(self, folder='checkpoint', filename='checkpoint.pth.tar'):
        # https://github.com/pytorch/examples/blob/master/imagenet/main.py#L98
        filepath = os.path.join(folder, filename)
        if not os.path.exists(filepath):
            raise ValueError("No model in path {}".format(filepath))
        self.nnet.model.load_weights(filepath)
