
class Tile:
    def __init__(self, location: int):
        self.location = location
        self.actors = []


class Grid:
    def __init__(self, num: int):
        self.num = num
        self.tiles = [Tile(i) for i in range(num)]

    def get_actors(self, location):
        return self.tiles[location].actors
