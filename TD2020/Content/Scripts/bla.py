# Converted to ue4 use from: https://www.tensorflow.org/get_started/mnist/beginners
# mnist_softmax.py: https://github.com/tensorflow/tensorflow/blob/r1.1/tensorflow/examples/tutorials/mnist/mnist_softmax.py

# Import data

# noinspection PyUnresolvedReferences
import unreal_engine as ue
# noinspection PyUnresolvedReferences
from TFPluginAPI import TFPluginAPI
from tensorflow.python.keras.backend import clear_session

from MCTS import MCTS
from td2020.TD2020Game import TD2020Game
from td2020.keras.NNet import NNetWrapper as NNet
from utils import dotdict
import numpy as np

ue.print_string("bla")


# noinspection PyMethodMayBeStatic,PyPep8Naming,PyUnusedLocal
class MnistSimple(TFPluginAPI):

    # expected api: storedModel and session, json inputs
    def onJsonInput(self, jsonInput):
        ue.print_string("blabla")
        ue.print_string(jsonInput)
        # now parse this input:
        encoded_actors = jsonInput['data']

        ue.print_string(encoded_actors)


        initial_board_config = []
        for encoded_actor in encoded_actors:
            ue.print_string(encoded_actor)
            initial_board_config.append(
                dotdict({
                    'x': encoded_actor['x'],
                    'y': encoded_actor['y'],
                    'player': encoded_actor['player'],
                    'a_type':encoded_actor['actorType'],
                    'health': encoded_actor['health'],
                    'carry': encoded_actor['carry'],
                    'gold': encoded_actor['money'],
                    'timeout': 100
                }),
                # TODO - TODO -THIS TIMEOUT IS HARDCODED
            )
        g = TD2020Game(8)
        g.setInitBoard(initial_board_config)
        b = g.getInitBoard()

        # nnet players
        n1 = NNet(g)
        n1.load_checkpoint('.\\..\\temp\\', 'temp.pth.tar')
        args1 = dotdict({'numMCTSSims': 50, 'cpuct': 1.0})
        mcts1 = MCTS(g, n1, args1)
        n1p = lambda x: np.argmax(mcts1.getActionProb(x, temp=0))

        recommended_act = n1p(g.getCanonicalForm(b))

        # self.jsonInput = encoded_actors

        return recommended_act

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

        # todo - do something with this best action
        return ''

    def run(self, args):
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
