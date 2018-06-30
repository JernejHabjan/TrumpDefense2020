MAX_ACTORS_ON_TILE = 4  # Predefined so neural network can receive fixed array
ALL_ACTIONS = {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15, "return_resources": 16, "choose_enemy": 17, "attack": 18, "npc": 19, "rifle_infantry": 20, "town_hall": 21, "barracks": 22, "sentry": 23, "mining_shack": 24, "continue_building": 25}
# noinspection PyRedeclaration
ALL_ACTIONS = {"idle": 10, "npc": 19, "up": 11, "down": 12, "right": 13, "left": 14}

ALL_ACTIONS_INT = dict((y, x) for x, y in ALL_ACTIONS.items())

ALL_ACTIONS_LEN = len(ALL_ACTIONS)
TIMEOUT_TICKS: int = 10

CANVAS_SCALE = 100  # for drawing
BORDER = int(CANVAS_SCALE / 20)
SHOW_TENSORFLOW_GPU = True
