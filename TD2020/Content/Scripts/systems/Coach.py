import os
import sys
import time
from collections import deque
from pickle import Pickler, Unpickler
from random import shuffle
from typing import List, Tuple, Deque

import numpy as np

from config_file import TIMEOUT_TICKS
from games.td2020.Game import Game
from games.td2020.src.Board import Board
from games.td2020.src.FunctionLibrary import action_into_array_print
from systems.nnet import NNetWrapperParent
from systems.arena import Arena
from systems.mcts import MCTS
from systems.misc.misc import AverageMeter
from systems.misc.progress.bar import Bar
from systems.types import ActionEncoding, CoachEpisode, CanonicalBoard, TrainExamples, TrainExamplesHistory, Sym, V, Pi
from systems.utils import DotDict


class Coach:
    """
    This class executes the self-play + learning. It uses the functions defined
    in Game and NeuralNet. args are specified in learn.py.
    """

    def __init__(self, game: Game, nnet: NNetWrapperParent, learn_args: DotDict) -> None:
        self.game: Game = game
        self.nnet: NNetWrapperParent = nnet
        self.pnet: NNetWrapperParent = self.nnet.__class__(self.game)  # the competitor network
        self.learn_args: DotDict = learn_args
        self.mcts: MCTS = MCTS(self.game, self.nnet, self.learn_args)
        self.train_examples_history: TrainExamplesHistory = []  # history of examples from args.numItersForTrainExamplesHistory latest iterations
        self.skipFirstSelfPlay: bool = learn_args.skip_first_self_play  # can be overridden in load_train_examples()

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
        train_examples: TrainExamples = []

        # init board
        board: Board = self.game.get_init_board
        # set current player
        self.cur_player: int = 1
        # set episodes counter
        episode_step: int = 0

        while True:
            # print("this is one iteration here in coach")
            episode_step += 1

            # sets temp var that is passed into MCTS get_action_prob
            temp: int = int(episode_step < self.learn_args.tempThreshold)

            # returns probability from get_action_prob

            # pi of size
            pi: List[int] = self.mcts.get_action_prob(board, self.cur_player, temp=temp)
            canonical_board: CanonicalBoard = self.game.get_canonical_form(board, self.cur_player)

            # sym size 8 (num of symmetries), ndarray(width,height,num_actors_tile), list(385) ## TODO - TUKEJ JE 385 namest 384(width,height,num_actors)
            sym: Sym = self.game.get_symmetries(canonical_board, pi)  # make nnet_train examples
            # iterating through symmetries with tuple board,pi
            for b, p in sym:
                b: Tuple[ActionEncoding] = b
                p: List[int] = p
                # appends board, player, pi, None

                train_examples.append((b, self.cur_player, p, None))

            # random action probability
            # parameter p : how uniform this sample is -> https://goo.gl/3D6yrj

            # print("COACH.py printing pi", pi,"printing len pi",len(pi))
            action: int = np.random.choice(len(pi), p=pi)  # TODO tukej zna bit problem ker izbira s pi porazdelitvijo random

            # apply action

            if self.learn_args.verbose > 2:
                pass
                if self.cur_player == 1:
                    curr_player_str = '+1'
                else:
                    curr_player_str = '-1'
                #action_into_array_print(board, action, "coach.py " + "player " + curr_player_str + " getting new state with action")
            board, self.cur_player = self.game.get_next_state(board, self.cur_player, action)
            board: Board = board
            # get winning player in variable "r"
            r: float = self.game.get_game_ended(board,self.cur_player)




            # if game has ended
            if r != 0 :
                # x[0] -> board
                # x[1] -> player
                # x[2] -> pi
                if self.learn_args.verbose == 2:
                    print("coach - episode ended with result:", r, "ticks",board.iteration)
                if self.learn_args.verbose == 3 or self.learn_args.verbose == 5:
                    print("coach - episode ended with result:", r, "ticks",board.iteration)
                    board.display()

                # unpacked so it can be seen what variables are what
                coach_episode: CoachEpisode = []
                for x in train_examples:
                    x: Tuple[ActionEncoding, int, List[int], None] = x
                    action_state: ActionEncoding = x[0]
                    pi: Pi = x[2]  # action probability like [0,0,0,0,0,...,0.5,0.5,...,0,0,0]
                    v: V = r * ((-1) ** (x[1] != self.cur_player))  # for example '-0.0001'
                    coach_episode.append((action_state, pi, v))
                return coach_episode

                # return [(x[0], x[2], r * ((-1) ** (x[1] != self.cur_player))) for x in train_examples]

    def coach_learn(self) -> None:
        """
        Performs numIters iterations with numEps episodes of self-play in each
        iteration. After every iteration, it retrains neural network with
        examples in train_examples (which has a maximium length of maxlenofQueue).
        It then pits the new neural network against the old one and accepts it
        only if it wins >= updateThreshold fraction of games.

        USED: learn.py
        """

        for i in range(1, self.learn_args.numIters + 1):
            # bookkeeping - not important
            print('------ITER ' + str(i) + '------')
            # examples of the iteration
            if not self.skipFirstSelfPlay or i > 1:
                iteration_train_examples: Deque[CoachEpisode] = deque([], maxlen=self.learn_args.maxlenOfQueue)

                eps_time: AverageMeter = AverageMeter()
                bar = Bar('Self Play', max=self.learn_args.numEps)
                end: time = time.time()

                for eps in range(self.learn_args.numEps):
                    # print("executing mcts episode")
                    self.mcts: MCTS = MCTS(self.game, self.nnet, self.learn_args)  # reset _search tree

                    iteration_train_examples += self._execute_episode()

                    # bookkeeping + plot progress
                    eps_time.update(time.time() - end)
                    end: time = time.time()
                    bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}'.format(eps=eps + 1, maxeps=self.learn_args.numEps, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
                    bar.next()
                bar.finish()

                # save the iteration examples to the history
                self.train_examples_history.append(iteration_train_examples)

            # check if exceeded num iterations for training
            if len(self.train_examples_history) > self.learn_args.numItersForTrainExamplesHistory:
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
            self.nnet.save_checkpoint(folder=self.learn_args.checkpoint, filename=self.learn_args.checkpoint_file)
            # competitor network
            self.pnet.load_checkpoint(folder=self.learn_args.checkpoint, filename=self.learn_args.checkpoint_file)
            # competitor mcts
            pmcts: MCTS = MCTS(self.game, self.pnet, self.learn_args)

            self.nnet.nnet_train(train_examples)
            nmcts: MCTS = MCTS(self.game, self.nnet, self.learn_args)

            print('PITTING AGAINST PREVIOUS VERSION')

            # create two new AI players that fight each other, each with different network - one with pnet and other with nnet

            def player1(x: Board, player: int):
                return np.argmax(pmcts.get_action_prob(x, player, temp=0))

            def player2(x: Board, player: int):
                return np.argmax(nmcts.get_action_prob(x, player, temp=0))


            arena: Arena = Arena(player1, player2, self.game)
            # returns wins for competitive network - pwins and wins for current network - nwins
            pwins, nwins, draws = arena.play_games(self.learn_args.arenaCompare, self.learn_args.verbose)
            pwins: int = pwins
            nwins: int = nwins
            draws: int = draws

            print('NEW/PREV WINS : %d / %d ; DRAWS : %d' % (nwins, pwins, draws))
            print("New Wins", nwins, "Prev wins", pwins, "Draws", draws)
            if pwins + nwins == 0:
                print('REJECTING NEW MODEL')
                self.nnet.load_checkpoint(folder=self.learn_args.checkpoint, filename=self.learn_args.checkpoint_file)
            elif pwins + nwins > 0 and float(nwins) / (pwins + nwins) < self.learn_args.updateThreshold:
                print('REJECTING NEW MODEL')
                self.nnet.load_checkpoint(folder=self.learn_args.checkpoint, filename=self.learn_args.checkpoint_file)
            else:
                print('ACCEPTING NEW MODEL')
                self.nnet.save_checkpoint(folder=self.learn_args.checkpoint, filename=self._get_checkpoint_file(i))
                self.nnet.save_checkpoint(folder=self.learn_args.checkpoint, filename=self.learn_args.best_file)

    @staticmethod
    def _get_checkpoint_file(iteration: int) -> str:
        return 'checkpoint_' + str(iteration) + '.pth.tar'

    def save_train_examples(self, iteration: int) -> None:
        folder: str = self.learn_args.checkpoint
        if not os.path.exists(folder):
            os.makedirs(folder)
        filename: str = os.path.join(folder, self._get_checkpoint_file(iteration) + ".examples")
        with open(filename, "wb+") as f:
            Pickler(f).dump(self.train_examples_history)

    def load_train_examples(self) -> None:
        model_file: str = os.path.join(self.learn_args.load_folder_file[0], self.learn_args.load_folder_file[1])
        examples_file: str = model_file + ".examples"
        if not os.path.isfile(examples_file):
            r: str = input("File with trainExamples not found. Continue? [y|n]")
            if r != "y":
                sys.exit()
        else:
            print("File with trainExamples found. Read it.")
            with open(examples_file, "rb") as f:
                self.train_examples_history: TrainExamplesHistory = Unpickler(f).load()
            # examples based on the model were already collected (loaded)
            self.skipFirstSelfPlay: bool = True
