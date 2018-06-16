import copy
import pygame
from games.td2020.src.Graphics import init_visuals, update_graphics


class Game:

    def __init__(self, timeout_ticks: int = 1000, visuals=False, world_width=8, world_height=8, fps=1, exit_after_end=True):

        self.current_player = 1  # set start to white player
        # create initial world
        from games.td2020.OthelloLogic import Board as Grid

        self.world_width = world_width
        self.world_height = world_height
        self.world: Grid = Grid(world_width, world_width)

        # init
        # world objects are bound only to world grid, but player objects have tile location stored in player
        self.spawn_world(world_width, world_height)
        self.world.spawn_players()
        self.world.timeout_ticks = timeout_ticks

        # init visuals if variable 'visuals' is true
        game_display, clock = init_visuals(world_width, world_height, visuals)

        # start game tick

        self._start_tick(game_display, clock, visuals, fps, exit_after_end)

        # here end game occurred so check scoring who won
        for player_name, player in self.world.players.items():

            for actor in player.actors:
                print(type(actor).__name__)
            print(str(player_name) + " got score of " + str(player.calculate_score()))
        print("game finished in " + str(self.world.iteration) + " turns.")

    @staticmethod
    def _manage_input():
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

    def spawn_world(self, world_width: int, world_height: int, ):
        from games.td2020.src.Actors import Granite
        # spawn granite
        granite = Granite(int(world_width / 2), int(world_height / 2))
        self.world[int(world_width / 2)][int(world_height / 2)].actors.append(granite)

    def manage_game_logic(self):
        # manages logic for single player - chooses actions for all players actors and executes them, updating world and assigning player to opposite player
        # iterates through world and if friendly actor is found there, update it - this may result in updating single actor multiple times, if actor is moved on tile that hasn't been iterated through
        if self.world.timeout() or self.end_condition(self.world):
            return False

        print(" ______________ TEAM " + str(self.current_player) + "_______________")

        import random
        from games.td2020.src.Actors import MyActor

        for x in range(self.world_width):
            for y in range(self.world_height):

                for actor_index in range(self.world.MAX_ACTORS_ON_TILE):

                    if actor_index < len(self.world[x][y].actors):
                        actor = self.world[x][y].actors[actor_index]
                        if issubclass(type(actor), MyActor) and actor.player == self.current_player:
                            # now this is our actor - we can execute action for this actor

                            action_int = self.world.ALL_ACTIONS[random.choice(actor.actions)]  # TODO - random for now

                            # prefix number 1, to prevent from trimming numbers
                            action = int("1" + str(actor.x) + str(actor.y) + str(actor_index) + str(action_int))
                            print(str(action))
                            # do not change current player here in for loop for this player
                            self.world, _ = self.getNextState(self.world, self.current_player, action)

        # change current player after finishing logic for this player
        self.current_player = -self.current_player

        return True

    def _start_tick(self, game_display, clock, visuals=True, fps=1, exit_after_end=True):
        crashed = False
        while not crashed:

            # game logic
            end_game = self.manage_game_logic()

            if not end_game:
                crashed = True

            if visuals:
                # input
                if not self._manage_input():
                    crashed = True
                # graphics
                update_graphics(self.world, game_display, clock, fps)
        if exit_after_end:
            pygame.quit()

    @staticmethod
    def end_condition(world):
        winner = None
        for player_name, player in world.players.items():
            if not len(player.actors):
                print("Player of team " + player_name + " lost")
                print("---> GAME END <---")
                winner = -player_name
                break
        return winner

    # ##################################################################################
    # ##################################################################################
    # ##################################################################################

    @staticmethod
    def getNextState(board, player: int, action: int):
        # create copy of old world and execute actions on new one
        from games.td2020.src.Grid import Grid

        new_world: Grid = copy.deepcopy(board)
        player = new_world.players[player]

        # beware that first value is random prefix (number 1) to prevent from trimming leading 0 when x position is 0
        action_arr = [int(digit) for digit in str(action)]
        x = int(action_arr[1])
        y = int(action_arr[2])
        actor_index = int(action_arr[3])

        action_str = board.ALL_ACTIONS_INT[int(str(action_arr[4]) + str(action_arr[5]))]

        actor = new_world[x][y].actors[actor_index]
        actor.update(new_world, action_str)

        return new_world, -player.name
