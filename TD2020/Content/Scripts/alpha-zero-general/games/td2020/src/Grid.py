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

    def spawn_players(self):
        # spawn players

        from td2020.src.Player import Player
        self.players[-1] = Player(-1, self, 0, 0)
        self.players[1] = Player(1, self, self.width - 1, self.height - 1)

        # spawn after they are created, so buildings can add themselves to this world for this player
        self.players[-1].initial_spawn()
        self.players[1].initial_spawn()

    # add [][] indexer syntax to the Board
    def __getitem__(self, index):
        return self.tiles[index]
