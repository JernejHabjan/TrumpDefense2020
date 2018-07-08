import os

from systems.utils import DotDict

MAX_ACTORS_ON_TILE = 1
CANVAS_SCALE = 100  # for drawing
BORDER = int(CANVAS_SCALE / 20)
SHOW_TENSORFLOW_GPU = True

PATH = os.path.expanduser('~\\TD2020\\saved_models\\')
# noinspection PyRedeclaration
PATH = './temp/'


# verbose: 0 - no output, 1 - basic learning output, 2 - output grid at end of game, 3 - output grid at end of each turn, 4 - output pygame at end of game, 5 - output pygame at end of each turn

NNET_ARGS = DotDict({
    'lr': 0.001,
    'dropout': 0.3,
    'epochs': 10,
    'batch_size': 128,
    'cuda': False,
    'num_channels': 512,
})


LEARN_ARGS = DotDict({
    'numIters': 2,
    'numEps': 2,
    'tempThreshold': 5,
    'updateThreshold': 0.6,
    'maxlenOfQueue': 200000,
    'numMCTSSims': 10,
    'arenaCompare': 2,
    'cpuct': 1,

    'checkpoint': './temp/',
    'load_model': False,
    'load_folder_file': ('./pretrained_models/othello/keras/', '6x6 checkpoint_145.pth.tar'),
    'numItersForTrainExamplesHistory': 20,

    'width': 8,
    'height': 8,
    'verbose': 3,
    'fps': 300,

})

PIT_ARGS = DotDict({
    'width': 8,
    'height': 8,
    'verbose': 4,
    'fps': 60,

    'numMCTSSims': 50,
    'cpuct': 1.0
})

GET_ACTION_ARGS = DotDict({
    'width': 8,
    'height': 8,
    'verbose': 0,
    'fps': 1,

    'numMCTSSims': 50,
    'cpuct': 1.0
})

WIN_CONDITION = 2

# 3 builders
if WIN_CONDITION == 1:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"npc": 19, "up": 11, "down": 12, "right": 13, "left": 14},
        'TIMEOUT_TICKS': 25,
        'PLAYER1WIN': 'len(board.players[1].actors) >= 10',
        'PLAYER2WIN': 'len(board.players[-1].actors) >= 10'
    })
# pick up minerals
elif WIN_CONDITION == 2:
    WIN_CONDITION_ARGS = DotDict({
        'ALL_ACTIONS': {"npc": 19, "up": 11, "down": 12, "right": 13, "left": 14,  "mine_resources": 15},
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

ALL_ACTIONS = WIN_CONDITION_ARGS.ALL_ACTIONS
ALL_ACTIONS_INT = dict((y, x) for x, y in ALL_ACTIONS.items())
ALL_ACTIONS_LEN = len(ALL_ACTIONS)
TIMEOUT_TICKS = WIN_CONDITION_ARGS.TIMEOUT_TICKS
PLAYER1WIN = WIN_CONDITION_ARGS.PLAYER1WIN
PLAYER2WIN = WIN_CONDITION_ARGS.PLAYER2WIN
