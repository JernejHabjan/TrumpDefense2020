from typing import List

from numpy import asarray, size, array

from config_file import MAX_ACTORS_ON_TILE, ALL_ACTIONS_LEN, ALL_ACTIONS
from games.td2020.src import Actors
from systems.types import ActionEncoding


class Tile:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y
        self.actors: List['Actors.GeneralActor'] = []


class Board:

    def __init__(self, args) -> None:
        """
        initializes world tiles, sets game iteration to 0, spawns minerals and actors for both players
        :param args: DotDict of init game args
        """
        # get parameters
        self.width = args.width
        self.height = args.height
        self.fps = args.fps
        self.verbose = args.verbose

        # create grid
        self.tiles = [[Tile(x, y) for x in range(self.width)] for y in range(self.height)]

        # players
        self.players = dict()

        self.iteration: int = 0  # game iteration

        # spawn minerals on world on fixed positions
        from games.td2020.src.Actors import Granite
        # spawn granite
        granite = Granite(int(self.width / 2), int(self.height / 2))
        self[int(self.width / 2)][int(self.height / 2)].actors.append(granite)

        # spawn players on fixed positions (1,0 and width-1,height-1) and appends initial buildings to it
        from games.td2020.src.Player import Player
        self.players[1] = Player(1, self, 1, 0)
        self.players[-1] = Player(-1, self, self.width, self.height)

        # spawn after they are created, so buildings can add themselves to this world for this player
        self.players[-1].initial_spawn()
        self.players[1].initial_spawn()

    def __getitem__(self, index: int) -> List[Tile]:
        """
        [][] indexer syntax for the Board
        :param index:
        :return: tile at index
        """
        return self.tiles[index]

    @property
    def get_valid_moves_board(self) -> array(List[List[List[List[int]]]]):  # cannot put here ActionEncoding but that's what it is
        """
        :return: 1 if action is executable else 0, for every possible action and that for every actor and that for every field on grid.
            returns binary flat vector of same length as get_action_size
        """

        columns: ActionEncoding = []
        for y in range(self.height):
            row: List[List[List[int]]] = []
            for x in range(self.width):
                actors_in_tile: list = []
                actors: List[List[int]] = self[x][y].actors
                for i in range(MAX_ACTORS_ON_TILE):

                    valid_actions: List[int] = [0] * ALL_ACTIONS_LEN
                    if i < len(actors):
                        actor: 'Actors.MyActor' = actors[i]  # now actor can be empty or it can consist of object MyActor...

                        for j, (action_str, action_int) in enumerate(ALL_ACTIONS.items()):
                            if hasattr(actor, 'action_manager'):
                                valid_actions[j] = actor.action_manager.can_execute_action(action_str, self)
                            else:
                                valid_actions[j] = 0
                    actors_in_tile.append(valid_actions)
                row.append(actors_in_tile)
            columns.append(row)
        return asarray(columns)

    def display(self) -> None:
        from games.td2020.src.Graphics import init_visuals, update_graphics

        """
        prints current board state in console
        """
        if not self.verbose:
            return

        if self.verbose > 3:
            # Display using pygame
            # warning - do not assign pygame canvas to self as it cannot be later copied via deepcopy
            game_display, clock = init_visuals(self.width, self.height, self.verbose)
            update_graphics(self, game_display, clock, self.fps)
        else:
            display_str: list = []
            if MAX_ACTORS_ON_TILE == 1:
                display_str.append("\n" + "".join(["-" * 8] * (self.width + 1)) + "-\n|")
            else:
                display_str.append("\n" + "".join(["-" * (2 * MAX_ACTORS_ON_TILE + 1)] * self.width) + "-\n|")
            for y in range(self.height):
                for x in range(self.width):
                    tile: Tile = self[x][y]
                    if size(tile.actors) > 1:
                        for actor in tile.actors:
                            display_str.append((("+" if actor.player == 1 else "-") if hasattr(actor, "player") else "*") + str(actor.numeric_value))
                        display_str.extend(["  "] * (MAX_ACTORS_ON_TILE - len(tile.actors)))
                    elif size(tile.actors) == 1:
                        if MAX_ACTORS_ON_TILE == 1:
                            display_str.append(" " + (("+" if tile.actors[0].player == 1 else "-") if hasattr(tile.actors[0], "player") else " ") + tile.actors[0].short_name + "  ")
                        else:
                            display_str.append(" " + (("+" if tile.actors[0].player == 1 else "-") if hasattr(tile.actors[0], "player") else " ") + tile.actors[0].short_name + (" " * (MAX_ACTORS_ON_TILE * 2 - 6)))
                    else:
                        if MAX_ACTORS_ON_TILE == 1:
                            display_str.append(" " * 8)
                        else:
                            display_str.append("  " * MAX_ACTORS_ON_TILE)
                    display_str.append("|")
                display_str.append("\n")
                if y < self.height:
                    if MAX_ACTORS_ON_TILE == 1:
                        display_str.append("".join(["-" * 8] * (self.width + 1)) + "-\n")
                    else:
                        display_str.append("".join(["-" * (2 * MAX_ACTORS_ON_TILE + 1)] * self.width) + "-\n")
                if y < self.height - 1:
                    display_str.append("|")
            print("".join(display_str))
