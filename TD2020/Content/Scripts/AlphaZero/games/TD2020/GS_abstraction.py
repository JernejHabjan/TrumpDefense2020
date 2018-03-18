import numpy as np


class Game:

    def __init__(self):
        self.currentPlayer = 1
        self.gameState = GameState(np.zeros(64, dtype=np.int), 1)
        self.actionSpace = np.zeros(64, dtype=np.int)
        self.pieces = {'1': 'X', '0': '-', '-1': 'O'}
        self.grid_shape = (6, 7)
        self.input_shape = (2, 6, 7)
        self.name = 'connect4'
        self.state_size = len(self.gameState.binary)
        self.action_size = len(self.actionSpace)

    def reset(self):
        self.gameState = GameState(np.zeros(64, dtype=np.int), 1)
        self.currentPlayer = 1
        return self.gameState

    def step(self, action):
        next_state, value, done = self.gameState.take_action(action)
        self.gameState = next_state
        self.currentPlayer = -self.currentPlayer
        info = None
        return next_state, value, done, info

    @staticmethod
    def identities(state, action_values):
        identities = [(state, action_values)]

        current_board = state.board
        current_av = action_values

        current_board = np.array([current_board[i] for i in range(64)])

        current_av = np.array([current_av[i] for i in range(64)])

        identities.append((GameState(current_board, state.playerTurn), current_av))

        return identities


class GameState:
    def __init__(self, board, player_turn):
        self.board = board
        self.pieces = {'1': 'X', '0': '-', '-1': 'O'}
        self.winners = [
            [0, 1, 2, 3],
            [1, 2, 3, 4],
            [2, 3, 4, 5],
            [3, 4, 5, 6],
            [7, 8, 9, 10],
            [8, 9, 10, 11],
            [9, 10, 11, 12],
            [10, 11, 12, 13],
            [14, 15, 16, 17],
            [15, 16, 17, 18],
            [16, 17, 18, 19],
            [17, 18, 19, 20],
            [21, 22, 23, 24],
            [22, 23, 24, 25],
            [23, 24, 25, 26],
            [24, 25, 26, 27],
            [28, 29, 30, 31],
            [29, 30, 31, 32],
            [30, 31, 32, 33],
            [31, 32, 33, 34],
            [35, 36, 37, 38],
            [36, 37, 38, 39],
            [37, 38, 39, 40],
            [38, 39, 40, 41],

            [0, 7, 14, 21],
            [7, 14, 21, 28],
            [14, 21, 28, 35],
            [1, 8, 15, 22],
            [8, 15, 22, 29],
            [15, 22, 29, 36],
            [2, 9, 16, 23],
            [9, 16, 23, 30],
            [16, 23, 30, 37],
            [3, 10, 17, 24],
            [10, 17, 24, 31],
            [17, 24, 31, 38],
            [4, 11, 18, 25],
            [11, 18, 25, 32],
            [18, 25, 32, 39],
            [5, 12, 19, 26],
            [12, 19, 26, 33],
            [19, 26, 33, 40],
            [6, 13, 20, 27],
            [13, 20, 27, 34],
            [20, 27, 34, 41],

            [3, 9, 15, 21],
            [4, 10, 16, 22],
            [10, 16, 22, 28],
            [5, 11, 17, 23],
            [11, 17, 23, 29],
            [17, 23, 29, 35],
            [6, 12, 18, 24],
            [12, 18, 24, 30],
            [18, 24, 30, 36],
            [13, 19, 25, 31],
            [19, 25, 31, 37],
            [20, 26, 32, 38],

            [3, 11, 19, 27],
            [2, 10, 18, 26],
            [10, 18, 26, 34],
            [1, 9, 17, 25],
            [9, 17, 25, 33],
            [17, 25, 33, 41],
            [0, 8, 16, 24],
            [8, 16, 24, 32],
            [16, 24, 32, 40],
            [7, 15, 23, 31],
            [15, 23, 31, 39],
            [14, 22, 30, 38],
        ]
        self.playerTurn = player_turn
        self.binary = self._binary()
        self.id = self._convert_state_to_id()
        self.allowedActions = self._allowed_actions()
        self.isEndGame = self._check_for_end_game()
        self.value = self._get_value()
        self.score = self._get_score()

    def _allowed_actions(self):
        allowed = []
        for i in range(len(self.board)):
            if i >= len(self.board) - 7:
                if self.board[i] == 0:
                    allowed.append(i)
            else:
                if self.board[i] == 0 and self.board[i + 7] != 0:
                    allowed.append(i)

        return allowed

    def _binary(self):

        current_player_position = np.zeros(len(self.board), dtype=np.int)
        current_player_position[self.board == self.playerTurn] = 1

        other_position = np.zeros(len(self.board), dtype=np.int)
        other_position[self.board == -self.playerTurn] = 1

        position = np.append(current_player_position, other_position)

        return position

    def _convert_state_to_id(self):
        player1_position = np.zeros(len(self.board), dtype=np.int)
        player1_position[self.board == 1] = 1

        other_position = np.zeros(len(self.board), dtype=np.int)
        other_position[self.board == -1] = 1

        position = np.append(player1_position, other_position)

        state_id = ''.join(map(str, position))

        return state_id

    def _check_for_end_game(self):
        if np.count_nonzero(self.board) == 42:
            return 1

        for x, y, z, a in self.winners:
            if self.board[x] + self.board[y] + self.board[z] + self.board[a] == 4 * -self.playerTurn:
                return 1
        return 0

    def _get_value(self):
        # This is the value of the state for the current player
        # i.e. if the previous player played a winning move, you lose
        for x, y, z, a in self.winners:
            if self.board[x] + self.board[y] + self.board[z] + self.board[a] == 4 * -self.playerTurn:
                return -1, -1, 1
        return 0, 0, 0

    def _get_score(self):
        tmp = self.value
        return tmp[1], tmp[2]

    # takeAction method return a new game state, with the starting player’s piece at the bottom of the centre column.
    def take_action(self, action):
        new_board = np.array(self.board)
        new_board[action] = self.playerTurn

        new_state = GameState(new_board, -self.playerTurn)

        value = 0
        done = 0

        if new_state.isEndGame:
            value = new_state.value[0]
            done = 1

        return new_state, value, done

    def render(self, logger):
        for r in range(6):
            logger.info([self.pieces[str(x)] for x in self.board[7 * r: (7 * r + 7)]])
        logger.info('--------------')
