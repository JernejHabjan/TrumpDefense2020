from config_file import LEARN_ARGS
from games.td2020.Game import Game
from games.td2020.keras.NNet import NNetWrapper as NNet
from systems.coach import Coach


class CoachWrapper:
    def __init__(self) -> None:
        self.game: Game = Game(LEARN_ARGS)
        self.nnet: NNet = NNet(self.game)

        self.load_model()
        self.coach()

    def load_model(self) -> None:
        if LEARN_ARGS.load_model:
            self.nnet.load_checkpoint(LEARN_ARGS.load_folder_file[0], LEARN_ARGS.load_folder_file[1])

    def coach(self) -> None:
        c: Coach = Coach(self.game, self.nnet, LEARN_ARGS)
        if LEARN_ARGS.load_model:
            print("Load trainExamples from file")
            c.load_train_examples()
        try:
            c.coach_learn()
        except RecursionError as e:
            raise Exception("Make sure you didn't set variable TIMEOUT_TICKS too high or chosen wrong config for learning -", e)


if __name__ == '__main__':
    CoachWrapper()
