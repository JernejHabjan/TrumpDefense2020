import json
import pandas as pd
from pandas.io.json import json_normalize
import numpy as np

from config_file import MAX_ACTORS_ON_TILE


def friendly(actor1, actor2):
    return actor1.player == actor2.player


def same_tile(actor1, actor2):
    return actor1.x == actor2.x and actor1.y == actor2.y


def dist(actor1, actor2):
    return np.sqrt((actor1.x - actor2.x) ** 2 + (actor1.y - actor2.y) ** 2)


def retrieve_json(filename, row_name=None):
    with open('games\\td2020\\datatables\\' + filename + '.json') as f:
        dict_train = json.load(f)
    # noinspection PyTypeChecker
    df = pd.DataFrame.from_dict(json_normalize(dict_train), orient='columns')
    if row_name:
        # print(df[df["Name"] == row_name])
        return df[df["Name"] == row_name]
    # print(df)
    return df


def get_valid_nearby_coordinates(world, x: int, y: int) -> list:
    # this function is also handling decision what coordinates to return with correlation to MAX_ACTORS_ON_TILE

    if MAX_ACTORS_ON_TILE > 1:
        return [(x, y)]

    coordinates = []
    if x - 1 >= 0 and y - 1 >= 0:
        coordinates.append((x - 1, y - 1))
    if y - 1 >= 0:
        coordinates.append((x, y - 1))
    if x + 1 < world.width and y - 1 >= 0:
        coordinates.append((x + 1, y - 1))

    if x - 1 >= 0:
        coordinates.append((x - 1, y))

    coordinates.append((x, y))
    if x + 1 < world.width:
        coordinates.append((x + 1, y))

    if x - 1 >= 0 and y + 1 < world.height:
        coordinates.append((x - 1, y + 1))
    if y + 1 < world.height:
        coordinates.append((x, y + 1))
    if x + 1 < world.width and y + 1 < world.height:
        coordinates.append((x + 1, y + 1))
    return coordinates


def can_add_unit(world, x: int, y: int, is_building: bool = False):
    for x, y in get_valid_nearby_coordinates(world, x, y):
        if is_building:
            from games.td2020.src.Actors import BuildingMaster
            # if building exists on this tile
            if any(isinstance(actor, BuildingMaster) for actor in world[x][y].actors):
                print("buildings already exist on this tile. Returning False")
                return False
        if len(world[x][y].actors) < MAX_ACTORS_ON_TILE:
            # found empty space - returning true
            return True
    # no empty space found
    return False


def get_nearest_empty_spawn(world, x_in: int, y_in: int) -> tuple:
    for x, y in get_valid_nearby_coordinates(world, x_in, y_in):
        if len(world[x][y].actors) < MAX_ACTORS_ON_TILE:
            return x, y
    return None, None


def get_nearest_instance_of_class(world, x_in: int, y_in: int, class_name, opts: str = None):
    # noinspection PyUnresolvedReferences
    from games.td2020.src.Actors import ResourcesMaster, Granite, TownHall, MiningShack, Barracks, Sentry, Character
    for x, y in get_valid_nearby_coordinates(world, x_in, y_in):
        for actor in world[x][y].actors:
            if issubclass(type(actor), class_name):
                if opts:
                    if eval(opts):
                        return actor
                else:
                    return actor
    return None
