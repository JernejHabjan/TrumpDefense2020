class Player:
    from games.td2020.TD2020Logic import Board as Grid

    def __init__(self, name: int, world: Grid, start_x: int, start_y: int):
        from games.td2020.TD2020Logic import Board as Grid
        self.world: Grid = world
        self.name: int = name
        self.start_x: int = start_x
        self.start_y: int = start_y

        # set variables
        self.money = 1000
        self.actors = []

    def initial_spawn(self):
        # self._character_initial_spawn("NPC", self.start_x, self.start_y)
        # self._character_initial_spawn("RifleInfantry", self.start_x, self.start_y)
        self._building_initial_spawn("TownHall", self.start_x, self.start_y)

        # self._building_initial_spawn("Barracks", self.start_x - 1, self.start_y)

    def _character_initial_spawn(self, name: str, x: int, y: int):
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import RifleInfantry, NPC
        character = eval(name)(self.name, x, y)
        character.spawn(self.world)

    def _building_initial_spawn(self, name: str, x: int, y: int):
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import TownHall, MiningShack, Barracks
        building = eval(name)(self.name, x, y)
        building.health = building.max_health
        building.current_production_time = building.production_time
        building.spawn(self.world)

    def calculate_score(self):
        # for actor in self.actors:
        #    print("actor of type" + str(type(actor)))
        return sum(actor.value for actor in self.actors)
