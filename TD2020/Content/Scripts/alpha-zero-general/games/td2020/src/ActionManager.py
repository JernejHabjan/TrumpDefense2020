from games.td2020.src.FunctionLibrary import friendly  # , retrieve_json, same_tile
from games.td2020.src.Grid import Grid


class ActionManager:

    def __init__(self, actor, actions):
        from games.td2020.src.Actors import MyActor

        self.actions = actions
        self.actor: MyActor = actor
        self.enemy_actor: MyActor = None

        self.ALL_ACTIONS = {"idle": 1, "up": 2, "down": 3, "right": 4, "left": 5, "mine_resources": 6, "return_resources": 7, "choose_enemy": 8, "attack": 9, "npc": 10,
                            "rifle_infantry": 11, "town_hall": 12, "barracks": 13, "sentry": 14, "mining_shack": 15, "continue_building": 16}
        # TODO - use this dictionary to map actions to numbers or other way around

    # ACTIONS

    def choose_enemy(self, world: Grid):
        my_player = self.actor.player
        # get enemy player here and his actors, then randomly or selectively choose one
        print("choosing enemy")

    def attack(self, world: Grid):

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

        self.actor.unit_production_component.construct_unit("NPC", world)

    def rifle_infantry(self, world: Grid):

        self.actor.unit_production_component.construct_unit("RifleInfantry", world)

    def town_hall(self, world: Grid):
        self._spawn_here("TownHall", world)

    def barracks(self, world: Grid):
        self._spawn_here("Barracks", world)

    def sentry(self, world: Grid):
        self._spawn_here("Sentry", world)

    def mining_shack(self, world: Grid):
        self._spawn_here("MiningShack", world)

    def up(self, world: Grid):

        self._execute_move(self.actor.x, self.actor.y - 1, world)

    def down(self, world: Grid):

        self._execute_move(self.actor.x, self.actor.y + 1, world)

    def right(self, world: Grid):

        self._execute_move(self.actor.x + 1, self.actor.y, world)

    def left(self, world: Grid):

        self._execute_move(self.actor.x - 1, self.actor.y, world)

    def idle(self, world: Grid):
        pass

    def mine_resources(self, world: Grid):

        from games.td2020.src.Actors import ResourcesMaster

        resource = None
        for actor in world[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break

        print("successfully mined resources")
        resource.amount -= resource.gather_amount
        self.actor.gather_amount += resource.gather_amount

    def return_resources(self, world: Grid):

        # add money
        world.players[self.actor.player].money += self.actor.gather_amount
        # reset gather amount
        self.actor.gather_amount = 0
        print("new money amount " + str(world.players[self.actor.player].money))

    def continue_building(self, world: Grid):  # continues building building for +1 time
        # get building to construct on this tile

        building = None
        for actor in world[self.actor.x][self.actor.y].actors:
            from games.td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster):
                # we found building on this tile
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    building = actor
                    break

        # continue building this building you are standing on
        print("CONTINUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE")
        building.current_production_time += 1
        # todo -increment health - to cover whole 100% when built to max - same as sc2

    def execute_action(self, action, world: Grid):
        if self.can_execute_action(action, world):
            self.actor.current_action = action
            print("Executing " + action + " by", type(self.actor).__name__)
            eval("self." + action + "(world)")

    # ACTION CHECKING

    def can_execute_action(self, action: str, world: Grid):
        production_percent = float(self.actor.current_production_time) / float(self.actor.production_time)  # value between 0 and 1
        if production_percent == 1:
            print("checking if action " + action + " can be executed...")
            can_execute = eval("self.can_" + action + "(world)")
            print("executed: " + str(can_execute))
            return can_execute
        else:
            print("cannot execute action - not constructed to max")
            return False

    def can_idle(self, world: Grid):
        return True

    def can_up(self, world: Grid):
        return self._can_execute_move(self.actor.x, self.actor.y - 1, world)

    def can_down(self, world: Grid):
        return self._can_execute_move(self.actor.x, self.actor.y + 1, world)

    def can_right(self, world: Grid):
        return self._can_execute_move(self.actor.x + 1, self.actor.y, world)

    def can_left(self, world: Grid):
        return self._can_execute_move(self.actor.x - 1, self.actor.y, world)

    def can_mine_resources(self, world: Grid):
        from games.td2020.src.Actors import ResourcesMaster
        # find if there are any resources on this location
        resource = None
        for actor in world[self.actor.x][self.actor.y].actors:

            if isinstance(actor, ResourcesMaster):
                resource = actor
                break
        # no resources found on this location - return

        from games.td2020.src.Actors import NPC
        return resource is not None and isinstance(self.actor, NPC) and self.actor.gather_amount < self.actor.max_gather_amount

    def can_return_resources(self, world: Grid):
        from games.td2020.src.Actors import NPC
        if not isinstance(self.actor, NPC):
            return False

        # find if there are any mines on this location
        resource_deposit_actor = None
        for actor in world[self.actor.x][self.actor.y].actors:
            if hasattr(actor, 'resources_deposit_component'):
                resource_deposit_actor = actor
                break
        # no mines found on this location - return

        return resource_deposit_actor is not None and friendly(resource_deposit_actor, self.actor)

    def can_choose_enemy(self, world: Grid):
        # TODO
        return True

    def can_attack(self, world: Grid):
        # check if enemy has been chosen:
        # check if we can attack
        return self.enemy_actor is not None and hasattr(self.actor, 'attack_component')

        # TODO -check if in range - beware that range is circular, but here im subtracting twho numbers in array
        # if(self.actor.attack_component.range < abs(self.actor.tile.location - self.other_actor.tile.location)):
        #    print("not in range")
        #    return

    def can_npc(self, world: Grid):
        from games.td2020.src.Actors import NPC
        character_temp = eval("NPC")(0, 0, 0)

        return hasattr(self.actor, 'unit_production_component') and world.players[self.actor.player].money >= character_temp.production_cost

    def can_rifle_infantry(self, world: Grid):
        from games.td2020.src.Actors import RifleInfantry
        character_temp = eval("RifleInfantry")(0, 0, 0)
        return hasattr(self.actor, 'unit_production_component') and world.players[self.actor.player].money >= character_temp.production_cost

    def can_town_hall(self, world: Grid):
        return self._can_spawn_here(world, "TownHall")

    def can_barracks(self, world: Grid):
        return self._can_spawn_here(world, "Barracks")

    def can_sentry(self, world: Grid):
        return self._can_spawn_here(world, "Sentry")

    def can_mining_shack(self, world: Grid):
        return self._can_spawn_here(world, "MiningShack")

    def can_continue_building(self, world: Grid):
        for actor in world[self.actor.x][self.actor.y].actors:
            from games.td2020.src.Actors import BuildingMaster
            if isinstance(actor, BuildingMaster):
                # we found building on this tile
                if actor.current_production_time < actor.production_time:
                    # we found a building on this tile that is not yet constructed
                    return True
        return False

    # HELPER METHODS
    def _execute_move(self, new_x: int, new_y: int, world: Grid):
        print("executing move action")

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

        world[self.actor.x][self.actor.y].actors.remove(self.actor)

        # add to new tile

        world[new_x][new_y].actors.append(self.actor)
        self.actor.x, self.actor.y = new_x, new_y

    def _spawn_here(self, name: str, world: Grid):  # spawns construction proxy
        if self._can_spawn_here(world, name):
            building = eval(name)(self.actor.player, self.actor.x, self.actor.y)
            # pay
            world.players[self.actor.player].money -= building.production_cost

            building.spawn(world)
            print("spawned new building - adding to player actors" + str(type(building)))

        else:
            print("not enough money")

    def _can_execute_move(self, new_x: int, new_y: int, world: Grid):
        from games.td2020.src.Actors import Character

        return 0 <= new_x < world.width and 0 <= new_y < world.height and issubclass(type(self.actor), Character)  # TODO - add here limit to 4 actors on tile

    def _can_spawn_here(self, world: Grid, name: str):
        from games.td2020.src.Actors import BuildingMaster, Barracks, TownHall, Sentry, MiningShack

        # check if here no buildings exist yet
        building_exists_on_tile = any(isinstance(actor, BuildingMaster) for actor in world[self.actor.x][self.actor.y].actors)

        if building_exists_on_tile:
            print("buildings already exist on this tile. Returning...")
            return False

        # get production cost of this

        building = eval(name)(self.actor.player, self.actor.x, self.actor.y)

        print("checking cost...")
        # check if we can pay for construction proxy
        return world.players[self.actor.player].money >= building.production_cost
