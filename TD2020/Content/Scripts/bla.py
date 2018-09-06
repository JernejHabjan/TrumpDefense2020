# Converted to ue4 use from: https://www.tensorflow.org/get_started/mnist/beginners
# mnist_softmax.py: https://github.com/tensorflow/tensorflow/blob/r1.1/tensorflow/examples/tutorials/mnist/mnist_softmax.py

# Import data
from tensorflow.examples.tutorials.mnist import input_data

import tensorflow as tf
import unreal_engine as ue
from TFPluginAPI import TFPluginAPI

import operator

from tensorflow.python.keras.backend import clear_session

from config_file import PATH, GET_ACTION_ARGS
from games.td2020.Game import Game
from games.td2020.src import Board
import numpy as np

from config_file import GET_ACTION_ARGS, LEARN_ARGS
from games.td2020.Game import Game
from games.td2020.keras.NNet import NNetWrapper as NNet
from games.td2020.src.Board import Board
from systems.mcts import MCTS

from pit import PitWrapper
ue.print_string("bla")


print("path is "+ PATH)


class MnistSimple(TFPluginAPI):

    # expected api: storedModel and session, json inputs
    def onJsonInput(self, jsonInput):
        return jsonInput

    # expected api: no params forwarded for training? TBC
    def onBeginTraining(self):
        """ue.log("starting mnist simple training")
        # Simple hello world using TensorFlow

        # Create a Constant op
        # The op is added as a node to the default graph.
        #
        # The value returned by the constructor represents the output
        # of the Constant op.
        hello = tf.constant('Hello, TensorFlow!')

        # Start tf session
        sess = tf.Session()

        # Run the op
        print(sess.run(hello))
        ue.print_string("tensorflow script")
        ue.print_string(sess.run(hello))
        PitWrapper()"""
        clear_session()
        print(" TODOOOOOOOOOOOOOOOOOOOOOOOOOOOO - TEMP FIX COZ CRASHING ASYNC IN GAME")
        print(" ZARAD TEGA DELAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA")
        g = Game(GET_ACTION_ARGS)
        board: Board = g.get_init_board()
        # board = create_board(board)

        # systems
        n1 = NNet(g)
        n1.load_checkpoint(LEARN_ARGS.checkpoint, 'best.pth.tar')
        mcts1 = MCTS(g, n1, GET_ACTION_ARGS)

        # nnet player
        def nnp(x, player): return np.argmax(mcts1.get_action_prob(x, player, temp=0))

        # get best action
        best_action = nnp(board, 1)  # current player as player 1 - it depends on how you create board
        ue.print_string("get_action.py", "printing best action:", best_action)
        # todo - do something with this best action
        return ''
    def run(self,args):
        pass
        """g = Game(GET_ACTION_ARGS)
        board: Board = g.get_init_board()
        # board = create_board(board)

        # systems
        n1 = NNet(g)
        n1.load_checkpoint(LEARN_ARGS.checkpoint, 'best.pth.tar')
        mcts1 = MCTS(g, n1, GET_ACTION_ARGS)

        # nnet player
        def nnp(x, player): return np.argmax(mcts1.get_action_prob(x, player, temp=0))

        # get best action
        best_action = nnp(board, 1)  # current player as player 1 - it depends on how you create board
        ue.print_string("get_action.py", "printing best action:", best_action)
        # todo - do something with this best action
        """
# required function to get our api
def getApi():
    # return CLASSNAME.getInstance()
    return MnistSimple.getInstance()
