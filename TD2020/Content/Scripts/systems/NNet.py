from typing import List, Tuple

from games.td2020.Game import Game


# noinspection PyUnusedLocal
class NNetWrapperParent:
    def __init__(self, game: Game) -> None:
        pass

    def nnet_train(self, examples: List) -> None:
        pass

    def nnet_predict(self, board) -> Tuple[List, int]:
        pass

    def save_checkpoint(self, folder, filename) -> None:
        pass

    def load_checkpoint(self, folder, filename) -> None:
        pass
