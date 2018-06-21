import numpy as np
import pygame


class RandomPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board,player):
        a = np.random.randint(self.game.getActionSize())
        valids = self.game.getValidMoves(board, player)
        while valids[a] != 1:
            a = np.random.randint(self.game.getActionSize())
        return a


class HumanOthelloPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board,player):
        # display(board)
        valid = self.game.getValidMoves(board, player)
        for i in range(len(valid)):
            if valid[i]:
                print(int(i / self.game.n), int(i % self.game.n))
        while True:

            a = ("1 " + input('enter x, y, actor_index, action_int separated by space in format >a b c de<')).split(" ")
            a = a[1] + a[2] + a[3] + a[4]

            if valid[a]:
                break
            else:
                print('Invalid')

        return a

    def select_object(self):
        # select object by clicking on it - you can select only your objects
        raise NotImplementedError()

    def set_action(self, actor):
        # set action to selected object like - move by arrow keys, build building with letters like qwertzui... create unit with letters like asdfghj, set enemy by CTRL + RMB clicking, attacking enemy by right clicking, etc
        raise NotImplementedError()

    def _manage_input(self):  # TODO - create mouse and keyboard combination for selecting something and then executing action
        raise NotImplementedError()

        # TODO -add while loop and check for complete action there

        # noinspection PyUnreachableCode
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
                    object = self.select_object()

                if event.button == rmb:
                    print("clicked right")

                pos = pygame.mouse.get_pos()
                print("clicked pos " + str(pos))
        return True


class GreedyOthelloPlayer:
    def __init__(self, game):
        self.game = game

    def play(self, board,player):
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
