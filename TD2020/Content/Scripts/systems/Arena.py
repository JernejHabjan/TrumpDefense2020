import time
from typing import Tuple, List

from config_file import PIT_ARGS, TIMEOUT_TICKS
from games.td2020 import Game
from games.td2020.src import Board
from games.td2020.src.FunctionLibrary import action_into_array
from systems.misc.misc import AverageMeter
from systems.misc.progress.bar import Bar


class Arena:
    """
    An Arena class where any 2 agents can be pit against each other.
    """

    def __init__(self, player1: any, player2: any, game: 'Game.Game') -> None:  # cannot set player1, player2 function type
        """
        Input:
            player 1,2: two functions that takes board as input, return action
            game: Game object
            display: a function that takes board as input and prints it (e.g.
                     display in othello/Game). Is necessary for verbose
                     mode.

        see othello/Players.py for an example. See pit.py for pitting
        human players/other baselines with each other.
        """

        self.player1: function = player1
        self.player2: function = player2

        self.game: 'Game.Game' = game

    def _play_game(self, verbose: int = 0) -> float:
        """
        Executes one episode of a game.

        Returns:
            either
                winner: player who won the game (1 if player1, -1 if player2)
            or
                draw result returned from the game that is neither 1, -1, nor 0.
        """

        players: List[function, None, function] = [self.player2, None, self.player1]
        # set current player
        cur_player: int = 1

        # init new board
        board: 'Board.Board' = self.game.get_init_board
        # set iteration to 0
        it: int = 0

        # while game not ended

        while self.game.get_game_ended(board, cur_player) == 0:
            it += 1

            # draw game
            if verbose == 3 or verbose == 5:
                board.display()
                print("Turn", str(it), "Player ", str(cur_player))

            # function of player that takes board as input
            # executes function or method that player represents
            # human player -> <bound method HumanPlayer.play of <othello.OthelloPlayers.HumanPlayer object at ...>>
            # nnet player -> <function n1p at ....>
            funct: function = players[cur_player + 1]
            # retrieves action

            # import inspect
            # print("arena.py", "printing funct", inspect.getsource(funct))
            # function like this
            # def player1(x, player):
            #     return np.argmax(pmcts.get_action_prob(x, self.cur_player, temp=0))

            action: int = funct(board, cur_player)

            x, y, actor_index, action_int, action_str = action_into_array(board, action)
            x: int = x
            y: int = y
            actor_index: int = actor_index
            # noinspection PyUnusedLocal
            action_int: int = action_int
            action_str: str = action_str
            if verbose > 0:
                print("arena.py - action chosen", x, y, actor_index, action_str)

            # check if action is valid
            # valids = self.game.get_valid_moves_board(board, cur_player)
            # if valids[action] == 0:
            #    print("Arena", "ERROR ---- Action not in valids - algorithm may have chosen wrong side of board to play as his figures", action, "parsed action:", action_arr[0], action_arr[1], action_arr[2], ALL_ACTIONS_INT[action_arr[3]])

            # apply action
            board, cur_player = self.game.get_next_state(board, cur_player, action)
            board: 'Board.Board' = board
            cur_player: int = cur_player
        # draw game over
        game_ended: float = self.game.get_game_ended(board, 1)
        if verbose > 1:
            f = open("demofile.txt", "a")

            f.write("Game over: Turn " + str(it) + " Result " + str(game_ended) + '\n')
            f.close()
            print("Game over: Turn", str(it), "Result", str(game_ended))
            board.display()
        return game_ended

    def play_games(self, num: int, verbose: int = 0) -> Tuple[int, int, int]:
        """
        Plays num games in which player1 starts num/2 games and player2 starts
        num/2 games.

        Returns:
            one_won: games won by player1
            two_won: games won by player2
            draws:  games won by nobody
        """
        # speed meter
        eps_time: AverageMeter = AverageMeter()
        # bar to display how many games have been played
        bar: Bar = Bar('Arena.play_games', max=num)
        # another benchmark variable
        end: time = time.time()
        # num games
        eps: int = 0
        # max num games
        maxeps: int = int(num)

        num = int(num / 2)
        one_won: int = 0
        two_won: int = 0
        draws: int = 0
        # iterate through first half of games
        for _ in range(num):
            # play this single game
            game_result: float = self._play_game(verbose=verbose)
            print("Arena", "printing game result", game_result)
            # check who won - player 1 or 2
            if game_result == 1:
                one_won += 1
            elif game_result == -1:
                two_won += 1
            else:
                draws += 1
            # bookkeeping + plot progress
            eps += 1
            eps_time.update(time.time() - end)
            end: time = time.time()
            # update bar
            if PIT_ARGS.display_bar:
                bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}\n'.format(eps=eps + 1, maxeps=maxeps, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
                bar.next()
        # change players
        self.player1, self.player2 = self.player2, self.player1

        # iterate through second half of games
        for _ in range(num):
            game_result: float = self._play_game(verbose=verbose)
            if game_result == 1:
                one_won += 1
            elif game_result == -1:
                two_won += 1
            else:
                draws += 1
            # bookkeeping + plot progress
            eps += 1
            eps_time.update(time.time() - end)
            end: time = time.time()
            if PIT_ARGS.display_bar:
                bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}\n'.format(eps=eps + 1, maxeps=num, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
                bar.next()

        bar.finish()

        return one_won, two_won, draws
