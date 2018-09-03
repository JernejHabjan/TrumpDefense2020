import os
import sys
import time
from collections import deque
from pickle import Pickler, Unpickler
from random import shuffle
from typing import List, Tuple, Deque, Any, Iterable

import numpy as np

from config_file import ALL_ACTIONS_INT
from games.td2020.Game import Game
from games.td2020.src.Board import Board
from games.td2020.src.FunctionLibrary import action_into_array, action_into_array_print
from systems.NNet import NNetWrapperParent
from systems.arena import Arena
from systems.mcts import MCTS
from systems.misc.misc import AverageMeter
from systems.misc.progress.bar import Bar
from systems.types import ActionEncoding, CoachEpisode, CanonicalBoard
from systems.utils import DotDict


class Coach:
    """
    This class executes the self-play + learning. It uses the functions defined
    in Game and NeuralNet. args are specified in learn.py.
    """

    def __init__(self, game: Game, nnet, args) -> None:
        self.game: Game = game
        self.nnet: NNetWrapperParent = nnet
        self.pnet: NNetWrapperParent = self.nnet.__class__(self.game)  # the competitor network
        self.args: DotDict = args
        self.mcts: MCTS = MCTS(self.game, self.nnet, self.args)
        self.train_examples_history: List[Deque[CoachEpisode]] = []  # history of examples from args.numItersForTrainExamplesHistory latest iterations
        self.skipFirstSelfPlay: bool = False  # can be overridden in load_train_examples()

    def _execute_episode(self) -> CoachEpisode:
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
        train_examples: List[Tuple[ActionEncoding, int, List[int], None]] = []

        # init board
        board: Board = self.game.get_init_board()
        # set current player
        self.curPlayer: int = 1
        # set episodes counter
        episode_step: int = 0

        while True:
            # print("this is one iteration here in coach")
            episode_step += 1

            # sets temp var that is passed into MCTS get_action_prob
            temp: int = int(episode_step < self.args.tempThreshold)

            # returns probability from get_action_prob

            # pi of size
            pi: List[int] = self.mcts.get_action_prob(board, self.curPlayer, temp=temp)
            canonical_board: CanonicalBoard = self.game.get_canonical_form(board, self.curPlayer)

            # sym size 8 (num of symmetries), ndarray(width,height,num_actors_tile), list(385) ## TODO - TUKEJ JE 385 namest 384(width,height,num_actors)
            sym: List[Tuple[ActionEncoding, List[int]]] = self.game.get_symmetries(canonical_board, pi)  # make nnet_train examples
            # iterating through symmetries with tuple board,pi
            for b, p in sym:
                # appends board, player, pi, None

                train_examples.append((b, self.curPlayer, p, None))

            # random action probability
            # parameter p : how uniform this sample is -> https://goo.gl/3D6yrj

            # print("COACH.py printing pi", pi,"printing len pi",len(pi))
            action: int = np.random.choice(len(pi), p=pi)  # TODO tukej zna bit problem ker izbira s pi porazdelitvijo random

            # apply action

            if self.args.verbose > 0:
                pass
                action_into_array_print(board, action, "coach.py " + "player " + str(self.curPlayer) + "getting new state with action");
            board, self.curPlayer = self.game.get_next_state(board, self.curPlayer, action)

            # get winning player in variable "r"
            r: float = self.game.get_game_ended(board)

            # if game has ended
            if r != 0:
                # x[0] -> board
                # x[1] -> player
                # x[2] -> pi
                if self.args.verbose == 3 or self.args.verbose == 5:
                    print("coach - episode ended with result:", r)
                    board.display()
                return [(x[0], x[2], r * ((-1) ** (x[1] != self.curPlayer))) for x in train_examples]

    def coach_learn(self) -> None:
        """
        Performs numIters iterations with numEps episodes of self-play in each
        iteration. After every iteration, it retrains neural network with
        examples in train_examples (which has a maximium length of maxlenofQueue).
        It then pits the new neural network against the old one and accepts it
        only if it wins >= updateThreshold fraction of games.

        USED: learn.py
        """

        for i in range(1, self.args.numIters + 1):
            # bookkeeping - not important
            print('------ITER ' + str(i) + '------')
            # examples of the iteration
            if not self.skipFirstSelfPlay or i > 1:
                iteration_train_examples: Deque[CoachEpisode] = deque([], maxlen=self.args.maxlenOfQueue)

                eps_time: AverageMeter = AverageMeter()
                bar = Bar('Self Play', max=self.args.numEps)
                end = time.time()

                for eps in range(self.args.numEps):
                    # print("executing mcts episode")
                    self.mcts: MCTS = MCTS(self.game, self.nnet, self.args)  # reset _search tree

                    iteration_train_examples += self._execute_episode()  # do not try to append - because then it doesnt work

                    # bookkeeping + plot progress
                    eps_time.update(time.time() - end)
                    end = time.time()
                    bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}'.format(eps=eps + 1, maxeps=self.args.numEps, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
                    bar.next()
                bar.finish()

                # save the iteration examples to the history
                self.train_examples_history.append(iteration_train_examples)

            # check if exceeded num iterations for training
            if len(self.train_examples_history) > self.args.numItersForTrainExamplesHistory:
                print("len(train_examples_history) =", len(self.train_examples_history), " => remove the oldest train_examples")
                self.train_examples_history.pop(0)
            # backup history to a file
            # NB! the examples were collected using the model from the previous iteration, so (i-1)
            self.save_train_examples(i - 1)

            # shuffle examples before training
            train_examples: List[CoachEpisode] = []
            for e in self.train_examples_history:
                train_examples.extend(e)

            shuffle(train_examples)

            print("printing len of nnet_train examples: ", len(train_examples))
            # training new network, keeping a copy of the old one
            self.nnet.save_checkpoint(folder=self.args.checkpoint, filename=self.args.checkpoint_file)
            # competitor network
            self.pnet.load_checkpoint(folder=self.args.checkpoint, filename=self.args.checkpoint_file)
            # competitor mcts
            pmcts: MCTS = MCTS(self.game, self.pnet, self.args)

            self.nnet.nnet_train(train_examples)
            nmcts: MCTS = MCTS(self.game, self.nnet, self.args)

            print('PITTING AGAINST PREVIOUS VERSION')

            # create two new AI players that fight each other, each with different network - one with pnet and other with nnet
            def player1(x, player):
                return np.argmax(pmcts.get_action_prob(x, player, temp=0))

            def player2(x, player):
                return np.argmax(nmcts.get_action_prob(x, player, temp=0))

            arena: Arena = Arena(player1, player2, self.game)
            # returns wins for competitive network - pwins and wins for current network - nwins
            pwins, nwins, draws = arena.play_games(self.args.arenaCompare, self.args.verbose)

            print('NEW/PREV WINS : %d / %d ; DRAWS : %d' % (nwins, pwins, draws))
            print("New Wins", nwins, "Prev wins", pwins, "Draws", draws)
            if pwins + nwins > 0 and float(nwins) / (pwins + nwins) < self.args.updateThreshold:
                print('REJECTING NEW MODEL')
                self.nnet.load_checkpoint(folder=self.args.checkpoint, filename=self.args.checkpoint_file)
            else:
                print('ACCEPTING NEW MODEL')
                self.nnet.save_checkpoint(folder=self.args.checkpoint, filename=self._get_checkpoint_file(i))
                self.nnet.save_checkpoint(folder=self.args.checkpoint, filename=self.args.best_file)

    @staticmethod
    def _get_checkpoint_file(iteration) -> str:
        return 'checkpoint_' + str(iteration) + '.pth.tar'

    def save_train_examples(self, iteration) -> None:
        folder: str = self.args.checkpoint
        if not os.path.exists(folder):
            os.makedirs(folder)
        filename = os.path.join(folder, self._get_checkpoint_file(iteration) + ".examples")
        with open(filename, "wb+") as f:
            Pickler(f).dump(self.train_examples_history)

    def load_train_examples(self) -> None:
        model_file: str = os.path.join(self.args.load_folder_file[0], self.args.load_folder_file[1])
        examples_file: str = model_file + ".examples"
        if not os.path.isfile(examples_file):
            r = input("File with trainExamples not found. Continue? [y|n]")
            if r != "y":
                sys.exit()
        else:
            print("File with trainExamples found. Read it.")
            with open(examples_file, "rb") as f:
                self.train_examples_history = Unpickler(f).load()
            # examples based on the model were already collected (loaded)
            self.skipFirstSelfPlay = True
