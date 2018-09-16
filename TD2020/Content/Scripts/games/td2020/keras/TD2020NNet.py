import os

from tensorflow import Tensor
from tensorflow.python.keras import Input, Model
from tensorflow.python.keras.layers import Conv2D, BatchNormalization, Activation, Dense, Dropout, Flatten, MaxPool2D
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
        # Tensor("input_1:0", shape=(?, 8, 8, 1), dtype=float32) -> x,y,max_on_tile
        self.input_boards: Tensor = Input(name='state_input_x_y_nat', shape=(self.board_x, self.board_y, self.max_actors_on_tile))  # s: batch_size x board_x x board_y x max_num_actors_on_tile
        # TODO - i mignt not need reashaping
        # Tensor("reshape/Reshape:0", shape=(?, 8, 8, 1), dtype=float32) -> x,y,max_on_tile
        # x_image: Tensor = Reshape((self.board_x, self.board_y, self.max_actors_on_tile))(self.input_boards)  # batch_size  x board_x x board_y x max_num_actors_on_tile

        # print("shape of input", np.shape(self.input_boards), "x_image:", np.shape(x_image))
        # Conv2D layers need 4D inputs: (samples, width, height, input_channels), and will output (samples, modified_width, modified_height, filters)

        # Todo - write that u added use_bias to false, because of issue or commit - check it out

        # conv2d paddings:
        #  "valid" means "no padding".
        #  "same" - adds zeroes to pad

        # batch normalization:
        # Normalize the activations of the previous layer at each batch, i.e. applies a transformation that maintains the mean activation close to 0 and the activation standard deviation close to 1.

        # Tensor("activation/Relu:0", shape=(?, 8, 8, 512), dtype=float32) -> 512 is num_channels
        h_conv1: Tensor = Activation('relu', name='activation1_relu')(BatchNormalization(axis=3, name='batch_norm1_axis3')(Conv2D(args.num_channels, 3, name='conv1_padding_same', padding='same', use_bias=False)(self.input_boards)))  # batch_size  x board_x x board_y x num_channels

        # pool = MaxPool2D(pool_size=(2,2))(h_conv1)

        # Tensor("activation_1/Relu:0", shape=(?, 8, 8, 512), dtype=float32) -> 512 is num_channels
        h_conv2: Tensor = Activation('relu', name='activation2_relu')(BatchNormalization(axis=3, name='batch_norm2_axis3')(Conv2D(args.num_channels, 3, name='conv2_padding_same', padding='same', use_bias=False)(h_conv1)))  # batch_size  x board_x x board_y x num_channels
        # Tensor("activation_2/Relu:0", shape=(?, 6, 6, 512), dtype=float32) -> 512 is num_channels
        h_conv3: Tensor = Activation('relu', name='activation3_relu')(BatchNormalization(axis=3, name='batch_norm3_axis3')(Conv2D(args.num_channels, 3, name='conv3_padding_valid', padding='valid', use_bias=False)(h_conv2)))  # batch_size  x (board_x-2) x (board_y-2) x num_channels
        # Tensor("activation_3/Relu:0", shape=(?, 4, 4, 512), dtype=float32) -> 512 is num_channels
        h_conv4: Tensor = Activation('relu', name='activation4_relu')(BatchNormalization(axis=3, name='batch_norm4_axis3')(Conv2D(args.num_channels, 3, name='conv4_padding_valid', padding='valid', use_bias=False)(h_conv3)))  # batch_size  x (board_x-4) x (board_y-4) x num_channels
        # Tensor("activation_3/Relu:0", shape=(?, 2, 2, 512), dtype=float32) -> 512 is num_channels
        h_conv5: Tensor = Activation('relu', name='activation5_relu')(BatchNormalization(axis=3, name='batch_norm5_axis3')(Conv2D(args.num_channels, 3, name='conv5_padding_valid', padding='valid', use_bias=False)(h_conv4)))  # batch_size  x (board_x-6) x (board_y-6) x num_channels

        # Tensor("flatten/Reshape:0", shape=(?, 2048), dtype=float32)
        h_conv5_flat: Tensor = Flatten(name='flatten_conv5')(h_conv5)

        # Dropout consists in randomly setting a fraction rate of input units to 0 at each update during training time, which helps prevent overfitting.
        # Tensor("dropout/cond/Merge:0", shape=(?, 1024), dtype=float32)
        # dropout in config 0.3

        # dense1_1024 params -> 2*2*512*1024 ((board_x-6) x (board_y-6) x num_channels x fc1)
        s_fc1: Tensor = Dropout(args.dropout, name='s_fc1_droput')(Activation('relu', name='activation6_relu')(BatchNormalization(axis=1, name='batch_norm6_axis1')(Dense(args.fc1, name='dense1_1024', use_bias=False)(h_conv5_flat))))  # batch_size x 1024
        # Tensor("dropout_1/cond/Merge:0", shape=(?, 512), dtype=float32)
        # dropout in config 0.3
        s_fc2: Tensor = Dropout(args.dropout, name='s_fc2_droput')(Activation('relu', name='activation7_relu')(BatchNormalization(axis=1, name='batch_norm7_axis1')(Dense(args.fc2, name='dense2_512', use_bias=False)(s_fc1))))  # batch_size x 1024

        # Tensor("pi/Softmax:0", shape=(?, 384), dtype=float32) - 384 -> action size
        # softmax activation (fits numbers between 0 and 1) (non linear)-> https://qph.fs.quoracdn.net/main-qimg-fda2f008df90ed5d7b6aff89b881e1ac
        self.pi: Tensor = Dense(self.action_size, activation='softmax', name='pi_dense_softmax')(s_fc2)  # batch_size x self.action_size
        # Tensor("v/Tanh:0", shape=(?, 1), dtype=float32) -> single output for probability
        # activation tanh (non linear)-> https://i2.wp.com/sefiks.com/wp-content/uploads/2017/01/tanh.png?resize=456%2C300&ssl=1
        self.v: Tensor = Dense(1, activation='tanh', name='v_dense_tanh')(s_fc2)  # batch_size x 1
        # <tensorflow.python.keras.engine.training.Model object at 0x0000026BF6D7EFD0>
        self.model: Model = Model(inputs=self.input_boards, outputs=[self.pi, self.v])
        self.model.compile(loss=['categorical_crossentropy', 'mean_squared_error'], optimizer=Adam(args.lr))  # learning rate in config -> 0.001
        # print("summary", self.model.summary())