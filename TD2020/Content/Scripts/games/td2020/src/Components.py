from numpy import size

from games.td2020.src import Actors
from games.td2020.src import Board


class AttackComponent:
    def __init__(self, damage: int, attack_range: int) -> None:
        # attack parameters
        self.damage = damage
        self.range = attack_range


class UnitProductionComponent:

    def __init__(self, parent: 'Actors.BuildingMaster', unit_types: list) -> None:
        self.parent: 'Actors.BuildingMaster' = parent
        self.unit_types = unit_types
        self.current_production_time: int = 0  # production time of current unit
        self.producing_units: list = []

    # produces unit by index from array
    def construct_unit(self, name, world: 'Board.Board') -> None:
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import MyActor, NPC, RifleInfantry

        # print("started constructing unit " + name)
        character: MyActor = eval(name)(self.parent.player, self.parent.x, self.parent.y)  # temp assign parent x,y to unit even if field after construction might be full (case of 1 Actor per tile)

        # get production cost of this actor

        # pay
        world.players[self.parent.player].money -= character.production_cost
        self.producing_units.append(character)

    def update(self, world: 'Board.Board') -> None:

        from games.td2020.src.FunctionLibrary import can_add_unit

        # print("running unit production component update")
        if size(self.producing_units) <= 0:
            return

        actor: 'Actors.MyActor' = self.producing_units[0]

        actor.current_production_time += 1
        if actor.current_production_time >= actor.production_time:
            # get actors on this tile check if we can spawn this unit here
            if can_add_unit(world, self.parent.x, self.parent.y):
                # print("finished updating unit production")
                # spawn character and reset timer
                character = self.producing_units.pop()
                character.current_production_time = character.production_time
                character.spawn(world, self.parent.x, self.parent.y)  # when spawning we are retrieving nearest free spot


class ResourcesDepositComponent:
    # empty component
    pass
