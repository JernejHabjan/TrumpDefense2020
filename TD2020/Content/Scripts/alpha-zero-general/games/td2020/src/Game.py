import copy
import pygame
from numpy import size

from td2020.src.Graphics import init_visuals, update_graphics


class Game:
    # team names can include also multiple instances of team names- if there are two players with same team name,
    # both are appended to same team
    def __init__(self, timeout_ticks: int = 1000, visuals=False, world_width=8, world_height=8, fps=1, exit_after_end=True):
        self.timeout_ticks = timeout_ticks
        self.current_player = 1  # set start to white player
        # create initial world
        from td2020.src.Grid import Grid

        self.world_width = world_width
        self.world_height = world_height
        self.world: Grid = Grid(world_width, world_width)

        # init
        # world objects are bound only to world grid, but player objects have tile location stored in player
        self.spawn_world(world_width, world_height)
        self.world.spawn_players()

        # init visuals if variable 'visuals' is true
        game_display, clock = init_visuals(world_width, world_height, visuals)

        # start game tick
        self.iteration: int = 0  # game iteration
        self.start_tick(game_display, clock, visuals, fps, exit_after_end)

        # here end game occurred so check scoring who won
        for player_name, player in self.world.players.items():

            for actor in player.actors:
                print(type(actor).__name__)
            print(str(player_name) + " got score of " + str(player.calculate_score()))
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

    def spawn_world(self, world_width: int, world_height: int, ):
        from td2020.src.Actors import Granite
        # spawn granite
        granite = Granite(int(world_width / 2), int(world_height / 2))
        self.world[int(world_width / 2)][int(world_height / 2)].actors.append(granite)

    def manage_game_logic(self):
        if self.timeout() or self.end_condition():
            return False

        # create copy of old world and execute actions on new one
        from td2020.src.Grid import Grid
        import random

        new_world: Grid = copy.deepcopy(self.world)
        player = new_world.players[self.current_player]
        print(" ______________ TEAM " + str(player.name) + "_______________")
        for actor in player.actors:
            action = random.choice(actor.actions)  # FOR NOW RANDOM

            actor.update(new_world, action)

        self.world, self.current_player = new_world, -player.name

        return True

    def manage_game_logic_COPY(self):  # TODO - THIS ONE USES GET NEXT STATE FUNCTION!!!!!
        if self.timeout() or self.end_condition():
            return False

        # create copy of old world and execute actions on new one
        from td2020.src.Grid import Grid
        new_world: Grid = copy.deepcopy(self.world)

        player = new_world.players[self.current_player]

        from td2020.src.ActionManager import ActionManager
        import random

        action = random.choice(ActionManager(None, []).actions)  # FOR NOW RANDOM

        self.world, self.current_player = self.getNextState(self.world, self.current_player, action)

        return True

    def start_tick(self, game_display, clock, visuals=True, fps=1, exit_after_end=True):
        crashed = False
        while not crashed:

            # game logic
            end_game = self.manage_game_logic()

            if not end_game:
                crashed = True

            if visuals:
                # input
                if not self.manage_input():
                    crashed = True
                # graphics
                update_graphics(self.world, game_display, clock, fps)
        if exit_after_end:
            pygame.quit()

    def end_condition(self):
        winner = None
        for player_name, player in self.world.players.items():
            if not len(player.actors):
                print("Player of team " + player_name + " lost")
                print("---> GAME END <---")
                winner = -player_name
                break
        return winner

    def timeout(self):
        if self.iteration > self.timeout_ticks:
            print("---> TIMEOUT <---")
            return True
        # update iteration
        self.iteration += 1
        return False

    # ##################################################################################
    # ##################################################################################
    # ##################################################################################

    def stringRepresentation(self, board):
        print("todo")  # todo

        # b'\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\xff\xff\xff\xff\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\xff\xff\xff\xff\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

        pass

    def getNextState(self, board, player, action):
        # create copy of old world and execute actions on new one
        from td2020.src.Grid import Grid

        new_world: Grid = copy.deepcopy(board)
        player = new_world.players[player]
        print(" ______________ TEAM " + str(player.name) + "_______________")
        for actor in player.actors:
            actor.update(new_world, action)
        return new_world, -player.name

    def getBoardSize(self):
        return self.world.height, self.world.width

    def getInitBoard(self):
        import numpy as np
        from td2020.src.Grid import Grid
        world = Grid(self.world_width, self.world_width)
        return np.array(world.tiles)  # Todo - is this correct -because these are objects not nubers as may be required in neural network or other functions in this project

    def getActionSize(self):
        # return number of actions
        return size(self.getValidMoves(self.world, self.world.players[self.current_player]))

    def getValidMoves(self, board, player):
        valid_moves = []

        for actor in player.actors:
            valid_moves.append(2)  # TODO ----- FOR NOW APPENDING 2 MOVES --- THIS IS WRONG -- im lazy atm... prestej kok potez lahko nardi posamezn od teh actorjev
        return valid_moves

    def getGameEnded(self, board, player):
        # 0 if game has not ended. 1 if player won, -1 if player lost, small non-zero value for draw.
        winner = self.end_condition()
        if winner:
            return winner
        if self.timeout():
            return 1e-4
        return 0

    def getCanonicalForm(self, board, player):
        """
        Input:
            board: current board
            player: current player (1 or -1)

        Returns:
            canonicalBoard: returns canonical form of board. The canonical form
                            should be independent of player. For e.g. in chess,
                            the canonical form can be chosen to be from the pov
                            of white. When the player is white, we can return
                            board as is. When the player is black, we can invert
                            the colors and return the board.
        """
        pass

    def getSymmetries(self, board, pi):
        """
        Input:
            board: current board
            pi: policy vector of size self.getActionSize()

        Returns:
            symmForms: a list of [(board,pi)] where each tuple is a symmetrical
                       form of the board and the corresponding pi vector. This
                       is used when training the neural network from examples.
        """
        pass
