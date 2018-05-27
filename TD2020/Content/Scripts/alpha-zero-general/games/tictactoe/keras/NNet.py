import os
import sys
# import time
import keras
import numpy as np
from keras.callbacks import TensorBoard
from keras.utils import plot_model

from utils import *
from NeuralNet import NeuralNet
from .TicTacToeNNet import TicTacToeNNet as ONNet

sys.path.append('..')

"""
NeuralNet wrapper class for the TicTacToeNNet.

Author: Evgeny Tyurin, github.com/evg-tyurin
Date: Jan 5, 2018.

Based on (copy-pasted from) the NNet by SourKream and Surag Nair.
"""

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

        self.tensorboard = TensorBoard(log_dir='_Files\\models\\logs' + type(self.nnet).__name__, histogram_freq=0, write_graph=True, write_images=True)
        # plot_model(self.nnet.model, to_file='_Files\\models\\' + type(self.nnet).__name__ + '_model_plot.png', show_shapes=True, show_layer_names=True)

    def train(self, examples):
        """
        examples: list of examples, each example is of form (board, pi, v)
        """
        input_boards, target_pis, target_vs = list(zip(*examples))
        input_boards = np.asarray(input_boards)
        target_pis = np.asarray(target_pis)
        target_vs = np.asarray(target_vs)
        self.nnet.model.fit(x=input_boards, y=[target_pis, target_vs], batch_size=args.batch_size, epochs=args.epochs, callbacks=[self.tensorboard])

    def predict(self, board):
        """
        board: np array with board
        """
        # timing
        # start = time.time()

        # preparing input
        board = board[np.newaxis, :, :]

        # run
        pi, v = self.nnet.model.predict(board)

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
            raise Exception("No model in path '{}'".format(filepath))
        self.nnet.model.load_weights(filepath)
