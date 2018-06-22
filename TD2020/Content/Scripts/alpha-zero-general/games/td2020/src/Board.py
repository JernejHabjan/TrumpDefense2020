"""
Author: Eric P. Nichols
Date: Feb 8, 2008.
Board class.
Board data:
  1=white, -1=black, 0=empty
  first dim is column , 2nd is row:
     pieces[1][7] is the square in column 2,
     at the opposite end of the board in row 8.
Squares are stored and manipulated as (x,y) tuples.
x is the column, y is the row.
"""

# noinspection PyUnresolvedReferences
from games.td2020.src.Actors import Granite, MyActor
from games.td2020.src.Graphics import init_visuals, update_graphics
from games.td2020.src.config_file import *
import numpy as np

from systems.utils import DotDict


class Tile:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
        self.actors = []


class Board:

    def __init__(self, args: DotDict):
        # get parameters
        self.draw_pygame = args.draw_pygame
        self.width = args.width
        self.height = args.height
        self.fps = args.fps
        self.verbose = args.verbose

        # create grid
        self.tiles = [[Tile(x, y) for x in range(self.width)] for y in range(self.height)]

        # players
        self.players = dict()

        self.iteration: int = 0  # game iteration

        self.spawn_world(self.width, self.height)
        self.spawn_players()

    # add [][] indexer syntax to the Board
    def __getitem__(self, index):
        return self.tiles[index]

    def spawn_world(self, world_width: int, world_height: int, ):
        from games.td2020.src.Actors import Granite
        # spawn granite
        granite = Granite(int(world_width / 2), int(world_height / 2))
        self[int(world_width / 2)][int(world_height / 2)].actors.append(granite)

    def spawn_players(self):
        # spawn players

        from games.td2020.src.Player import Player
        self.players[-1] = Player(-1, self, 1, 0)
        self.players[1] = Player(1, self, self.width - 1, self.height - 1)

        # spawn after they are created, so buildings can add themselves to this world for this player
        self.players[-1].initial_spawn()
        self.players[1].initial_spawn()

    def get_legal_moves_obj(self, color):
        moves = list()  # stores the legal moves.

        # Get all the squares with pieces of the given color.
        for y in range(self.height):
            for x in range(self.width):
                for actor in self[x][y].actors:
                    # check if it even is valid actor - for example not minerals and check if its not construction proxy
                    if isinstance(actor, MyActor) and actor.is_constructed():
                        if actor.player == color:
                            newmoves = str(x) + " " + str(y) + " " + actor.short_name + str(actor.actions)
                            moves.append(newmoves)
        return list(moves)

    def getValidMoves(self):
        # returns binary flat vector
        # same output length as getActionSize

        columns = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                actors_in_tile = []
                actors = self[x][y].actors
                for i in range(MAX_ACTORS_ON_TILE):
                    actor = actors[i]  # now actor can be empty or it can consist of object MyActor...

                    valid_actions = [0] * ALL_ACTIONS_LEN
                    for j, (action_str, action_int) in enumerate(ALL_ACTIONS.items()):
                        valid_actions[j] = actor.can_execute_action(action_str, self)
                    actors[i].append(valid_actions)
                row.append(actors_in_tile)
            columns.append(row)
        return columns

    def display(self):
        if not self.verbose:
            return

        display_str = ["\n" + "".join(["-" * (2 * MAX_ACTORS_ON_TILE + 1)] * self.width) + "-\n|"]
        for y in range(self.height):
            for x in range(self.width):
                tile = self[x][y]
                if np.size(tile.actors) > 1:
                    for actor in tile.actors:
                        display_str.append((("+" if actor.player == 1 else "-") if hasattr(actor, "player") else "*") + str(actor.numeric_value))
                    display_str.extend(["  "] * (MAX_ACTORS_ON_TILE - len(tile.actors)))
                elif np.size(tile.actors) == 1:
                    display_str.append("  " + tile.actors[0].short_name + "  ")
                else:
                    display_str.append("  " * MAX_ACTORS_ON_TILE)
                display_str.append("|")
            display_str.append("\n")
            if y < self.height:
                display_str.append("".join(["-" * (2 * MAX_ACTORS_ON_TILE + 1)] * self.width) + "-\n")
            if y < self.height - 1:
                display_str.append("|")
        print("".join(display_str))

        # Display using pygame
        # warning - do not assign pygame canvas to self as it cannot be later copied via deepcopy
        if self.draw_pygame:
            game_display, clock = init_visuals(self.width, self.height, self.verbose)
            update_graphics(self, game_display, clock, self.fps)

    def timeout(self) -> bool:

        if self.iteration > TIMEOUT_TICKS:
            # board has timeouted
            return True
        # update iteration
        self.iteration += 1
        return False
