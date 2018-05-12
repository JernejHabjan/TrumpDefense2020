import random
import pygame
from collections import defaultdict
from numpy import linspace, size

from games.TD2020.src.Graphics import init_visuals, update_graphics


class Game:
    # team names can include also multiple instances of team names- if there are two players with same team name,
    # both are appended to same team
    def __init__(self, team_names: list, timeout_ticks: int, visuals=True, world_size: int = 64, fps=1,
                 exit_after_end=True):

        from games.TD2020.src.Grid import Grid
        self.world = Grid(world_size)
        self.timeout_ticks = timeout_ticks
        self.players = defaultdict(list)
        self.iteration: int = 0  # game iteration
        # init

        # world objects are bound only to world grid, but player objects have tile location stored in player
        self.spawn_world(world_size)
        self.spawn_players(world_size, team_names)

        game_display, clock = init_visuals(world_size, visuals)
        self.start_tick(self.world, game_display, clock, visuals, fps, exit_after_end)

        # here end game occurred so check scoring who won
        for team in self.players.values():
            for player in team:
                for actor in player.actors:
                    print(type(actor).__name__)
                print(player.team_name + " got score of " + str(player.calculate_score()))
        print("game finished in " + str(self.iteration) + " turns.")

    @staticmethod
    def manage_input():
        for event in pygame.event.get():
            # print(event)
            if event.type == pygame.QUIT:
                return False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    print("pressed left...")
                if event.key == pygame.K_ESCAPE:
                    return False
            # handle mouse
            if event.type == pygame.MOUSEBUTTONUP:
                lmb, rmb = 1, 3
                if event.button == lmb:
                    print("clicked left")
                if event.button == rmb:
                    print("clicked right")

                pos = pygame.mouse.get_pos()
                print("clicked pos " + str(pos))
        return True

    def spawn_world(self, world_size: int):
        from games.TD2020.src.Actors import Granite
        # spawn granite
        self.world.tiles[int(world_size / 2)].actors.append(Granite(self.world.tiles[int(world_size / 2)]))

    def spawn_players(self, world_size: int, team_names: list):
        from games.TD2020.src.Player import Player

        spawn_padding: int = 4
        spawn_locations: list = linspace(spawn_padding, world_size - spawn_padding, size(team_names))
        for i, team_name in enumerate(team_names):
            spawn_location = int(spawn_locations[i])

            print("added player from " + team_name + " on spawn " + str(spawn_location))
            self.players[team_name].append(Player(self, team_name, self.world.tiles[spawn_location]))

    def manage_game_logic(self):

        from games.TD2020.src.Action import Action

        if self.timeout() or self.end_condition():
            return False

        # run tick on all actors
        for team in self.players.values():

            for player in team:
                print(" ______________ TEAM " + player.team_name + "_______________")
                for actor in player.actors:

                    actor.update()

                    # get enemy
                    enemy = None
                    for enemy_team in self.players.values():

                        for enemy_player in enemy_team:
                            if enemy_player != player:
                                if enemy_player.actors:
                                    enemy = random.choice(enemy_player.actors)

                    # end get enemy

                    if enemy:
                        action = Action(actor, enemy)

                        # choose random action
                        action.execute_action(random.choice(action.actions))

                    else:
                        print("Endgame - no enemy actors")
                        return False

        return True

    def start_tick(self, world, game_display, clock, visuals=True, fps=1, exit_after_end=True):

        crashed = False
        while not crashed:

            # game logic
            if not self.manage_game_logic():
                crashed = True

            if visuals:
                # input
                if not self.manage_input():
                    crashed = True
                # graphics
                update_graphics(world, game_display, clock, fps)
        if exit_after_end:
            pygame.quit()

    def end_condition(self):
        for team_name, players in self.players.items():
            for player in players:
                print("Player of team " + team_name + " has " + str(size(player.actors)) + " actors.")
                if not len(player.actors):
                    print("Player of team " + team_name + " lost")
                    print("---> GAME END <---")
                    return True
        return False

    def timeout(self):
        if self.iteration > self.timeout_ticks:
            print("---> TIMEOUT <---")
            return True
        # update iteration
        self.iteration += 1
        return False
