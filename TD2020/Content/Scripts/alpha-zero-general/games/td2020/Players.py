import numpy as np
import pygame

from games.td2020.src.config_file import *


class RandomPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board, player):
        a = np.random.randint(self.game.getActionSize())
        valids = self.game.getValidMoves(board, player)
        while valids[a] != 1:
            a = np.random.randint(self.game.getActionSize())
        return a


class HumanPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board, player):
        # display(board)
        print("----------------")
        valid = self.game.getValidMoves(board, player)
        for i in range(len(valid)):
            if valid[i]:
                action_into_arr_array = self.game.actionIntoArr(board, i)
                x = action_into_arr_array[0]
                y = action_into_arr_array[1]
                actor_index = action_into_arr_array[2]
                action_str = ALL_ACTIONS_INT[action_into_arr_array[3]]
                print(x, y, actor_index, action_str)
        print("----------------")
        while True:
            print("right click on canvas after writing event to resume action - this is temp until keyboard and mouse events are implemented")
            self._manage_input()

            a = ("1 " + input('type one of above actions\n')).split(" ")
            # convert to action index in valids array
            a = self.game.arrIntoAction(board, a)

            if valid[a]:
                break
            else:
                print('This action is invalid')

        return a

    def select_object(self):
        # select object by clicking on it - you can select only your objects
        # raise NotImplementedError()
        pass

    def set_action(self, actor):
        # set action to selected object like - move by arrow keys, build building with letters like qwertzui... create unit with letters like asdfghj, set enemy by CTRL + RMB clicking, attacking enemy by right clicking, etc
        # raise NotImplementedError()
        pass

    def _manage_input(self):
        while True:

            for event in pygame.event.get():
                # print(event)
                if event.type == pygame.QUIT:
                    pygame.quit()
                    raise SystemExit(0)
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_LEFT:
                        print("pressed left...")
                    if event.key == pygame.K_ESCAPE:
                        pygame.quit()
                        raise SystemExit(0)
                # handle mouse
                if event.type == pygame.MOUSEBUTTONUP:
                    lmb, rmb = 1, 3
                    if event.button == lmb:
                        print("clicked left")
                        object = self.select_object()

                    if event.button == rmb:
                        print("clicked right")

                        # return somewhere here when action is selected
                        return True
                    pos = pygame.mouse.get_pos()
                    print("clicked pos " + str(pos))


class GreedyPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board, player):
        valids = self.game.getValidMoves(board, player)
        candidates = []
        for a in range(self.game.getActionSize()):
            if valids[a] == 0:
                continue
            next_board, _ = self.game.getNextState(board, player, a)
            score = self.game.getScore(next_board, player)
            candidates += [(-score, a)]
        candidates.sort()
        return candidates[0][1]
