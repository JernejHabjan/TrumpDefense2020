import os
import sys
import time
from collections import deque
from pickle import Pickler, Unpickler
from random import shuffle

import numpy as np

from games.td2020.Game import display
from config_file import ALL_ACTIONS_INT
from systems.Arena import Arena
from systems.MCTS import MCTS
from systems.pytorch_classification.utils.misc import AverageMeter
from systems.pytorch_classification.utils.progress.progress.bar import Bar


class Coach:
    """
    This class executes the self-play + learning. It uses the functions defined
    in Game and NeuralNet. args are specified in learn.py.
    """

    def __init__(self, game, nnet, args):
        self.game = game
        self.nnet = nnet
        self.pnet = self.nnet.__class__(self.game)  # the competitor network
        self.args = args
        self.mcts = MCTS(self.game, self.nnet, self.args)
        self.trainExamplesHistory = []  # history of examples from args.numItersForTrainExamplesHistory latest iterations
        self.skipFirstSelfPlay = False  # can be overridden in loadTrainExamples()

    def __executeEpisode(self):
        """
        This function executes one episode of self-play, starting with player 1.
        As the game is played, each turn is added as a training example to
        train_examples. The game is played till the game ends. After the game
        ends, the outcome of the game is used to assign values to each example
        in train_examples.

        It uses a temp=1 if episode_step < tempThreshold, and thereafter
        uses temp=0.

        Returns:
            train_examples: a list of examples of the form (canonical_board,pi,v)
                           pi is the MCTS informed policy vector, v is +1 if
                           the player eventually won the game, else -1.
        """
        # print("\nCoach - executing one episode of self play")

        # private method

        # init train_examples array
        train_examples = []
        # init board
        board = self.game.getInitBoard()
        # set current player
        self.curPlayer = 1
        # set episodes counter
        episode_step = 0

        while True:
            # print("this is one iteration here in coach")
            episode_step += 1

            # sets temp var that is passed into MCTS getActionProb
            temp = int(episode_step < self.args.tempThreshold)
            # returns probability from getActionProb
            pi = self.mcts.getActionProb(board, self.curPlayer, temp=temp)
            # return symmetries - todo ? what are symmetries here
            canonical_board = self.game.getCanonicalForm(board, self.curPlayer)
            sym = self.game.getSymmetries(canonical_board, pi)
            # iterating through symmetries with tuple board,pi
            for b, p in sym:
                # appends board, player, pi, None
                train_examples.append([b, self.curPlayer, p, None])

            # random action probability
            # parameter p : how uniform this sample is -> https://goo.gl/3D6yrj

            # print("COACH.py printing pi", pi,"printing len pi",len(pi))
            action = np.random.choice(len(pi), p=pi)




            # apply action

            action_arr = self.game.actionIntoArr(board, action)
            if self.args.verbose > 0:
                pass
                # print("----------")
                # for i in range(len(self.game.getValidMoves(board, self.curPlayer))):
                #     if self.game.getValidMoves(board, self.curPlayer)[i]:
                #         action_into_arr_array = self.game.actionIntoArr(board, i)
                #         x = action_into_arr_array[0]
                #         y = action_into_arr_array[1]
                #         actor_index = action_into_arr_array[2]
                #         action_str = ALL_ACTIONS_INT[action_into_arr_array[3]]
                #         print(x, y, actor_index, action_str)
                # print("----------")
                print("Coach.py ", "player ", self.curPlayer, "getting new state with action", action_arr[0], action_arr[1], action_arr[2], ALL_ACTIONS_INT[action_arr[3]])
            board, self.curPlayer = self.game.getNextState(board, self.curPlayer, action)

            # get winning player in variable "r"
            r = self.game.getGameEnded(board)

            # if game has ended
            if r != 0:
                # x[0] -> board
                # x[1] -> player
                # x[2] -> pi
                if self.args.verbose == 3 or self.args.verbose == 5:
                    print("coach - episode ended with result:", r)
                    display(board)
                return [(x[0], x[2], r * ((-1) ** (x[1] != self.curPlayer))) for x in train_examples]

    def learn(self):
        """
        Performs numIters iterations with numEps episodes of self-play in each
        iteration. After every iteration, it retrains neural network with
        examples in train_examples (which has a maximium length of maxlenofQueue).
        It then pits the new neural network against the old one and accepts it
        only if it wins >= updateThreshold fraction of games.
        """

        for i in range(1, self.args.numIters + 1):
            # bookkeeping - not important
            print('------ITER ' + str(i) + '------')
            # examples of the iteration
            if not self.skipFirstSelfPlay or i > 1:
                iteration_train_examples = deque([], maxlen=self.args.maxlenOfQueue)

                eps_time = AverageMeter()
                bar = Bar('Self Play', max=self.args.numEps)
                end = time.time()

                for eps in range(self.args.numEps):
                    # print("executing mcts episode")
                    self.mcts = MCTS(self.game, self.nnet, self.args)  # reset search tree

                    iteration_train_examples += self.__executeEpisode()

                    # print("printing shape of single iteration train examples", np.size(iteration_train_examples))

                    # bookkeeping + plot progress
                    eps_time.update(time.time() - end)
                    end = time.time()
                    bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}'.format(eps=eps + 1, maxeps=self.args.numEps, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
                    bar.next()
                bar.finish()

                # save the iteration examples to the history
                self.trainExamplesHistory.append(iteration_train_examples)

            # check if exceeded num iterations for training
            if len(self.trainExamplesHistory) > self.args.numItersForTrainExamplesHistory:
                print("len(trainExamplesHistory) =", len(self.trainExamplesHistory), " => remove the oldest train_examples")
                self.trainExamplesHistory.pop(0)
            # backup history to a file
            # NB! the examples were collected using the model from the previous iteration, so (i-1)
            self.saveTrainExamples(i - 1)

            # shuffle examples before training
            train_examples = []
            for e in self.trainExamplesHistory:
                train_examples.extend(e)

            shuffle(train_examples)

            print("printing len of train examples: ", len(train_examples))
            # training new network, keeping a copy of the old one
            self.nnet.save_checkpoint(folder=self.args.checkpoint, filename='temp.pth.tar')
            # competitor network
            self.pnet.load_checkpoint(folder=self.args.checkpoint, filename='temp.pth.tar')
            # competitor mcts
            pmcts = MCTS(self.game, self.pnet, self.args)

            self.nnet.train(train_examples)
            nmcts = MCTS(self.game, self.nnet, self.args)

            print('PITTING AGAINST PREVIOUS VERSION')

            # create two new AI players that fight each other, each with different network - one with pnet and other with nnet
            def player1(x, player):
                return np.argmax(pmcts.getActionProb(x, player, temp=0))

            def player2(x, player):
                return np.argmax(nmcts.getActionProb(x, player, temp=0))

            arena = Arena(player1, player2, self.game)
            # returns wins for competitive network - pwins and wins for current network - nwins
            pwins, nwins, draws = arena.playGames(self.args.arenaCompare, self.args.verbose)

            print('NEW/PREV WINS : %d / %d ; DRAWS : %d' % (nwins, pwins, draws))
            print("New Wins", nwins, "Prev wins", pwins, "Draws", draws)
            if pwins + nwins > 0 and float(nwins) / (pwins + nwins) < self.args.updateThreshold:
                print('REJECTING NEW MODEL')
                self.nnet.load_checkpoint(folder=self.args.checkpoint, filename='temp.pth.tar')
            else:
                print('ACCEPTING NEW MODEL')
                self.nnet.save_checkpoint(folder=self.args.checkpoint, filename=self.getCheckpointFile(i))
                self.nnet.save_checkpoint(folder=self.args.checkpoint, filename='best.pth.tar')

    @staticmethod
    def getCheckpointFile(iteration):
        return 'checkpoint_' + str(iteration) + '.pth.tar'

    def saveTrainExamples(self, iteration):
        folder = self.args.checkpoint
        if not os.path.exists(folder):
            os.makedirs(folder)
        filename = os.path.join(folder, self.getCheckpointFile(iteration) + ".examples")
        with open(filename, "wb+") as f:
            Pickler(f).dump(self.trainExamplesHistory)

    def loadTrainExamples(self):
        model_file = os.path.join(self.args.load_folder_file[0], self.args.load_folder_file[1])
        examples_file = model_file + ".examples"
        if not os.path.isfile(examples_file):
            r = input("File with trainExamples not found. Continue? [y|n]")
            if r != "y":
                sys.exit()
        else:
            print("File with trainExamples found. Read it.")
            with open(examples_file, "rb") as f:
                self.trainExamplesHistory = Unpickler(f).load()
            # examples based on the model were already collected (loaded)
            self.skipFirstSelfPlay = True
