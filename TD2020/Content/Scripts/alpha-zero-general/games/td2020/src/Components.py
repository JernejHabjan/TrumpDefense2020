from numpy import size
from games.td2020.src.Board import Board as Grid


class AttackComponent:
    def __init__(self, damage: int, attack_range: int):
        # attack parameters
        self.damage = damage
        self.range = attack_range


class UnitProductionComponent:
    from games.td2020.src.Actors import BuildingMaster

    def __init__(self, parent: BuildingMaster, unit_types: list):
        from games.td2020.src.Actors import BuildingMaster
        self.parent: BuildingMaster = parent
        self.unit_types = unit_types
        self.current_production_time: int = 0  # production time of current unit
        self.producing_units: list = []

    # produces unit by index from array
    def construct_unit(self, name, world: Grid):
        # noinspection PyUnresolvedReferences
        from games.td2020.src.Actors import MyActor, NPC, RifleInfantry

        # print("started constructing unit " + name)
        character: MyActor = eval(name)(self.parent.player, self.parent.x, self.parent.y)

        # get production cost of this actor

        # pay
        world.players[self.parent.player].money -= character.production_cost
        self.producing_units.append(character)

    def update(self, world: Grid):
        # print("running unit production component update")
        if size(self.producing_units) <= 0:
            return

        actor = self.producing_units[0]

        # print("continuing constructing unit " + str(type(self.producing_units[0])) + " with construction time " + str( self.current_production_time) + " of " + str(self.producing_units[0].production_time))

        actor.current_production_time += 1
        if actor.current_production_time >= actor.production_time:
            # print("finished updating unit production")
            # spawn character and reset timer
            character = self.producing_units.pop()
            character.current_production_time = character.production_time
            character.spawn(world)
            # print("new character spawned")


class ResourcesDepositComponent:
    # empty component
    pass
