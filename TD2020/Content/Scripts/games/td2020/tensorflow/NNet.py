import os
import sys
import time
from typing import Tuple

import numpy as np
import tensorflow as tf

from config_file import NNET_ARGS
from games.td2020 import Game
from systems.nnet import NNetWrapperParent
from systems.misc.misc import AverageMeter
from systems.misc.progress.bar import Bar
from systems.types import CanonicalBoard, Pi, V
from .TD2020NNet import TD2020NNet as ONNet

sys.path.append('../../')


class NNetWrapper(NNetWrapperParent):
    def __init__(self, game: 'Game.Game') -> None:

        super().__init__(game)
        self.nnet: ONNet = ONNet(game, NNET_ARGS)
        self.board_x, self.board_y, self.max_actors_on_tile = game.get_board_size
        self.action_size: int = game.get_action_size

        self.sess = tf.Session(graph=self.nnet.graph)
        self.saver = None
        with tf.Session() as temp_sess:
            temp_sess.run(tf.global_variables_initializer())
        self.sess.run(tf.variables_initializer(self.nnet.graph.get_collection('variables')))

    def nnet_train(self, examples) -> None:
        """
        examples: list of examples, each example is of form (board, pi, v)
        """

        for epoch in range(NNET_ARGS.epochs):
            print('EPOCH ::: ' + str(epoch + 1))
            data_time = AverageMeter()
            batch_time = AverageMeter()
            pi_losses = AverageMeter()
            v_losses = AverageMeter()
            end = time.time()

            bar = Bar('Training Net', max=int(len(examples) / NNET_ARGS.batch_size))
            batch_idx = 0

            # self.sess.run(tf.local_variables_initializer())
            while batch_idx < int(len(examples) / NNET_ARGS.batch_size):
                sample_ids = np.random.randint(len(examples), size=NNET_ARGS.batch_size)
                boards, pis, vs = list(zip(*[examples[i] for i in sample_ids]))

                # nnet_predict and compute gradient and do SGD step
                input_dict = {self.nnet.input_boards: boards, self.nnet.target_pis: pis, self.nnet.target_vs: vs, self.nnet.dropout: NNET_ARGS.dropout, self.nnet.isTraining: True}

                # measure data loading time
                data_time.update(time.time() - end)

                # record loss
                self.sess.run(self.nnet.train_step, feed_dict=input_dict)
                pi_loss, v_loss = self.sess.run([self.nnet.loss_pi, self.nnet.loss_v], feed_dict=input_dict)
                pi_losses.update(pi_loss, len(boards))
                v_losses.update(v_loss, len(boards))

                # measure elapsed time
                batch_time.update(time.time() - end)
                end = time.time()
                batch_idx += 1

                # plot progress
                bar.suffix = '({batch}/{size}) Data: {data:.3f}s | Batch: {bt:.3f}s | Total: {total:} | ETA: {eta:} | Loss_pi: {lpi:.4f} | Loss_v: {lv:.3f}'.format(
                    batch=batch_idx,
                    size=int(len(examples) / NNET_ARGS.batch_size),
                    data=data_time.avg,
                    bt=batch_time.avg,
                    total=bar.elapsed_td,
                    eta=bar.eta_td,
                    lpi=pi_losses.avg,
                    lv=v_losses.avg,
                )
                bar.next()
            bar.finish()

    def nnet_predict(self, canonical_board: CanonicalBoard) -> Tuple[Pi, V]:
        """
        :param canonical_board: canonical board
        :return: 
        USED:
            MCTS - search - creates Ps[state], v from current canonical form
        """

        # timing
        # start = time.time()

        # preparing input
        canonical_board = canonical_board[np.newaxis, :, :]

        # run
        prob, v = self.sess.run([self.nnet.prob, self.nnet.v], feed_dict={self.nnet.input_boards: canonical_board, self.nnet.dropout: 0, self.nnet.isTraining: False})

        # print('PREDICTION TIME TAKEN : {0:03f}'.format(time.time()-start))
        return prob[0], v[0]


    def save_checkpoint(self, folder, filename) -> None:
        filepath = os.path.join(folder, filename)
        if not os.path.exists(folder):
            print("Checkpoint Directory does not exist! Making directory {}".format(folder))
            os.mkdir(folder)
        else:
            print("Checkpoint Directory exists! ")
        if self.saver is None:
            self.saver = tf.train.Saver(self.nnet.graph.get_collection('variables'))
        with self.nnet.graph.as_default():
            self.saver.save(self.sess, filepath)

    def load_checkpoint(self, folder, filename) -> None:
        filepath = os.path.join(folder, filename)
        if not os.path.exists(filepath + '.meta'):
            raise Exception("No model in path {}".format(filepath))
        with self.nnet.graph.as_default():
            self.saver = tf.train.Saver()
            self.saver.restore(self.sess, filepath)
