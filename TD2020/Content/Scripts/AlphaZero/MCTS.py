import numpy as np
import config
import loggers as lg


class Node:

    def __init__(self, state):
        self.state = state
        self.playerTurn = state.playerTurn
        self.id = state.id
        self.edges = []

    def is_leaf(self):
        if len(self.edges) > 0:
            return False
        else:
            return True


class Edge:

    def __init__(self, in_node, out_node, prior, action):
        self.id = in_node.state.id + '|' + out_node.state.id
        self.inNode = in_node
        self.outNode = out_node
        self.playerTurn = in_node.state.playerTurn
        self.action = action

        self.stats = {
            'N': 0,
            'W': 0,
            'Q': 0,
            'P': prior,
        }


class MCTS:

    def __init__(self, root, cpuct):
        self.root = root
        self.tree = {}
        self.cpuct = cpuct
        self.add_node(root)

    def __len__(self):
        return len(self.tree)

    def move_to_leaf(self):

        simulation_action = None
        simulation_edge = None

        lg.logger_mcts.info('------MOVING TO LEAF------')

        breadcrumbs = []
        current_node = self.root

        done = 0
        value = 0

        while not current_node.is_leaf():

            lg.logger_mcts.info('PLAYER TURN...%d', current_node.state.playerTurn)

            max_qu = -99999

            if current_node == self.root:
                epsilon = config.EPSILON
                nu = np.random.dirichlet([config.ALPHA] * len(current_node.edges))
            else:
                epsilon = 0
                nu = [0] * len(current_node.edges)

            nb = 0
            for action, edge in current_node.edges:
                nb = nb + edge.stats['N']

            for idx, (action, edge) in enumerate(current_node.edges):

                u = self.cpuct * ((1 - epsilon) * edge.stats['P'] + epsilon * nu[idx]) * np.sqrt(nb) / (1 + edge.stats['N'])

                q = edge.stats['Q']

                # lg.logger_mcts.info('action: %d (%d)... N = %d, P = %f, nu = %f, adjP = %f, W = %f, q = %f, u = %f, q+u = %f'
                # , action, action % 7, edge.stats['N'], round(edge.stats['P'],6), round(nu[idx],6), ((1-epsilon) * edge.stats['P'] + epsilon * nu[idx] )
                # , round(edge.stats['W'],6), round(q,6), round(u,6), round(q+u,6))

                if q + u > max_qu:
                    max_qu = q + u
                    simulation_action = action
                    simulation_edge = edge

            lg.logger_mcts.info('action with highest q + u...%d', simulation_action)

            # the value of the new_state from the POV of the new playerTurn
            new_state, value, done = current_node.state.take_action(simulation_action)
            current_node = simulation_edge.outNode
            breadcrumbs.append(simulation_edge)

        lg.logger_mcts.info('DONE...%d', done)

        return current_node, value, done, breadcrumbs

    @staticmethod
    def back_fill(leaf, value, breadcrumbs):
        lg.logger_mcts.info('------DOING BACKFILL------')

        current_player = leaf.state.playerTurn

        for edge in breadcrumbs:
            playerTurn = edge.playerTurn
            if playerTurn == current_player:
                direction = 1
            else:
                direction = -1

            edge.stats['N'] = edge.stats['N'] + 1
            edge.stats['W'] = edge.stats['W'] + value * direction
            edge.stats['Q'] = edge.stats['W'] / edge.stats['N']

            lg.logger_mcts.info('updating edge with value %f for player %d... N = %d, W = %f, Q = %f',
                                value * direction, playerTurn, edge.stats['N'], edge.stats['W'], edge.stats['Q']
                                )

            edge.outNode.state.render(lg.logger_mcts)

    def add_node(self, node):
        self.tree[node.id] = node
