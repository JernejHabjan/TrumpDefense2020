import os
from typing import List, Tuple

import numpy as np
from tensorflow.python.keras.callbacks import TensorBoard
# noinspection PyUnresolvedReferences
from tensorflow.python.keras.utils import plot_model

from config_file import NNET_ARGS
from games.td2020.Game import Game
from systems.nnet import NNetWrapperParent
from systems.types import CanonicalBoard, V, Pi, ActionEncoding, CoachEpisode
from .TD2020NNet import TD2020NNet as ONNet


class NNetWrapper(NNetWrapperParent):
    def __init__(self, game: Game) -> None:

        super().__init__(game)
        self.nnet: ONNet = ONNet(game, NNET_ARGS)
        self.action_size: int = game.get_action_size

        self.tensorboard: TensorBoard = TensorBoard(log_dir='_Files\\models\\logs' + type(self.nnet).__name__, histogram_freq=0, write_graph=True, write_images=True)
        plot_model(self.nnet.model, to_file='_Files\\models\\' + type(self.nnet).__name__ + '_model_plot.png', show_shapes=True, show_layer_names=True)

    def nnet_train(self, examples: List[CoachEpisode]) -> None:
        """
        examples: list of examples, each example is of form (board, pi, v)
        """

        input_boards, target_pis, target_vs = list(zip(*examples))

        input_boards: ActionEncoding = np.asarray(input_boards)
        target_pis: List[Pi] = np.asarray(target_pis)
        target_vs: List[V] = np.asarray(target_vs)

        self.nnet.model.fit(x=input_boards, y=[target_pis, target_vs], batch_size=NNET_ARGS.batch_size, epochs=NNET_ARGS.epochs, callbacks=[self.tensorboard])

    def nnet_predict(self, canonical_board: CanonicalBoard) -> Tuple[Pi, V]:
        """
        :param canonical_board:
        :return:
        USED:
            MCTS - search - creates Ps[state], v from current canonical form
        """
        canonical_board = canonical_board[np.newaxis, :, :]
        pi, v = self.nnet.model.predict(canonical_board)
        pi: List[Pi] = pi
        v: List[V] = v

        # print('PREDICTION TIME TAKEN : {0:03f}'.format(time.time()-start))
        return pi[0], v[0]


    def save_checkpoint(self, folder, filename) -> None:
        filepath: str = os.path.join(folder, filename)
        if not os.path.exists(folder):
            print("Checkpoint Directory does not exist! Making directory {}".format(folder))
            os.mkdir(folder)
        else:
            print("Checkpoint Directory exists! ")
        self.nnet.model.save_weights(filepath)

    def load_checkpoint(self, folder, filename) -> None:
        # if file has ending .index, it still loads without that suffix (for example if file is saved as temp.pth.tar.index, load it as 'temp.pth.tar' and save it as 'temp.pth.tar'
        filepath: str = os.path.join(folder, filename)
        # if not os.path.exists(filepath):
        #     raise ValueError("No model in path {}".format(filepath))

        print("NNet", "loading checkpoint", filepath)

        try:
            self.nnet.model.load_weights(filepath)
        except (FileNotFoundError, Exception) as e:
            raise Exception("Did you train your model with same dimensions as used for pit? Also does folder contain specified file? ->", e)
