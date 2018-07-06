import os

from systems.utils import DotDict

MAX_ACTORS_ON_TILE = 1
CANVAS_SCALE = 100  # for drawing
BORDER = int(CANVAS_SCALE / 20)
SHOW_TENSORFLOW_GPU = True

PATH = os.path.expanduser('~\\TD2020\\saved_models\\')
# noinspection PyRedeclaration
PATH = './temp/'

NNET_ARGS = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 10,
    'batch_size': 64,
    'cuda': False,
    'num_channels': 512,
})

# noinspection PyRedeclaration
NNET_ARGS = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 2,
    'batch_size': 8,
    'cuda': False,
    'num_channels': 512,
})

LEARN_ARGS = DotDict({
    'numIters': 100,
    'numEps': 100,
    'tempThreshold': 15,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 25,
    'arenaCompare': 30,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('/dev/models/8x100x50', 'best.pth.tar'),
    'numItersForTrainExamplesHistory': 20,

    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': False,
    'fps': 300,
})

# noinspection PyRedeclaration
LEARN_ARGS = DotDict({
    'numIters': 2,
    'numEps': 2,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 10,
    'arenaCompare': 4,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('./pretrained_models/othello/keras/', '6x6 checkpoint_145.pth.tar'),
    'numItersForTrainExamplesHistory': 20,

    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': False,
    'fps': 300,

})

# noinspection PyRedeclaration
LEARN_ARGS = DotDict({
    'numIters': 2,
    'numEps': 2,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 10,
    'arenaCompare': 20,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('./pretrained_models/othello/keras/', '6x6 checkpoint_145.pth.tar'),
    'numItersForTrainExamplesHistory': 20,

    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': False,
    'fps': 300,

})

PIT_ARGS = DotDict({
    'width': 8,
    'height': 8,
    'verbose': True,
    'draw_pygame': True,
    'fps': 60,

    'numMCTSSims': 50,
    'cpuct': 1.0
})

GET_ACTION_ARGS = DotDict({
    'width': 8,
    'height': 8,
    'verbose': False,
    'draw_pygame': False,
    'fps': 1,

    'numMCTSSims': 50,
    'cpuct': 1.0
})

WIN_CONDITION = 1

if WIN_CONDITION == 1:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"idle": 10, "npc": 19, "up": 11, "down": 12, "right": 13, "left": 14},
        'TIMEOUT_TICKS': 10,
        'PLAYER1WIN': 'len(board.players[1].actors) >= 3',
        'PLAYER2WIN': 'len(board.players[-1].actors) >= 3'
    })
elif WIN_CONDITION == 2:
    WIN_CONDITION_ARGS = DotDict({

    })
else:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15, "return_resources": 16, "choose_enemy": 17, "attack": 18, "npc": 19, "rifle_infantry": 20, "town_hall": 21, "barracks": 22, "sentry": 23, "mining_shack": 24, "continue_building": 25}
    })

ALL_ACTIONS = WIN_CONDITION_ARGS.ALL_ACTIONS
ALL_ACTIONS_INT = dict((y, x) for x, y in ALL_ACTIONS.items())
ALL_ACTIONS_LEN = len(ALL_ACTIONS)
TIMEOUT_TICKS = WIN_CONDITION_ARGS.TIMEOUT_TICKS
PLAYER1WIN = WIN_CONDITION_ARGS.PLAYER1WIN
PLAYER2WIN = WIN_CONDITION_ARGS.PLAYER2WIN
