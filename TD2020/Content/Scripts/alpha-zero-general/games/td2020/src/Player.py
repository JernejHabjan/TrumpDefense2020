class Player:
    from td2020.src import Grid

    def __init__(self, name: int, world: Grid, start_x: int, start_y: int):
        from td2020.src import Grid
        self.world: Grid = world
        self.name: int = name
        self.start_x: int = start_x
        self.start_y: int = start_y

        # set variables
        self.money = 0
        self.actors = []

    def initial_spawn(self):
        from td2020.src.Actors import TownHall, RifleInfantry, MiningShack, NPC

        print("initial spawn")
        # spawn initial buildings and characters
        town_hall = TownHall(self.name, self.start_x, self.start_y)
        rifle_infantry = RifleInfantry(self.name, self.start_x, self.start_y)

        town_hall.health = town_hall.max_health
        # town_hall.current_production_time = town_hall.production_time


        mining_shack = MiningShack(self.name, self.start_x, self.start_y)
        mining_shack.health = mining_shack.max_health
        mining_shack.current_production_time = mining_shack.production_time
        npc = NPC(self.name, self.start_x, self.start_y)

        town_hall.spawn(self.world)
        # rifle_infantry.spawn(self.world)
        # mining_shack.spawn(self.world)
        npc.spawn(self.world)

    def calculate_score(self):
        # for actor in self.actors:
        #    print("actor of type" + str(type(actor)))
        return sum(actor.value for actor in self.actors)
