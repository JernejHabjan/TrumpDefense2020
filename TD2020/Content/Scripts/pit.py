from config_file import PATH, PIT_ARGS, LEARN_ARGS
from systems.arena import Arena
from systems.mcts import MCTS
from games.td2020.Game import Game
from games.td2020.Players import RandomPlayer, HumanPlayer, GreedyPlayer
from games.td2020.keras.NNet import NNetWrapper as NNet

import numpy as np

"""
use this script to play any two agents against each other, or play manually with
any agent.
"""


class PitWrapper:
    def __init__(self) -> None:
        self.game = Game(PIT_ARGS)

        # all players
        self.rp = RandomPlayer(self.game).play
        self.gp = GreedyPlayer(self.game).play
        self.hp = HumanPlayer(self.game).play

        # systems
        self.n1 = NNet(self.game)
        self.n1.load_checkpoint(LEARN_ARGS.checkpoint, LEARN_ARGS.checkpoint_file)
        self.mcts1 = MCTS(self.game, self.n1, PIT_ARGS)

        # nnet player
        def nnp(x, player): return np.argmax(self.mcts1.get_action_prob(x, player, temp=0))

        arena = Arena(self.hp, nnp, self.game)
        print(arena.play_games(2, PIT_ARGS.verbose))


if __name__ == '__main__':
    PitWrapper()
