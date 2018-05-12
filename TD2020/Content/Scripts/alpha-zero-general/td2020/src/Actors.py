import pandas as pd
from numpy import size


class GeneralActor:
    color = dict
    short_name = str

    def __init__(self, name: str, tile):
        from games.TD2020.src.Grid import Tile
        self.name = name
        self.tile: Tile = tile

class MyActor(GeneralActor):
    def __init__(self, player, name: str, team_name: str, tile):
        from games.TD2020.src import Player
        from games.TD2020.src.FunctionLibrary import retrieve_json

        super().__init__(name, tile)
        self.player: Player = player
        self.team_name = team_name
        # read td_myactor

        self.td_my_actor: pd.DataFrame = retrieve_json('td_myactor', name)
        self.max_health = self.td_my_actor["MaxHealth"].values[0]
        self.vision: int = self.td_my_actor["Vision"].values[0]
        self.production_time: int = self.td_my_actor["ProductionTime"].values[0]

        # self.production_cost = self.td_my_actor[ "ProductionCost.BlueprintGeneratedClass'/Game/TD2020/Blueprints/Resources/Granite.Granite_C'"].values[0]

        self.tech_requirements = self.td_my_actor["TechRequirements"].values[0]
        self.value = self.td_my_actor["Value"].values[0]
        self.short_name = self.td_my_actor["ShortName"].values[0]
        self.color = {"R": self.td_my_actor["Color.R"].values[0], "G": self.td_my_actor["Color.G"].values[0],"B": self.td_my_actor["Color.B"].values[0]}

        # variables
        self.current_production_time: int = 0  # amount that this building / character has been produced
        self.health = self.max_health * 0.1  # 10%





    def update(self):
        pass

    def __del__(self):
        pass
        # print("Actor destroyed")


class BuildingMaster(MyActor):

    def __init__(self, player, name: str, team_name: str, tile):
        super().__init__(player, name, team_name, tile)
        # config variables

        self.max_employees: int = self.td_my_actor["MaxEmployees"].values[0]
        self.max_residents: int = self.td_my_actor["MaxResidents"].values[0]
        self.max_build_amount: int = self.td_my_actor["MaxBuildAmount"].values[0]

        # add self to world tile
        self.player.world_ref.world.tiles[tile.location].actors.append(self)


class TownHall(BuildingMaster):
    unit_types = ["NPC"]

    def __init__(self, player, name: str, team_name: str, tile):
        from games.TD2020.src.Components import UnitProductionComponent

        super().__init__(player, name, team_name, tile)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

    def update(self):
        self.unit_production_component.update()


class Barracks(BuildingMaster):
    unit_types = ["RifleInfantry"]

    def __init__(self, player, name: str, team_name: str, tile):
        from games.TD2020.src.Components import UnitProductionComponent

        super().__init__(player, name, team_name, tile)
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

    def update(self):
        self.unit_production_component.update()


class MiningShack(BuildingMaster):
    def __init__(self, player, name: str, team_name: str, tile):
        super().__init__(player, name, team_name, tile)
        from games.TD2020.src.Components import ResourcesDepositComponent
        self.resources_deposit_component = ResourcesDepositComponent()


class Sentry(BuildingMaster):
    def __init__(self, player, name: str, team_name: str, tile):
        from games.TD2020.src.Components import AttackComponent
        super().__init__(player, name, team_name, tile)
        self.attack_component = AttackComponent(self.name)


class Character(MyActor):
    is_busy = False

    def __init__(self, player, name: str, team_name: str, tile):
        super().__init__(player, name, team_name, tile)
        # set health to max after spawn
        self.health = self.max_health


class NPC(Character):
    gather_amount = 0  # currently holding resources
    max_gather_amount = 20  # max of how much can hold resources

    def __init__(self, player, name: str, team_name: str, tile):
        super().__init__(player, name, team_name, tile)


class RifleInfantry(Character):
    def __init__(self, player, name: str, team_name: str, tile):
        from games.TD2020.src.Components import AttackComponent
        super().__init__(player, name, team_name, tile)
        self.attack_component = AttackComponent(self.name)


class ResourcesMaster(GeneralActor):
    def __init__(self, name: str, location, amount: int = 2000):
        from games.TD2020.src.FunctionLibrary import retrieve_json

        super().__init__(name, location)
        self.amount = amount
        self.td_resource: pd.DataFrame = retrieve_json('td_resource', self.name)
        self.gather_amount: int = self.td_resource["Capacity"].values[0]


class Granite(ResourcesMaster):

    def __init__(self, location):
        super().__init__("Granite", location, amount=2000)
        self.short_name = "Gran"
        self.color = {"R": 230, "G": 0, "B": 50}
