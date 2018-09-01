import os
import sys
from tensorflow.python.keras import Input, Model
from tensorflow.python.keras.layers import Conv2D, BatchNormalization, Activation, Reshape, Dense, Dropout, Flatten
from tensorflow.python.keras.optimizers import Adam


from config_file import SHOW_TENSORFLOW_GPU

if not SHOW_TENSORFLOW_GPU:
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

sys.path.append('..')


class TD2020NNet:
    def __init__(self, game, args):
        # game params
        self.board_x, self.board_y, self.max_actors_on_tile = game.getBoardSize()

        self.action_size = game.getActionSize()
        self.args = args

        # Neural Net
        self.input_boards = Input(shape=(self.board_x, self.board_y, self.max_actors_on_tile))  # s: batch_size x board_x x board_y x max_num_actors_on_tile
        x_image = Reshape((self.board_x, self.board_y, self.max_actors_on_tile))(self.input_boards)  # batch_size  x board_x x board_y x max_num_actors_on_tile

        # print("shape of input", np.shape(self.input_boards), "x_image:", np.shape(x_image))
        # Conv2D layers need 4D inputs: (samples, width, height, input_channels), and will output (samples, modified_width, modified_height, filters)

        h_conv1 = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='same', use_bias=False)(x_image)))  # batch_size  x board_x x board_y x num_channels
        h_conv2 = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='same', use_bias=False)(h_conv1)))  # batch_size  x board_x x board_y x num_channels
        h_conv3 = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='valid', use_bias=False)(h_conv2)))  # batch_size  x (board_x-2) x (board_y-2) x num_channels
        h_conv4 = Activation('relu')(BatchNormalization(axis=3)(Conv2D(args.num_channels, 3, padding='valid', use_bias=False)(h_conv3)))  # batch_size  x (board_x-4) x (board_y-4) x num_channels
        h_conv4_flat = Flatten()(h_conv4)  # shape=(?, 2048)

        # Dropout consists in randomly setting a fraction rate of input units to 0 at each update during training time, which helps prevent overfitting.
        s_fc1 = Dropout(args.dropout)(Activation('relu')(BatchNormalization(axis=1)(Dense(1024, use_bias=False)(h_conv4_flat))))  # batch_size x 1024
        s_fc2 = Dropout(args.dropout)(Activation('relu')(BatchNormalization(axis=1)(Dense(512, use_bias=False)(s_fc1))))  # batch_size x 512
        self.pi = Dense(self.action_size, activation='softmax', name='pi')(s_fc2)  # batch_size x self.action_size

        self.v = Dense(1, activation='tanh', name='v')(s_fc2)  # batch_size x 1

        self.model = Model(inputs=self.input_boards, outputs=[self.pi, self.v])
        self.model.compile(loss=['categorical_crossentropy', 'mean_squared_error'], optimizer=Adam(args.lr))
