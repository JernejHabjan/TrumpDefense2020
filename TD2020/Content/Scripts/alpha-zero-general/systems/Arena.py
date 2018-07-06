import time
from games.td2020.Game import display as game_display
from config_file import *
# noinspection PyUnresolvedReferences
from systems.pytorch_classification.utils import Bar, AverageMeter


class Arena:
    """
    An Arena class where any 2 agents can be pit against each other.
    """

    def __init__(self, player1, player2, game, display=game_display):
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

        self.player1 = player1  # function
        self.player2 = player2  # function

        self.game = game
        self.display = display  # function

    def __playGame(self, verbose=False):
        """
        Executes one episode of a game.

        Returns:
            either
                winner: player who won the game (1 if player1, -1 if player2)
            or
                draw result returned from the game that is neither 1, -1, nor 0.
        """

        players = [self.player2, None, self.player1]
        # set current player
        cur_player = 1

        # init new board
        board = self.game.getInitBoard()
        # set iteration to 0
        it = 0

        # while game not ended
        while self.game.getGameEnded(board) == 0:
            it += 1
            # draw game
            if verbose:
                self.display(board)
                print("Turn", str(it), "Player ", str(cur_player))

            # function of player that takes board as input
            # executes function or method that player represents
            # human player -> <bound method HumanPlayer.play of <othello.OthelloPlayers.HumanPlayer object at ...>>
            # nnet player -> <function n1p at ....>
            funct = players[cur_player + 1]
            # retrieves action

            # import inspect
            # print("arena.py", "printing funct", inspect.getsource(funct))
            # function like this
            # def player1(x, player):
            #     return np.argmax(pmcts.getActionProb(x, self.curPlayer, temp=0))
            action = funct(board, cur_player)

            action_arr = self.game.actionIntoArr(board, action)
            if verbose:
                print("Arena.py - action chosen", action_arr[0], action_arr[1], action_arr[2], ALL_ACTIONS_INT[action_arr[3]])
            valids = self.game.getValidMoves(board, cur_player)

            # check if action is valid
            if valids[action] == 0:
                print("Arena", "ERROR ---- Action not in valids - algorithm may have chosen wrong side of board to play as his figures", action, "parsed action:", action_arr[0], action_arr[1], action_arr[2], ALL_ACTIONS_INT[action_arr[3]])

            # apply action
            board, cur_player = self.game.getNextState(board, cur_player, action)

        # draw game over
        if verbose:
            assert self.display
            print("Game over: Turn", str(it), "Result ", str(self.game.getGameEnded(board)))
            self.display(board)
        return self.game.getGameEnded(board)

    def playGames(self, num, verbose=False):
        """
        Plays num games in which player1 starts num/2 games and player2 starts
        num/2 games.

        Returns:
            one_won: games won by player1
            two_won: games won by player2
            draws:  games won by nobody
        """
        # speed meter
        eps_time = AverageMeter()
        # bar to display how many games have been played
        bar = Bar('Arena.playGames', max=num)
        # another benchmark variable
        end = time.time()
        # num games
        eps = 0
        # max num games
        maxeps = int(num)

        num = int(num / 2)
        one_won = 0
        two_won = 0
        draws = 0
        # iterate through first half of games
        for _ in range(num):
            # play this single game
            game_result = self.__playGame(verbose=verbose)
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
            end = time.time()
            # update bar
            bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}'.format(eps=eps + 1, maxeps=maxeps, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
            bar.next()
        # change players
        self.player1, self.player2 = self.player2, self.player1

        # iterate through second half of games
        for _ in range(num):
            game_result = self.__playGame(verbose=verbose)
            if game_result == -1:
                one_won += 1
            elif game_result == 1:
                two_won += 1
            else:
                draws += 1
            # bookkeeping + plot progress
            eps += 1
            eps_time.update(time.time() - end)
            end = time.time()
            bar.suffix = '({eps}/{maxeps}) Eps Time: {et:.3f}s | Total: {total:} | ETA: {eta:}'.format(eps=eps + 1, maxeps=num, et=eps_time.avg, total=bar.elapsed_td, eta=bar.eta_td)
            bar.next()

        bar.finish()

        return one_won, two_won, draws
