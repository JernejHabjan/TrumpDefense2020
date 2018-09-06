import ctypes
import os

from systems.utils import DotDict

MAX_ACTORS_ON_TILE: int = 1
GRID_WIDTH: int = 8
GRID_HEIGHT: int = 8

CANVAS_SCALE: int = int(ctypes.windll.user32.GetSystemMetrics(1) * (2 / 3) / GRID_HEIGHT)  # for drawing - it takes 2 thirds of screen height
BORDER: int = int(CANVAS_SCALE / 20)
SHOW_TENSORFLOW_GPU: bool = False
SHOW_PYGAME_WELCOME: bool = False


PATH: str = os.path.dirname(os.path.realpath(__file__))

EPS: float = 1e-8  # for calculating U value in MCTS

# verbose: 0 - no output, 1 - basic learning output, 2 - output grid at end of game, 3 - output grid at end of each turn, 4 - output pygame at end of game, 5 - output pygame at end of each turn

NNET_ARGS: DotDict = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 5,
    'batch_size': 32,
    'cuda': True,
    'num_channels': 512,
})

LEARN_ARGS: DotDict = DotDict({
    'numIters': 2,
    'numEps': 2,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 3,
    'arenaCompare': 2,
    'cpuct': 1,

    'checkpoint': PATH + "\\temp\\",
    'checkpoint_file': 'temp.pth.tar',
    'best_file': 'best.pth.tar',
    'load_model': False,
    'load_folder_file': ('./pretrained_models/td2020/', 'model.pth.tar'),
    'numItersForTrainExamplesHistory': 20,

    'width': GRID_WIDTH,
    'height': GRID_HEIGHT,
    'verbose': 4,
    'fps': 300,

})

PIT_ARGS: DotDict = DotDict({
    'width': GRID_WIDTH,
    'height': GRID_HEIGHT,
    'verbose': 4,
    'fps': 60,

    'numMCTSSims': 10,
    'cpuct': 1.0
})

GET_ACTION_ARGS: DotDict = DotDict({
    'width': GRID_WIDTH,
    'height': GRID_HEIGHT,
    'verbose': 0,
    'fps': 10000,

    'numMCTSSims': 10,
    'cpuct': 1.0
})

_WIN_CONDITION: int = 1

# 3 builders
if _WIN_CONDITION == 1:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"idle": 10, "npc": 19, "up": 11, "down": 12, "right": 13, "left": 14},
        'TIMEOUT_TICKS': 25,
        'PLAYER1WIN': 'len(board.players[1].actors) >= 10',
        'PLAYER2WIN': 'len(board.players[-1].actors) >= 10'
    })
# pick up minerals
elif _WIN_CONDITION == 2:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"npc": 19, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15},
        'TIMEOUT_TICKS': 200,
        'PLAYER1WIN': 'any([hasattr(actor, "gather_amount") and actor.gather_amount > 0 for actor in board.players[1].actors])',
        'PLAYER2WIN': 'any([hasattr(actor, "gather_amount") and actor.gather_amount > 0 for actor in board.players[-1].actors])',
    })
else:
    # sandbox mode
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15, "return_resources": 16, "choose_enemy": 17, "attack": 18, "npc": 19, "rifle_infantry": 20, "town_hall": 21, "barracks": 22, "sentry": 23, "mining_shack": 24, "continue_building": 25},
        'TIMEOUT_TICKS': 10000,
        'PLAYER1WIN': 'len(board.players[-1].actors) == 0',
        'PLAYER2WIN': 'len(board.players[1].actors) == 0'
    })

ALL_ACTIONS: dict = WIN_CONDITION_ARGS.ALL_ACTIONS
ALL_ACTIONS_INT: dict = dict((y, x) for x, y in ALL_ACTIONS.items())
ALL_ACTIONS_LEN: int = len(ALL_ACTIONS)
TIMEOUT_TICKS: int = WIN_CONDITION_ARGS.TIMEOUT_TICKS
PLAYER1WIN = WIN_CONDITION_ARGS.PLAYER1WIN
PLAYER2WIN = WIN_CONDITION_ARGS.PLAYER2WIN

if __name__ == '__main__':
    pass