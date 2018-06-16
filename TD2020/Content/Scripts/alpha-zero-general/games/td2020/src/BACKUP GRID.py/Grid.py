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

        self.MAX_ACTORS_ON_TILE = 4  # Predefined so neural network can receive fixed array
        # self.ALL_ACTIONS = {"idle": 10, "up": 11, "down": 12, "right": 13, "left": 14, "mine_resources": 15, "return_resources": 16, "choose_enemy": 17, "attack": 18, "npc": 19, "rifle_infantry": 20, "town_hall": 21, "barracks": 22, "sentry": 23,
        #                     "mining_shack": 24, "continue_building": 25}
        # self.ALL_ACTIONS_INT = {10: "idle", 11: "up", 12: "down", 13: "right", 14: "left", 15: "mine_resources", 16: "return_resources", 17: "choose_enemy", 18: "attack", 19: "npc", 20: "rifle_infantry", 21: "town_hall", 22: "barracks", 23: "sentry",
        #                         24: "mining_shack", 25: "continue_building"}

        self.ALL_ACTIONS = {"idle": 10}
        self.ALL_ACTIONS_INT = {10: "idle"}



        self.iteration: int = 0  # game iteration
        self.timeout_ticks: int = 1000

        self.spawn_world(width, height)
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
        self.players[1] = Player(1, self, self.width - 2, self.height - 1)

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

        display_str = ["".join(["-" * (2 * self.MAX_ACTORS_ON_TILE + 1)] * self.width) + "\n"]

        for i in range(self.width):

            for j in range(self.height):

                tile = self[i][j]
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
            if i < self.height:
                display_str.append("".join(["-" * (2 * self.MAX_ACTORS_ON_TILE + 1)] * self.width) + "\n")
        print("".join(display_str))

    def timeout(self) -> bool:
        # returns boolean that returns true when game has timeouted
        if self.iteration > self.timeout_ticks:
            print("---> TIMEOUT <---")
            return True
        # update iteration
        self.iteration += 1
        return False
