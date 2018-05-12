import pandas as pd

from numpy import size

from games.TD2020.src.FunctionLibrary import retrieve_json


class AttackComponent:
    def __init__(self, name: str):
        from games.TD2020.src.FunctionLibrary import retrieve_json
        import pandas as pd

        # attack parameters
        self.td_attack: pd.DataFrame = retrieve_json('td_attack', name)
        self.cooldown = self.td_attack["Cooldown"].values[0]
        self.damage = self.td_attack["Damage.Class'/Script/Engine.DamageType'"].values[0]
        self.range = self.td_attack["Range"].values[0]
        self.acquisition_radius = self.td_attack["AcquisitionRadius"].values[0]
        self.critical_damage = self.td_attack["CriticalDamage.Class'/Script/Engine.DamageType'"].values[0]


class UnitProductionComponent:
    from games.TD2020.src.Actors import BuildingMaster

    def __init__(self, parent: BuildingMaster, unit_types: list):
        self.parent = parent
        self.unit_types = unit_types
        self.current_production_time: int = 0  # production time of current unit
        self.producing_units: list = []

    # produces unit by index from array
    def construct_unit(self, name):
        from games.TD2020.src.Actors import MyActor, NPC, RifleInfantry

        print("started constructing unit " + name)
        character_temp: MyActor = eval(name)(self.parent.player, name, self.parent.team_name,
                                             self.parent.tile)

        # get production cost of this actor
        td_my_actor: pd.DataFrame = retrieve_json('td_myactor', name)
        production_cost = td_my_actor["ProductionCost.BlueprintGeneratedClass'/Game/TD2020/Blueprints/Resources/Granite.Granite_C'"].values[0]
        if self.parent.player.money >= production_cost:
            # pay
            self.parent.player.money -= production_cost
            self.producing_units.append(character_temp)
        else:
            print("not enough money to start creating unit")
            del character_temp

    def update(self):
        # print("running unit production component update")
        if size(self.producing_units) <= 0:
            return

        if self.current_production_time >= self.producing_units[0].production_time:

            # print("finished updating unit production")
            # spawn character and reset timer
            character = self.producing_units.pop()
            # spawn character - by adding it to player
            self.parent.player.actors.append(character)
            # add to world tile
            self.parent.player.world_ref.world.tiles[self.parent.tile.location].actors.append(character)

        else:
            # print("continuing constructing unit " + str(type(self.producing_units[0])) + " with construction time " + str( self.current_production_time) + " of " + str(self.producing_units[0].production_time))

            self.current_production_time += 1


class ResourcesDepositComponent:
    pass
