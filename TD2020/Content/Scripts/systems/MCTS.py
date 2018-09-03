import math
from typing import Dict, List

import numpy as np

from config_file import EPS
from games.td2020.Game import Game
from games.td2020.src.Board import Board
from systems.types import StrPresentation, ValidMoves, NodeType
from systems.utils import DotDict


class MCTS:
    """
    This class handles the MCTS tree.
    """

    def __init__(self, game: Game, nnet, args) -> None:
        self.game: Game = game
        self.nnet = nnet
        self.args: DotDict = args
        self.Qsa: NodeType = {}  # stores Q values for s,a (as defined in the paper)
        self.Nsa: NodeType = {}  # stores #times edge s,a was visited
        self.Ns: NodeType = {}  # stores #times board s was visited
        self.Ps: NodeType = {}  # stores initial policy (returned by neural net)

        self.Es: Dict[StrPresentation, float] = {}  # stores game.get_game_ended ended for board s
        self.Vs: Dict[StrPresentation, float] = {}  # stores game.get_valid_moves_board for board s

    def get_action_prob(self, board, player, temp=1) -> List[int]:

        """
        This function performs numMCTSSims simulations of MCTS starting from
        canonical_board.

        Returns:
            probs: a policy vector where the probability of the ith action is
                   proportional to Nsa[(s,a)]**(1./temp)
        """

        # runs simulation multiple times
        for i in range(self.args.numMCTSSims):
            self._search(board, player)

        # get string representation of this board in canonical way - ugly string
        s: StrPresentation = self.game.string_representation(self.game.get_canonical_form(board, player))
        # stores number of counts for each action in given state - state "s"
        counts: List[int] = [self.Nsa[(s, a)] if (s, a) in self.Nsa else 0 for a in range(self.game.get_action_size())]
        if temp == 0:
            # get action with most counts in Nsa for this state
            best_a = np.argmax(counts)

            probs: list = [0] * len(counts)
            # noinspection PyTypeChecker
            probs[best_a] = 1
            return probs

        counts = [x ** (1. / temp) for x in counts]
        probs = [x / float(sum(counts)) for x in counts]
        return probs

    def _search(self, board: Board, player: int) -> float:
        """
        This function performs one iteration of MCTS. It is recursively called
        till a leaf node is found. The action chosen at each node is one that
        has the maximum upper confidence bound as in the paper.

        Once a leaf node is found, the neural network is called to return an
        initial policy P and a value v for the state. This value is propogated
        up the _search path. In case the leaf node is a terminal state, the
        outcome is propogated up the _search path. The values of Ns, Nsa, Qsa are
        updated.

        NOTE: the return values are the negative of the value of the current
        state. This is done since v is in [-1,1] and if v is the value of a
        state for the current player, then its value is -v for the other player.

        Returns:
            v: the negative of the value of the current canonical_board (float)
        """

        # print("called mcts _search")

        # get string representation of this board in canonical way - ugly string
        s: StrPresentation = self.game.string_representation(self.game.get_canonical_form(board, player))

        # check if game has finished in this node
        # have to check for gameEnded every _search because of timeout iteration even if board is always same

        self.Es[s] = self.game.get_game_ended(board)

        # print("mcts _search checking end condition", self.Es[s])

        # check for terminal condition - end state
        if self.Es[s] != 0:
            # terminal node - return this state back
            # print("received terminal state", self.Es[s])
            return -self.Es[s]

        # if state not yet in dictionary
        if s not in self.Ps:
            # leaf node

            # self.nnet.nnet_predict returns next values:
            #     pi: a policy vector for the current board- a numpy array of length game.get_action_size
            #     v: a float in [-1,1] that gives the value of the current board

            self.Ps[s], v = self.nnet.nnet_predict(self.game.get_canonical_form(board, player))

            valids: ValidMoves = self.game.get_valid_moves(board, player)

            # masking invalid moves
            self.Ps[s] = self.Ps[s] * valids
            # now self.Ps[s] contains only valid predictions
            # print("mcts.py","printing valid predictions", self.Ps[s])

            sum_ps_s = np.sum(self.Ps[s])
            if sum_ps_s > 0:
                self.Ps[s] /= sum_ps_s  # renormalize
            else:
                # if all valid moves were masked make all valid moves equally probable

                # NB! All valid moves may be masked if either your NNet architecture is insufficient or you've get overfitting or something else.
                # If you have got dozens or hundreds of these messages you should pay attention to your NNet and/or training process.   
                print("All valid moves were masked, do workaround.")
                self.Ps[s] = self.Ps[s] + valids
                self.Ps[s] /= np.sum(self.Ps[s])

            self.Vs[s] = valids

            # leaf node
            self.Ns[s] = 0
            return -v

        # valids is valid moves for this state
        valids: ValidMoves = self.Vs[s]
        # best value
        cur_best = -float('inf')
        # best action
        best_act = -1

        # pick the action with the highest upper confidence bound
        # loop through all actions
        for a in range(self.game.get_action_size()):
            # if action in valid moves for this state
            if valids[a]:
                if (s, a) in self.Qsa:
                    # here is our formula
                    u = self.Qsa[(s, a)] + self.args.cpuct * self.Ps[s][a] * math.sqrt(self.Ns[s]) / (1 + self.Nsa[(s, a)])
                else:
                    u = self.args.cpuct * self.Ps[s][a] * math.sqrt(self.Ns[s] + EPS)  # Q = 0 ? ####################### JERNEJ HABJAN 2018-09-01 to je blo before
                    """
                    next_s, next_player = self.game.get_next_state(board, 1, a)
                    next_s = self.game.get_canonical_form(next_s, next_player)
                    Q = self.nnet.nnet_predict(board)[next_s][1]
                    u = Q + self.args.cpuct * self.Ps[s][a] * math.sqrt(self.Ns[s] + EPS)
                    """

                # print("u ", u, "for current action", a)
                if u > cur_best:
                    cur_best = u
                    best_act = a

        a = best_act
        # apply this action to game - get full board and player

        next_s, next_player = self.game.get_next_state(board, player, a)

        # calls recursively this _search function again and returns terminal or leaf state in variable "v"
        v: float = self._search(next_s, next_player)

        # print("received back terminal state from _search", v)
        if (s, a) in self.Qsa:
            # calculate new value for this Qsa
            # Num(state, action) * Value(state,action) + value / (Num(state,action) + 1)
            self.Qsa[(s, a)] = (self.Nsa[(s, a)] * self.Qsa[(s, a)] + v) / (self.Nsa[(s, a)] + 1)
            # append num times visited
            self.Nsa[(s, a)] += 1

        else:
            # we have not visited Qsa - set value of it as v
            self.Qsa[(s, a)] = v
            self.Nsa[(s, a)] = 1

        # visited this state +1 times
        self.Ns[s] += 1

        # print("returning -v to _search back",-v)
        return -v
