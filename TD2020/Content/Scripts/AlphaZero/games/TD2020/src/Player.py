

class Player:
    def __init__(self, world_ref, team_name: str, start_location):
        from games.TD2020.src.Grid import Tile
        from games.TD2020.src import Game

        self.world_ref: Game = world_ref
        self.team_name: str = team_name
        self.start_location: Tile = start_location


        # set variables
        self.money = 0
        self.actors = []

        # spawn
        self.initial_spawn()

    def initial_spawn(self):
        from games.TD2020.src.Actors import TownHall, RifleInfantry,MiningShack,NPC
        from numpy import size

        print("initial spawn")
        # spawn initial buildings and characters
        #town_hall = TownHall(self, "TownHall", self.team_name, self.start_location)
        #rifle_infantry = RifleInfantry(self, "RifleInfantry", self.team_name, self.start_location)
        #town_hall.health = town_hall.max_health
        #self.actors.append(town_hall)
        #self.actors.append(rifle_infantry)

        mining_shack = MiningShack(self, "MiningShack", self.team_name, self.start_location)
        mining_shack.health = mining_shack.max_health
        npc = NPC(self, "NPC", self.team_name, self.start_location)
        self.actors.append(mining_shack)
        self.actors.append(npc)

    def calculate_score(self):
        #for actor in self.actors:
        #    print("actor of type" + str(type(actor)))
        return sum(actor.value for actor in self.actors)


class HumanPlayer(Player):
    # TODO - add input here
    pass


class ComputerPlayer(Player):
    # TODO - add auto selecting for actions here
    pass
