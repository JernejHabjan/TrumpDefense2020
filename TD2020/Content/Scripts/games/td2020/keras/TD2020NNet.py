import os

from tensorflow import Tensor
from tensorflow.python.keras import Input, Model
from tensorflow.python.keras.layers import Conv2D, BatchNormalization, Activation, Reshape, Dense, Dropout, Flatten
from tensorflow.python.keras.optimizers import Adam

from config_file import SHOW_TENSORFLOW_GPU
from games.td2020 import Game
from systems.utils import DotDict

if not SHOW_TENSORFLOW_GPU:
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


class TD2020NNet:
    def __init__(self, game: 'Game.Game', args: DotDict) -> None:
        # game params
        self.board_x, self.board_y, self.max_actors_on_tile = game.get_board_size

        # self.width * self.height * MAX_ACTORS_ON_TILE * ALL_ACTIONS_LEN
        self.action_size: int = game.get_action_size
        self.args: DotDict = args

        # Neural Net
        # Tensor("input_1:0", shape=(?, 8, 8, 1), dtype=float32)
        self.input_boards: Tensor = Input(shape=(self.board_x, self.board_y, self.max_actors_on_tile))  # s: batch_size x board_x x board_y x max_num_actors_on_tile
        # Tensor("reshape/Reshape:0", shape=(?, 8, 8, 1), dtype=float32)
        x_image: Tensor = Reshape((self.board_x, self.board_y, self.max_actors_on_tile))(self.input_boards)  # batch_size  x board_x x board_y x max_num_actors_on_tile

        # print("shape of input", np.shape(self.input_boards), "x_image:", np.shape(x_image))
        # Conv2D layers need 4D inputs: (samples, width, height, input_channels), and will output (samples, modified_width, modified_height, filters)

        # Todo - write that u addded use_bias to false, because of issue or commit - check it out

        # Tensor("activation/Relu:0", shape=(?, 8, 8, 512), dtype=float32)
        h_conv1: Tensor = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='same', use_bias=False)(x_image)))  # batch_size  x board_x x board_y x num_channels
        # Tensor("activation_1/Relu:0", shape=(?, 8, 8, 512), dtype=float32)
        h_conv2: Tensor = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='same', use_bias=False)(h_conv1)))  # batch_size  x board_x x board_y x num_channels
        # Tensor("activation_2/Relu:0", shape=(?, 6, 6, 512), dtype=float32)
        h_conv3: Tensor = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='valid', use_bias=False)(h_conv2)))  # batch_size  x (board_x-2) x (board_y-2) x num_channels
        # Tensor("activation_3/Relu:0", shape=(?, 4, 4, 512), dtype=float32)
        h_conv4: Tensor = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='valid', use_bias=False)(h_conv3)))  # batch_size  x (board_x-4) x (board_y-4) x num_channels
        # Tensor("flatten/Reshape:0", shape=(?, 8192), dtype=float32)
        h_conv4_flat: Tensor = Flatten()(h_conv4)  # shape=(?, 2048)

        # Dropout consists in randomly setting a fraction rate of input units to 0 at each update during training time, which helps prevent overfitting.
        # Tensor("dropout/cond/Merge:0", shape=(?, 1024), dtype=float32)
        s_fc1: Tensor = Dropout(args.dropout)(Activation('relu')(BatchNormalization(axis=1)(Dense(1024, use_bias=False)(h_conv4_flat))))  # batch_size x 1024
        # Tensor("dropout_1/cond/Merge:0", shape=(?, 512), dtype=float32)
        s_fc2: Tensor = Dropout(args.dropout)(Activation('relu')(BatchNormalization(axis=1)(Dense(512, use_bias=False)(s_fc1))))  # batch_size x 512

        # Tensor("pi/Softmax:0", shape=(?, 384), dtype=float32)
        self.pi: Tensor = Dense(self.action_size, activation='softmax', name='pi')(s_fc2)  # batch_size x self.action_size
        # Tensor("v/Tanh:0", shape=(?, 1), dtype=float32)
        self.v: Tensor = Dense(1, activation='tanh', name='v')(s_fc2)  # batch_size x 1
        # <tensorflow.python.keras.engine.training.Model object at 0x0000026BF6D7EFD0>
        self.model: Model = Model(inputs=self.input_boards, outputs=[self.pi, self.v])
        self.model.compile(loss=['categorical_crossentropy', 'mean_squared_error'], optimizer=Adam(args.lr))
