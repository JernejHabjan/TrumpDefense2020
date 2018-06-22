import math
import numpy as np

EPS = 1e-8


class MCTS:
    """
    This class handles the MCTS tree.
    """

    def __init__(self, game, nnet, args):
        self.game = game
        self.nnet = nnet
        self.args = args
        self.Qsa = {}  # stores Q values for s,a (as defined in the paper)
        self.Nsa = {}  # stores #times edge s,a was visited
        self.Ns = {}  # stores #times board s was visited
        self.Ps = {}  # stores initial policy (returned by neural net)

        self.Es = {}  # stores game.getGameEnded ended for board s
        self.Vs = {}  # stores game.getValidMoves for board s

        # PS:
        """
            {array([0.        , 0.        , 0.        , 0.        , 0.        ,
                    0.        , 0.        , 0.        , 0.25112109, 0.        ,
                    0.        , 0.        , 0.        , 0.24944946, 0.        ,
                    0.        , 0.        , 0.        , 0.        , 0.        ,
                    0.        , 0.        , 0.2495447 , 0.        , 0.        ,
                    0.        , 0.        , 0.24988475, 0.        , 0.        ,
                    0.        , 0.        , 0.        , 0.        , 0.        ,
                    0.        , 0.        ])}
        """

    def getActionProb(self, board, player, temp=1):

        # print("getting action probability")
        """
        This function performs numMCTSSims simulations of MCTS starting from
        canonical_board.

        Returns:
            probs: a policy vector where the probability of the ith action is
                   proportional to Nsa[(s,a)]**(1./temp)
        """

        # runs simulation multiple times
        for i in range(self.args.numMCTSSims):
            self.search(board, player)

        # get string representation of this board in canonical way - ugly string
        s = self.game.stringRepresentation(self.game.getCanonicalForm(board, player))
        # stores number of counts for each action in given state - state "s"
        counts = [self.Nsa[(s, a)] if (s, a) in self.Nsa else 0 for a in range(self.game.getActionSize())]

        if temp == 0:
            # get action with most counts in Nsa for this state
            best_a = np.argmax(counts)
            probs = [0] * len(counts)
            # noinspection PyTypeChecker
            probs[best_a] = 1
            return probs

        counts = [x ** (1. / temp) for x in counts]
        probs = [x / float(sum(counts)) for x in counts]
        return probs

    def search(self, board, player):
        """
        This function performs one iteration of MCTS. It is recursively called
        till a leaf node is found. The action chosen at each node is one that
        has the maximum upper confidence bound as in the paper.

        Once a leaf node is found, the neural network is called to return an
        initial policy P and a value v for the state. This value is propogated
        up the search path. In case the leaf node is a terminal state, the
        outcome is propogated up the search path. The values of Ns, Nsa, Qsa are
        updated.

        NOTE: the return values are the negative of the value of the current
        state. This is done since v is in [-1,1] and if v is the value of a
        state for the current player, then its value is -v for the other player.

        Returns:
            v: the negative of the value of the current canonical_board
        """

        # get string representation of this board in canonical way - ugly string
        s = self.game.stringRepresentation(self.game.getCanonicalForm(board, player))

        # if not yet in dictionary ES, which stores game.getGameEnded ended for board s
        # if s not in self.Es: # TODO --------------- @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENTED THESE 4 LINES - if actor chooses idle - state remains the same and timeout condition is not checked again
        #     # add player who won to that state in dictionary Es
        #     self.Es[s] = self.game.getGameEnded(canonical_board, 1)
        #     # check if game has finished in this node

        self.Es[s] = self.game.getGameEnded(board, 1)

        # check for terminal condition - end state
        if self.Es[s] != 0:
            # terminal node - return this state back
            # print("recieved terminal state", self.Es[s])
            return -self.Es[s]

        # if state not yet in dictionary
        if s not in self.Ps:
            # leaf node

            # here for example keras NNet for Othello game is called, which calls then self.nnet.model.predict(board), which is library function
            # it inputs canonical_board, that should look like this:
            """
            [[ 0  0  0  0  0  0]
             [ 0  0  0  0  0  0]
             [ 0  0 -1  1  0  0]
             [ 0  0  1 -1  0  0]
             [ 0  0  0  0  0  0]
             [ 0  0  0  0  0  0]]
            """

            # self.nnet.predict returns next values:
            #     pi: a policy vector for the current board- a numpy array of length game.getActionSize
            #     v: a float in [-1,1] that gives the value of the current board

            self.Ps[s], v = self.nnet.predict(self.game.getCanonicalForm(board, player))
            # self.PS[s]

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

            # get all valid moves for this board
            # valids is 1-d fixed size binary numpy vector
            # for example
            """
            [0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0]
            """
            valids = self.game.getValidMoves(board, player)

            # masking invalid moves
            self.Ps[s] = self.Ps[s] * valids
            # now self.Ps[s] contains only valid predictions
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
        valids = self.Vs[s]
        # best value
        cur_best = -float('inf')
        # best action
        best_act = -1

        # pick the action with the highest upper confidence bound
        # loop through all actions
        for a in range(self.game.getActionSize()):
            # print("action size of size ", self.game.getActionSize())
            # print("printing action of getActionSize in search mcts", a)
            # if action in valid moves for this state
            if valids[a]:
                if (s, a) in self.Qsa:
                    # here is our formula
                    u = self.Qsa[(s, a)] + self.args.cpuct * self.Ps[s][a] * math.sqrt(self.Ns[s]) / (1 + self.Nsa[(s, a)])
                else:
                    u = self.args.cpuct * self.Ps[s][a] * math.sqrt(self.Ns[s] + EPS)  # Q = 0 ?

                # print("u ", u, "for current action", a) # todo printing U for action

                if u > cur_best:
                    cur_best = u
                    best_act = a

        # print("MCTS CHOSE ACTION", best_act)
        # now we got best action
        a = best_act
        # apply this action to game - get full board and player

        next_s, next_player = self.game.getNextState(board, player, a)

        # calls recursively this search function again and returns terminal or leaf state in variable "v"
        # print("going deeper")
        v = self.search(next_s, next_player)

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
        return -v
