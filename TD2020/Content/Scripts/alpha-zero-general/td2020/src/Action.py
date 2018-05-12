import pandas as pd
from numpy import size

from games.TD2020.src.Actors import Character, NPC, MyActor, ResourcesMaster
from games.TD2020.src.FunctionLibrary import friendly, retrieve_json
from games.TD2020.src.Grid import Tile


class Action:
    def __init__(self, actor: MyActor, enemy_actor: MyActor):
        # print("init")
        #
        self.actions = ["idle", "up", "down", "right", "left", "mine_resources", "return_resources", "attack", "npc",
                        "rifle_infantry", "town_hall", "barracks", "sentry", "mining_shack", "continue_building"]
        # self.actions = ["idle", "up", "down", "right", "left", "mine_resources", "return_resources", "npc" , "mining_shack"]

        self.actor: MyActor = actor
        self.enemy_actor: MyActor = enemy_actor

        # print("printing loc" + str(self.actor.tile))
        print("NEW ACTION BY " + actor.name)

    def execute_move(self, new_location: int):
        print("executing move action")
        max_tile = self.actor.player.world_ref.world.num
        if new_location < 0 or new_location >= max_tile:
            print("invalid move")
            return

        """
        actors = self.actor.player.world_ref.world.get_actors(new_location)
        for actor in actors:
            if friendly(self.actor, actor): # TODO- ---- TODO NE DELA -- LOOPING
                print("moving to friendly")
                # move it there
                self.actor.player.world_ref.world.tiles[new_location].actors.append(self.actor)
                self.actor.tile =  self.actor.player.world_ref.world.tiles[new_location]
            # if not friendly
            else:
                print("moving to enemy - attack")
                self.attack()

        else:
            print("moving to new location", new_location)

            # remove from old tile
            tile: Tile = self.actor.tile
            if self.actor in tile.actors:
                print("removed from other tile")
                tile.actors.remove(self.actor)

            # add to new tile

            self.actor.player.world_ref.world.tiles[new_location].actors.append(self.actor)
            self.actor.tile = self.actor.player.world_ref.world.tiles[new_location]
        """

        # MAYBE ONLY MOVE AND NOT CHECK IF THERE IS ALREADY ENEMY OR FRIENDLY

        print("moving to new location", new_location)

        # remove from old tile
        tile: Tile = self.actor.tile
        if self.actor in tile.actors:
            print("removed from other tile")
            tile.actors.remove(self.actor)

        # add to new tile

        self.actor.player.world_ref.world.tiles[new_location].actors.append(self.actor)
        self.actor.tile = self.actor.player.world_ref.world.tiles[new_location]

    def attack(self):

        # check if we can attack
        if not hasattr(self.actor, 'attack_component'):
            return

        # TODO -check if in range - beware that range is circular, but here im subtracting twho numbers in array
        # if(self.actor.attack_component.range < abs(self.actor.tile.location - self.other_actor.tile.location)):
        #    print("not in range")
        #    return

        # print("ATTACKING ENEMY " + self.other_actor.name)

        enemy = self.enemy_actor
        if enemy.health > 0:
            # print("DAMAGE " + str(self.actor.attack_component.damage))
            # print("enemy health ->" + str(enemy.health) + " of max " + str(enemy.max_health))
            enemy.health -= self.actor.attack_component.damage

        # after damaging him check if he is dead
        if enemy.health <= 0:
            # print("ENEMY KILLED" + str(type(enemy)) + " of team " + enemy.player.team_name)

            # remove him
            enemy.player.actors.remove(enemy)
            enemy.tile.actors.remove(enemy)
            del enemy

            # check if maybe it was last building
            self.actor.player.world_ref.end_condition()

    def npc(self):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("NPC")

    def rifle_infantry(self):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("RifleInfantry")

    def town_hall(self):
        self.spawn_here("TownHall")

    def barracks(self):
        self.spawn_here("Barracks")

    def sentry(self):
        self.spawn_here("Sentry")

    def mining_shack(self):
        self.spawn_here("MiningShack")

    # ACTIONS

    def up(self):
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.tile.location + 8)

    def down(self):
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.tile.location - 8)

    def right(self):
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.tile.location + 1)

    def left(self):
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.tile.location - 1)

    def idle(self):
        pass

    def mine_resources(self):
        # find if there are any resources on this location
        resource = None
        for actor in self.actor.tile.actors:
            if isinstance(actor, ResourcesMaster):
                resource = actor
                break
        # no resources found on this location - return
        if not resource:
            return

        print("there are resources")

        if isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount:
            print("successfully mined resources")
            resource.amount -= resource.gather_amount
            self.actor.gather_amount += resource.gather_amount

    def return_resources(self):
        # find if there are any mines on this location
        mine = None
        for actor in self.actor.tile.actors:
            if hasattr(actor, 'resources_deposit_component'):
                mine = actor
                break
        # no mines found on this location - return
        if not mine:
            return

        if isinstance(self.actor, NPC) and friendly(mine, self.actor):
            print("resources returned")

            # add money
            self.actor.player.money += self.actor.gather_amount
            # reset gather amount
            self.actor.gather_amount = 0
            print("new money amount " + str(self.actor.player.money))

    def spawn_here(self, name: str):  # spawns construction proxy
        from games.TD2020.src.Actors import BuildingMaster

        # check if here no buildings exist yet
        building_exists_on_tile = any(isinstance(actor, BuildingMaster) for actor in self.actor.tile.actors)
        print("ACTORS HERE" + str(size(self.actor.tile.actors)) + " exists " + str(building_exists_on_tile))
        if building_exists_on_tile:
            return

        # get production cost of this actor
        td_my_actor: pd.DataFrame = retrieve_json('td_myactor', name)
        production_cost = 10
        # check if we can pay for construction proxy
        if self.actor.player.money >= production_cost:
            # pay
            self.actor.player.money -= production_cost

            building = eval(name)(self.actor.player, name, self.actor.team_name, self.actor.tile)
            print("checking spawn here location class" + str(type(self.actor.tile)))

            print("spawned new building - adding to player actors" + str(type(building)))
            self.actor.player.actors.append(building)
        else:
            print("not enough money")

    def continue_building(self):  # continues building building for +1 time
        building = self.enemy_actor
        if self.actor.tile == building.tile:
            if building.current_production_time < building.production_time:
                building.current_production_time += 1
                # todo -increment health - to cover whole 100% when built to max - same as sc2

    def execute_action(self, action):
        print("Executing " + action)
        eval("self." + action + "()")
