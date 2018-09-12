from typing import List

from games.td2020.src import Actors
from games.td2020.src import Board


class Player:

    def __init__(self, name: int, world: 'Board.Board', start_x: int, start_y: int) -> None:
        self.world: 'Board.Board' = world
        self.name: int = name
        self.start_x: int = start_x
        self.start_y: int = start_y

        # set variables
        self.money = 1000
        self.actors: List['Actors.MyActor'] = []

    def initial_spawn(self) -> None:
        # self._character_initial_spawn("NPC", self.start_x, self.start_y)
        # self._character_initial_spawn("RifleInfantry", self.start_x, self.start_y)
        self._building_initial_spawn("TownHall", self.start_x, self.start_y)

        # self._building_initial_spawn("Barracks", self.start_x - 1, self.start_y)

    def _character_initial_spawn(self, name: str, x: int, y: int) -> None:
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import RifleInfantry, NPC, Character
        character: Character = eval(name)(self.name, x, y)
        character.spawn(self.world, x, y)

    def _building_initial_spawn(self, name: str, x: int, y: int) -> None:
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import TownHall, MiningShack, Barracks, BuildingMaster, Sentry
        building: BuildingMaster = eval(name)(self.name, x, y)
        building.health = building.max_health
        building.current_production_time = building.production_time
        building.spawn(self.world, x, y)

    def calculate_score(self) -> int:
        # for actor in self.actors:
        #    print("actor of type" + str(type(actor)))
        return sum(actor.value for actor in self.actors)
