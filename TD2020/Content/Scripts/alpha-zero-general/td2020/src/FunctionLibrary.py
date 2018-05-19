# coding=utf-8
#import json
#import pandas as pd
#from pandas.io.json import json_normalize


def friendly(actor1, actor2):
    return actor1.player == actor2.player


def same_tile(actor1, actor2):
    return actor1.x == actor2.x and actor1.y == actor2.y

#
#def retrieve_json(filename, row_name=None):
#    with open('..\\datatables\\' + filename + '.json') as f:
#        dict_train = json.load(f)
#    # noinspection PyTypeChecker
#    df = pd.DataFrame.from_dict(json_normalize(dict_train), orient='columns')
#
#    if row_name:
#        # print(df[df["Name"] == row_name])
#        return df[df["Name"] == row_name]
#    # print(df)
#    return df
