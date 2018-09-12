from typing import List, Tuple

from games.td2020 import Game
from games.td2020.src import Board
from systems.types import Pi, V, CoachEpisode


class NNetWrapperParent:
    # noinspection PyUnusedLocal
    def __init__(self, game: 'Game.Game') -> None:
        pass

    def nnet_train(self, examples: List[CoachEpisode]) -> None:
        pass

    def nnet_predict(self, board: 'Board.Board') -> Tuple[Pi, V]:
        pass

    def save_checkpoint(self, folder: str, filename: str) -> None:
        pass

    def load_checkpoint(self, folder: str, filename: str) -> None:
        pass
