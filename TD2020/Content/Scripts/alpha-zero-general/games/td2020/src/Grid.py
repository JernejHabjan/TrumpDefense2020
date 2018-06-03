from games.td2020.src.Actors import MyActor
import numpy as np


class Tile:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
        self.actors = []


class Grid:

    def __init__(self, width: int, height: int):
        # grid
        self.num = width * height
        self.width = width
        self.height = height
        self.tiles = [[Tile(x, y) for x in range(width)] for y in range(height)]

        # players
        self.players = dict()

        self.MAX_ACTORS_ON_TILE = 4  # Predefined so neural network can recieve fixed array
        self.ALL_ACTIONS = {"idle": 1, "up": 2, "down": 3, "right": 4, "left": 5, "mine_resources": 6, "return_resources": 7, "choose_enemy": 8, "attack": 9, "npc": 10,
                            "rifle_infantry": 11, "town_hall": 12, "barracks": 13, "sentry": 14, "mining_shack": 15, "continue_building": 16}

    def spawn_players(self):
        # spawn players

        from games.td2020.src.Player import Player
        self.players[-1] = Player(-1, self, 0, 0)
        self.players[1] = Player(1, self, self.width - 1, self.height - 1)

        # spawn after they are created, so buildings can add themselves to this world for this player
        self.players[-1].initial_spawn()
        self.players[1].initial_spawn()

    # add [][] indexer syntax to the Board
    def __getitem__(self, index):
        return self.tiles[index]

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
        for x in range(self.width):
            row = []
            for y in range(self.height):
                actors_in_tile = []
                actors = self[x][y].actors
                for i in range(self.MAX_ACTORS_ON_TILE):
                    actor = actors[i]  # now actor can be empty or it can consist of object MyActor...

                    valid_actions = [0] * len(self.ALL_ACTIONS)
                    for j, (action_str, action_int) in enumerate(self.ALL_ACTIONS.items()):
                        valid_actions[j] = actor.can_execute_action(action_str, self)
                    actors[i].append(valid_actions)
                row.append(actors_in_tile)
            columns.append(row)
        return columns

    def display_obj(self):
        # todo - make prefix of which team the piece is on board. If pieces of both teams are on same tile, make special suffix
        display_str = ["".join(["-----"] * self.width) + "\n"]

        for i in range(self.width):

            for j in range(self.height):

                tile = self[i][j]
                if np.size(tile.actors) > 1:

                    for actor in tile.actors:
                        display_str.append(str(actor.numeric_value))

                    display_str.extend([" "] * (self.MAX_ACTORS_ON_TILE - len(tile.actors)))

                elif np.size(tile.actors) == 1:
                    display_str.append(tile.actors[0].short_name)
                else:
                    display_str.append("    ")
                display_str.append("|")

            # print("".join(row_str))
            display_str.append("\n")
            if i < self.height:
                #    print( "".join(["-----"]*board.width))

                display_str.append("".join(["-----"] * self.width) + "\n")
        print("".join(display_str))
