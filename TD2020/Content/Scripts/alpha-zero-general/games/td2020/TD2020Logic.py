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
import numpy as np


class Tile:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
        self.actors = []


class Board:

    def __init__(self, n: int):
        # grid
        self.num = n * n
        self.width = n
        self.height = n
        self.tiles = [[Tile(x, y) for x in range(n)] for y in range(n)]

        # players
        self.players = dict()

        self.MAX_ACTORS_ON_TILE = 4  # Predefined so neural network can receive fixed array
        self.ALL_ACTIONS = {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15, "return_resources": 16, "choose_enemy": 17, "attack": 18, "npc": 19, "rifle_infantry": 20, "town_hall": 21, "barracks": 22, "sentry": 23,
                            "mining_shack": 24, "continue_building": 25}
        self.ALL_ACTIONS = {"idle": 10, "npc": 19, "up": 11, "down": 12, "right": 13, "left": 14}

        self.ALL_ACTIONS_INT = dict((y, x) for x, y in self.ALL_ACTIONS.items())
        print("ALL ACTIONS INT", self.ALL_ACTIONS_INT)
        self.ALL_ACTIONS_LEN = len(self.ALL_ACTIONS)

        # self.ALL_ACTIONS = {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14}
        # self.ALL_ACTIONS_INT = {10: "idle", 11: "up", 12: "down", 13: "right", 14: "left"}

        self.iteration: int = 0  # game iteration
        self.timeout_ticks: int = 50

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
                for i in range(self.MAX_ACTORS_ON_TILE):
                    actor = actors[i]  # now actor can be empty or it can consist of object MyActor...

                    valid_actions = [0] * self.ALL_ACTIONS_LEN
                    for j, (action_str, action_int) in enumerate(self.ALL_ACTIONS.items()):
                        valid_actions[j] = actor.can_execute_action(action_str, self)
                    actors[i].append(valid_actions)
                row.append(actors_in_tile)
            columns.append(row)
        return columns

    def display_obj(self):

        display_str = ["".join(["-" * (2 * self.MAX_ACTORS_ON_TILE + 1)] * self.width) + "\n"]
        for y in range(self.height):
            for x in range(self.width):
                tile = self[x][y]
                if np.size(tile.actors) > 1:

                    for actor in tile.actors:
                        display_str.append((("+" if actor.player == 1 else "-") if hasattr(actor, "player") else "*") + str(actor.numeric_value))

                    display_str.extend(["  "] * (self.MAX_ACTORS_ON_TILE - len(tile.actors)))

                elif np.size(tile.actors) == 1:
                    display_str.append("  " + tile.actors[0].short_name + "  ")
                else:
                    display_str.append("  " * self.MAX_ACTORS_ON_TILE)
                display_str.append("|")

            # print("".join(row_str))
            display_str.append("\n")
            if y < self.height:
                display_str.append("".join(["-" * (2 * self.MAX_ACTORS_ON_TILE + 1)] * self.width) + "\n")
        print("".join(display_str))

    def timeout(self) -> bool:
        # print("checking timeout iteration ", self.iteration)
        # returns boolean that returns true when game timeouts

        print("this world has iteration ", self.iteration )

        if self.iteration > self.timeout_ticks:
            print("---> TIMEOUT <---")
            return True
        # update iteration
        self.iteration += 1
        return False
