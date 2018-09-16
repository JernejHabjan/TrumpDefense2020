from typing import Dict, List

from games.td2020.src.Components import AttackComponent, ResourcesDepositComponent, UnitProductionComponent


class GeneralActor:
    """
    This is an actor that exists in world
    """

    def __init__(self, x: int, y: int) -> None:
        self.x: int = x
        self.y: int = y

        self.numeric_value: int = None  # value that is forwarded to neural network
        self.color: Dict[int, int, int] = None
        self.short_name: str = None


class MyActor(GeneralActor):
    """
    This is an actor that player can use
    """

    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(x, y)

        self.player: int = player

        # variables - used as reference but they are just temp
        self.max_health: int = None
        self.health: int = None
        self.production_time: int = None
        self.production_cost: int = None
        self.value: int = None
        self.current_production_time: int = 0  # amount that this building / character has been produced

        self.current_action: str = None
        self.actions: List[str] = ["idle"]

        from games.td2020.src.ActionManager import ActionManager
        self.action_manager: ActionManager = ActionManager(self, self.actions)

    def update(self, world, action: str) -> None:
        self.action_manager.execute_action(action, world)

    def spawn(self, world, x_in: int, y_in: int) -> None:
        from games.td2020.src.FunctionLibrary import get_nearest_empty_spawn

        self.x, self.y = get_nearest_empty_spawn(world, x_in, y_in)

        # spawn character - by adding it to player
        world.players[self.player].actors.append(self)
        # add to world tile
        world[self.x][self.y].actors.append(self)


class BuildingMaster(MyActor):

    def __init__(self, player: int, x: int, y: int) -> None:
        # config variables
        super().__init__(player, x, y)


class TownHall(BuildingMaster):

    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)

        self.unit_production_component = UnitProductionComponent(self, ["NPC"])
        self.resources_deposit_component = ResourcesDepositComponent()
        self.max_health: int = 400
        self.production_time: int = 10
        self.production_cost: int = 500
        self.value: int = 500
        self.short_name = "Hall"
        self.color: dict = {"R": 235, "G": 255, "B": 0}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["npc"])
        self.numeric_value = 1

    def update(self, world, action: str) -> None:
        MyActor.update(self, world, action)
        self.unit_production_component.update(world)


class Barracks(BuildingMaster):
    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(player, x, y)

        self.unit_production_component: UnitProductionComponent = UnitProductionComponent(self, ["RifleInfantry"])

        self.max_health = 150
        self.production_time: int = 5
        self.production_cost = 120
        self.value = 400
        self.short_name = "Barr"
        self.color = {"R": 255, "G": 156, "B": 255}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["rifle_infantry"])
        self.numeric_value = 2

    def update(self, world, action: str) -> None:
        MyActor.update(self, world, action)
        self.unit_production_component.update(world)


class MiningShack(BuildingMaster):
    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(player, x, y)
        self.resources_deposit_component = ResourcesDepositComponent()
        self.max_health = 150
        self.production_time: int = 2
        self.production_cost = 100
        self.value = 150
        self.short_name = "Mine"
        self.color = {"R": 203, "G": 186, "B": 103}
        self.health = self.max_health * 0.1  # 10%
        self.numeric_value = 3


class Sentry(BuildingMaster):
    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(player, x, y)

        self.attack_component = AttackComponent(10, 2)
        self.max_health = 200
        self.production_time: int = 2
        self.production_cost = 100
        self.value = 100
        self.short_name = "Sent"
        self.color = {"R": 0, "G": 196, "B": 255}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["choose_enemy", "attack"])
        self.numeric_value = 4


class Character(MyActor):
    def __init__(self, player: int, x: int, y: int) -> None:
        # set health to max after spawn
        super().__init__(player, x, y)


class NPC(Character):
    gather_amount: int = 0  # currently holding resources
    max_gather_amount: int = 20  # max of how much can hold resources

    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(player, x, y)
        self.max_health = 20
        self.production_time: int = 10
        self.production_cost = 20
        self.value = 50
        self.short_name = "Work"
        self.color = {"R": 0, "G": 165, "B": 208}

        self.health = self.max_health
        self.current_production_time = self.production_time
        self.actions.extend(["up", "down", "right", "left", "mine_resources", "return_resources", "town_hall", "barracks", "sentry", "mining_shack", "continue_building"])
        self.numeric_value = 5


class RifleInfantry(Character):
    def __init__(self, player: int, x: int, y: int) -> None:
        super().__init__(player, x, y)
        self.max_health = 35
        self.production_time: int = 20
        self.production_cost = 60
        self.value = 30
        self.short_name = "Rifl"
        self.color = {"R": 152, "G": 0, "B": 136}
        self.health = self.max_health
        self.current_production_time = self.production_time

        self.attack_component = AttackComponent(10, 2)

        self.actions.extend(["up", "down", "right", "left", "choose_enemy", "attack"])
        self.numeric_value = 6


class ResourcesMaster(GeneralActor):
    """
    Child of general actor that represents some type of resource in world
    """

    def __init__(self, x: int, y: int, amount: int = 2000) -> None:
        super().__init__(x, y)
        self.amount = amount


class Granite(ResourcesMaster):

    def __init__(self, x: int, y: int) -> None:
        super().__init__(x, y)
        self.short_name = "Gold"
        self.color = {"R": 230, "G": 0, "B": 50}
        self.gather_amount: int = 20
        self.numeric_value = 0.0001 # THEY MUST NOT HAVE VALUE OF 0 BECUASE THEN THEY LOOK INVISIBLE
