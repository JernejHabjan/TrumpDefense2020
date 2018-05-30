class GeneralActor:
    color = dict
    short_name = str

    def __init__(self, x: int, y: int):
        self.x: int = x
        self.y: int = y


class MyActor(GeneralActor):
    def __init__(self, player: int, x: int, y: int):
        super().__init__(x, y)

        self.player: int = player

        # variables - used as reference but they are just temp
        self.max_health = 1
        self.health = 1
        self.production_time: int = 0
        self.production_cost = 0
        self.value = 0
        self.short_name = "None"
        self.color = {"R": 255, "G": 0, "B": 0}
        self.current_production_time: int = 0  # amount that this building / character has been produced

        self.current_action = ""
        self.actions = ["idle"]

        from td2020.src.ActionManager import ActionManager
        self.action_manager = ActionManager(self, self.actions)

    def update(self, world, action: str):
        self.action_manager.execute_action(action, world)

    def __del__(self):
        pass
        # print("Actor destroyed")

    def spawn(self, world):
        # spawn character - by adding it to player
        world.players[self.player].actors.append(self)
        # add to world tile
        world[self.x][self.y].actors.append(self)


class BuildingMaster(MyActor):

    def __init__(self, player: int, x: int, y: int):
        # config variables

        super().__init__(player, x, y)


class TownHall(BuildingMaster):
    unit_types = ["NPC"]

    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)

        from td2020.src.Components import UnitProductionComponent
        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

        self.max_health = 400
        self.production_time: int = 10
        self.production_cost = 500
        self.value = 500
        self.short_name = "Hall"
        self.color = {"R": 235, "G": 255, "B": 0}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["npc"])

    def update(self, world, action: str):
        MyActor.update(self, world, action)
        self.unit_production_component.update(world)


class Barracks(BuildingMaster):
    unit_types = ["RifleInfantry"]

    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)
        from td2020.src.Components import UnitProductionComponent

        self.unit_production_component = UnitProductionComponent(self, self.unit_types)

        self.max_health = 150
        self.production_time: int = 5
        self.production_cost = 120
        self.value = 400
        self.short_name = "Barr"
        self.color = {"R": 255, "G": 156, "B": 255}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["rifle_infantry"])

    def update(self, world, action: str):
        MyActor.update(self, world, action)
        self.unit_production_component.update(world)


class MiningShack(BuildingMaster):
    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)
        from td2020.src.Components import ResourcesDepositComponent
        self.resources_deposit_component = ResourcesDepositComponent()
        self.max_health = 150
        self.production_time: int = 2
        self.production_cost = 100
        self.value = 150
        self.short_name = "Mine"
        self.color = {"R": 203, "G": 186, "B": 103}
        self.health = self.max_health * 0.1  # 10%


class Sentry(BuildingMaster):
    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)
        from td2020.src.Components import AttackComponent

        self.attack_component = AttackComponent(10, 2)
        self.max_health = 200
        self.production_time: int = 2
        self.production_cost = 100
        self.value = 100
        self.short_name = "Sent"
        self.color = {"R": 0, "G": 196, "B": 255}
        self.health = self.max_health * 0.1  # 10%
        self.actions.extend(["choose_enemy", "attack"])


class Character(MyActor):
    is_busy = False

    def __init__(self, player: int, x: int, y: int):
        # set health to max after spawn
        super().__init__(player, x, y)


class NPC(Character):
    gather_amount = 0  # currently holding resources
    max_gather_amount = 20  # max of how much can hold resources

    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)
        self.max_health = 20
        self.production_time: int = 1
        self.production_cost = 20
        self.value = 50
        self.short_name = "NPC "
        self.color = {"R": 0, "G": 165, "B": 208}

        self.health = self.max_health
        self.current_production_time = self.production_time
        self.actions.extend(["up", "down", "right", "left", "mine_resources", "return_resources", "town_hall", "barracks", "sentry", "mining_shack", "continue_building"])


class RifleInfantry(Character):
    def __init__(self, player: int, x: int, y: int):
        super().__init__(player, x, y)
        self.max_health = 35
        self.production_time: int = 2
        self.production_cost = 60
        self.value = 30
        self.short_name = "Rif "
        self.color = {"R": 152, "G": 0, "B": 136}
        self.health = self.max_health
        self.current_production_time = self.production_time

        from td2020.src.Components import AttackComponent
        self.attack_component = AttackComponent(10, 2)

        self.actions.extend(["up", "down", "right", "left", "choose_enemy", "attack"])


class ResourcesMaster(GeneralActor):
    def __init__(self, x: int, y: int, amount: int = 2000):
        super().__init__(x, y)
        self.amount = amount


class Granite(ResourcesMaster):

    def __init__(self, x: int, y: int):
        super().__init__(x, y)
        self.short_name = "Gran"
        self.color = {"R": 230, "G": 0, "B": 50}
        self.gather_amount: int = 20
