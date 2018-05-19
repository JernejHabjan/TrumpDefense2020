import pandas as pd
from numpy import size

from td2020.src.FunctionLibrary import friendly  # , retrieve_json, same_tile
from td2020.src.Grid import Grid


class ActionManager:

    def __init__(self, actor,actions):
        from td2020.src.Actors import MyActor

        self.actions = actions
        self.actor: MyActor = actor
        self.enemy_actor: MyActor = None

    def choose_enemy(self, world: Grid):
        my_player = self.actor.player
        # get enemy player here and his actors, then randomly or selectively choose one
        print("choosing enemy")

    def execute_move(self, new_x: int, new_y: int, world: Grid):
        print("executing move action")

        if new_x < 0 or new_x >= world.width or new_y < 0 or new_y >= world.height:
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

        print("moving from ", self.actor.x, self.actor.y, " to new location", new_x, new_y)

        # remove from old tile

        print("removing from other tile...")

        # todo - checking if actor is in tile - this is redundant
        # if self.actor in world[self.actor.x][self.actor.y].actors:

        world[self.actor.x][self.actor.y].actors.remove(self.actor)

        # add to new tile

        world[new_x][new_y].actors.append(self.actor)
        self.actor.x, self.actor.y = new_x, new_y

    def attack(self, world: Grid):
        # check if enemy has been chosen:
        if not self.enemy_actor:
            return

        # check if we can attack
        if not hasattr(self.actor, 'attack_component'):
            return

        # TODO -check if in range - beware that range is circular, but here im subtracting twho numbers in array
        # if(self.actor.attack_component.range < abs(self.actor.tile.location - self.other_actor.tile.location)):
        #    print("not in range")
        #    return

        print("ATTACKING ENEMY " + str(type(self.enemy_actor)))

        enemy = self.enemy_actor
        if enemy.health > 0:
            # print("DAMAGE " + str(self.actor.attack_component.damage))
            # print("enemy health ->" + str(enemy.health) + " of max " + str(enemy.max_health))
            enemy.health -= self.actor.attack_component.damage

        # after damaging him check if he is dead
        if enemy.health <= 0:
            # print("ENEMY KILLED" + str(type(enemy)) + " of team " + enemy.player.team_name)

            # remove him
            world.players[enemy.player].actors.remove(enemy)
            if enemy in world[self.actor.x][self.actor.y].actors:
                world[enemy.x][enemy.y].actors.remove(enemy)
            del enemy

    def npc(self, world: Grid):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("NPC", world)

    def rifle_infantry(self, world: Grid):
        if hasattr(self.actor, 'unit_production_component'):
            self.actor.unit_production_component.construct_unit("RifleInfantry", world)

    def town_hall(self, world: Grid):
        self.spawn_here("TownHall", world)

    def barracks(self, world: Grid):
        self.spawn_here("Barracks", world)

    def sentry(self, world: Grid):
        self.spawn_here("Sentry", world)

    def mining_shack(self, world: Grid):
        self.spawn_here("MiningShack", world)

    # ACTIONS

    def up(self, world: Grid):
        from td2020.src.Actors import Character
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.x, self.actor.y - 1, world)

    def down(self, world: Grid):
        from td2020.src.Actors import Character
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.x, self.actor.y + 1, world)

    def right(self, world: Grid):
        from td2020.src.Actors import Character
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.x + 1, self.actor.y, world)

    def left(self, world: Grid):
        from td2020.src.Actors import Character
        if issubclass(type(self.actor), Character):
            self.execute_move(self.actor.x - 1, self.actor.y, world)

    def idle(self, world: Grid):
        pass

    def mine_resources(self, world: Grid):
        from td2020.src.Actors import ResourcesMaster
        # find if there are any resources on this location
        resource = None
        for actor in world[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break
        # no resources found on this location - return
        if not resource:
            return

        print("there are resources")
        from td2020.src.Actors import NPC
        if isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount:
            print("successfully mined resources")
            resource.amount -= resource.gather_amount
            self.actor.gather_amount += resource.gather_amount

    def return_resources(self, world: Grid):
        # find if there are any mines on this location
        mine = None
        for actor in world[self.actor.x][self.actor.y].actors:
            if hasattr(actor, 'resources_deposit_component'):
                mine = actor
                break
        # no mines found on this location - return
        if not mine:
            return
        from td2020.src.Actors import NPC
        if isinstance(self.actor, NPC) and friendly(mine, self.actor):
            print("resources returned")

            # add money
            world.players[self.actor.player].money += self.actor.gather_amount
            # reset gather amount
            self.actor.gather_amount = 0
            print("new money amount " + str(world.players[self.actor.player].money))

    def spawn_here(self, name: str, world: Grid):  # spawns construction proxy
        from td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack

        # check if here no buildings exist yet
        building_exists_on_tile = any(isinstance(actor, BuildingMaster) for actor in world[self.actor.x][self.actor.y].actors)

        if building_exists_on_tile:
            print("buildings already exist on this tile. Returning...")
            return

        # get production cost of this

        building = eval(name)(self.actor.player, self.actor.x, self.actor.y)

        print("checking cost...")
        # check if we can pay for construction proxy
        if world.players[self.actor.player].money >= building.production_cost:
            # pay
            world.players[self.actor.player].money -= building.production_cost

            building.spawn(world)
            print("spawned new building - adding to player actors" + str(type(building)))

        else:
            print("not enough money")
            del building

    def continue_building(self, world: Grid):  # continues building building for +1 time
        # get building to construct on this tile
        building = None
        for actor in world[self.actor.x][self.actor.y].actors:
            from td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster):
                # we found building on this tile
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    building = actor
                    break

        if not building:
            # no buildings found on this tile. Return
            return

        # continue building this building you are standing on
        print("CONTINUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE")
        building.current_production_time += 1
        # todo -increment health - to cover whole 100% when built to max - same as sc2

    def execute_action(self, action, world: Grid):
        if self.can_execute_action():

            self.actor.current_action = action
            print("Executing " + action + " by", type(self.actor).__name__)
            eval("self." + action + "(world)")



    def can_execute_action(self):
        production_percent = float(self.actor.current_production_time) / float(self.actor.production_time)  # value between 0 and 1
        if production_percent == 1:
            return True
        else:
            print("cannot execute action - not constructed to max")
        return False