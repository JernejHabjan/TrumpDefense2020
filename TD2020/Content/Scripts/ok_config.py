import ctypes
import os
from typing import Dict

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
"""
NNET_ARGS: DotDict = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 5,
    'batch_size': 32,
    'cuda': True,
    'num_channels': 512, # connects with how many params model generates - does not get reduced by shrinking img with conv
    'fc1': 1024, # densely connected layer 1 ->
    'fc2': 512,
})
"""
NNET_ARGS: DotDict = DotDict({
    'lr': 0.01,
    'dropout': 0.5,
    'epochs': 2,
    'batch_size': 32,
    'cuda': True,
    'num_channels': 64,
    'fc1': 512,
    'fc2': 256,
})

LEARN_ARGS: DotDict = DotDict({
    'numIters': 20,
    'numEps': 5,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 30000, # it was before 200k, but i am memory swapping at 93k
    'numMCTSSims': 50,
    'arenaCompare': 8,
    'cpuct': 1, #cpuct is a hyperparameter controlling the degree of exploration

    'checkpoint': PATH + "\\temp\\",
    'checkpoint_file': 'temp.pth.tar',
    'best_file': 'best.pth.tar',
    'load_model': False,
    'load_folder_file': (PATH + "\\temp\\", 'checkpoint_2.pth.tar'), # it must have suffix with '.examples'
    'numItersForTrainExamplesHistory': 20,
    'skip_first_self_play': False, # this should be set to false, it is overwritten by load model

    'width': GRID_WIDTH,
    'height': GRID_HEIGHT,
    'verbose': 3,
    'fps': 300,

})

PIT_ARGS: DotDict = DotDict({
    'width': GRID_WIDTH,
    'height': GRID_HEIGHT,
    'verbose': 3,
    'fps': 60,

    'numMCTSSims': 10,
    'cpuct': 1.0,

    'display_bar': True,
    'parallel': True,
    'multiGPU': False,  # multiGPU only support 2 GPUs.
    'setGPU': '0',
    'numPlayGames': 4,  # total num should x2, because each process play 2 games.
    'numPlayPool': 4,  # num of processes pool.

    'model1Folder': PATH + "\\temp\\",
    'model1FileName': 'temp.pth.tar',
    'model2Folder': PATH + "\\temp\\",
    'model2FileName': 'temp.pth.tar'
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
        # 'ALL_ACTIONS': {"idle": 10, "npc": 19, "up": 11, "down": 12, "right": 13, "left": 14},
        'ALL_ACTIONS': {"npc": 19, "up": 11, "down": 12, "right": 13, "left": 14},
        'TIMEOUT_TICKS': 200,
        'PLAYER1WIN': 'len(board.players[1].actors) >= 10', # almost optimal for single player to have 10 actors is 25 moves (per player)
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

ALL_ACTIONS: Dict[str, int] = WIN_CONDITION_ARGS.ALL_ACTIONS
ALL_ACTIONS_INT: Dict[int, str] = dict((y, x) for x, y in ALL_ACTIONS.items())
ALL_ACTIONS_LEN: int = len(ALL_ACTIONS)
TIMEOUT_TICKS: int = WIN_CONDITION_ARGS.TIMEOUT_TICKS
PLAYER1WIN: str = WIN_CONDITION_ARGS.PLAYER1WIN
PLAYER2WIN: str = WIN_CONDITION_ARGS.PLAYER2WIN

if __name__ == '__main__':
    pass
