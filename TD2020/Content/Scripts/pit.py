import multiprocessing
import os

import numpy as np
import tensorflow as tf

from config_file import PIT_ARGS
from games.td2020.Game import Game
from games.td2020.Players import RandomPlayer, HumanPlayer, GreedyPlayer
from games.td2020.keras.NNet import NNetWrapper as NNet
from systems.arena import Arena
from systems.mcts import MCTS
from systems.misc.progress.bar import Bar

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""


# TODO - https://github.com/gigayaya/alpha-zero-general/blob/master/pit.py
# TODO - issue https://github.com/suragnair/alpha-zero-general/pull/82

# noinspection PyUnusedLocal
class PitWrapper:
    def __init__(self) -> None:

        self.game = Game(PIT_ARGS)

        if PIT_ARGS.parallel:
            self.ParallelPlay(self.game)
        else:
            self.SingleProcessPlay(self.game)

    @staticmethod
    def SingleProcessPlay(game):
        # all players
        rp = RandomPlayer(game).play
        gp = GreedyPlayer(game).play
        hp = HumanPlayer(game).play

        # system 1
        n1 = NNet(game)
        n1.load_checkpoint(PIT_ARGS.model1Folder, PIT_ARGS.model1FileName)
        mcts1 = MCTS(game, n1, PIT_ARGS)

        # nnet player 1
        def nnp1(x, player): return np.argmax(mcts1.get_action_prob(x, player, temp=0))

        # system 2
        n2 = NNet(game)
        n2.load_checkpoint(PIT_ARGS.model2Folder, PIT_ARGS.model2FileName)
        mcts1 = MCTS(game, n1, PIT_ARGS)

        # nnet player 2
        def nnp2(x, player): return np.argmax(mcts1.get_action_prob(x, player, temp=0))

        # compare 2 models against each other
        # arena = Arena(nnp1, nnp2, game)

        # play against learnt model
        arena = Arena(hp, nnp1, game)
        print(arena.play_games(2, PIT_ARGS.verbose))

    @staticmethod
    def ParallelPlay(g):
        """
            Before using multiprocessing to reduce total time.
            Please check 2 things before use this script.
            1. The number of PlayPool should not over your CPU's core number.
            2. Make sure all Neural Network which each process created can store in VRAM at same time. Check your NN size before use this.
            """

        bar = Bar('Play', max=PIT_ARGS.numPlayGames)
        pool = multiprocessing.Pool(processes=PIT_ARGS.numPlayPool)
        res = []
        result = []
        for i in range(PIT_ARGS.numPlayGames):
            res.append(pool.apply_async(Async_Play, args=(g, PIT_ARGS, i, bar)))
        pool.close()
        pool.join()

        one_won = 0
        two_won = 0
        draws = 0
        for i in res:
            # noinspection PyProtectedMember
            # if i._success:
            #     result.append(i.get())
            # else:
            #    print("multi pit not working - check # https://github.com/gigayaya/alpha-zero-general/blob/master/pit.py repo")
            result.append(i.get())

        for i in result:
            one_won += i[0]
            two_won += i[1]
            draws += i[2]
        print("Model 1 Win:", one_won, " Model 2 Win:", two_won, " Draw:", draws)


# noinspection PyUnusedLocal
def Async_Play(game, args, iter_num, bar):
    bar.suffix = "iter:{i}/{x} | Total: {total:} | ETA: {eta:}".format(i=iter_num + 1, x=args.numPlayGames, total=bar.elapsed_td, eta=bar.eta_td)
    bar.next()

    # set gpu
    if args.multiGPU:
        if iter_num % 2 == 0:
            os.environ["CUDA_VISIBLE_DEVICES"] = "0"
        else:
            os.environ["CUDA_VISIBLE_DEVICES"] = "1"
    else:
        os.environ["CUDA_VISIBLE_DEVICES"] = args.setGPU

    # set gpu growth
    config = tf.ConfigProto()
    config.gpu_options.allow_growth = True
    sess = tf.Session(config=config)

    # create NN
    model1 = NNet(game)
    model2 = NNet(game)

    # try load weight
    try:
        model1.load_checkpoint(folder=args.model1Folder, filename=args.model1FileName)
    except Exception as e:
        print("load model1 fail", e)
        pass
    try:
        model2.load_checkpoint(folder=args.model2Folder, filename=args.model2FileName)
    except Exception as e:
        print("load model2 fail", e)
        pass

    # create MCTS
    mcts1 = MCTS(game, model1, args)
    mcts2 = MCTS(game, model2, args)

    # each process play 2 games
    def player1(x, player):
        return np.argmax(mcts1.get_action_prob(x, player, temp=0))

    def player2(x, player):
        return np.argmax(mcts2.get_action_prob(x, player, temp=0))

    arena = Arena(player1, player2, game)
    arena.displayBar = False
    one_won, two_won, draws = arena.play_games(2)
    return one_won, two_won, draws


if __name__ == '__main__':
    PitWrapper()
