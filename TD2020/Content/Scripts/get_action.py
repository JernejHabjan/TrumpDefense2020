import threading
import numpy as np
from config_file import GET_ACTION_ARGS
from games.td2020.Game import Game
from games.td2020.tensorflow.NNet import NNetWrapper as NNet
from systems.MCTS import MCTS


def create_board(board):
    # todo fill board here from UE4 for both players and assign this AI player as player 1
    return 1


import time

start_time = time.time()

g = Game(GET_ACTION_ARGS)
board = g.getInitBoard()
# board = create_board(board)

# systems
m1 = None
mcts1 = None


def initNNet():
    n1 = NNet(g)
    print("--- %s seconds ---" % (time.time() - start_time))
    n1.load_checkpoint('./temp/', 'best.pth.tar')
    mcts1 = MCTS(g, n1, GET_ACTION_ARGS)


a_stop_event = threading.Event()

th1 = threading.Thread(target=initNNet, args=[a_stop_event])
th1.daemon = True
th1.start()

while not a_stop_event.is_set():
    # wait for an event
    time.sleep(0.1)

print("AFTER STOP EVENT")


# nnet player
def nnp(x, player): return np.argmax(mcts1.getActionProb(x, player, temp=0))


print("before  thread");


def threadfunc():
    start_time = time.time()
    best_action = nnp(board, 1)  # current player as player 1 - it depends on how you create board
    print("--- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    best_action = nnp(board, 1)
    print("--- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    best_action = nnp(board, 1)
    print("--- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    best_action = nnp(board, 1)
    print("--- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    best_action = nnp(board, 1)
    print("--- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    best_action = nnp(board, 1)
    print("--- %s seconds ---" % (time.time() - start_time))
    print("get_action.py", "printing best action:", best_action)
    # todo - do something with this best action


th = threading.Thread(target=threadfunc)
th.daemon = True
th.start()
print("after thread")
