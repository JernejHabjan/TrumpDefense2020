from math import sqrt, ceil

import pygame
from numpy import size

from games.TD2020.src.Actors import GeneralActor
from games.TD2020.src.Player import Player


def message_display(game_display, text, position, size):
    large_text = pygame.font.Font('..\\assets\\Cyberbit.ttf', size)
    text_surf = large_text.render(text, True, (0, 0, 0))
    text_rect = text_surf.get_rect()
    text_rect.center = position
    game_display.blit(text_surf, text_rect)


def display_img(game_display, x, y):
    carImg = pygame.image.load('..\\assets\\racecar.jpg')
    game_display.blit(carImg, (x, y))


def init_visuals(world_size, visuals=True):
    if visuals:
        pygame.init()
        # square
        display_width = display_height = int(sqrt(world_size)) * 100  # for example 800

        game_display = pygame.display.set_mode((display_width, display_height))
        pygame.display.set_caption('TD2020 Python game')
        clock = pygame.time.Clock()

        return game_display, clock
    return None, None


def update_graphics(world, game_display, clock, fps: int = 1):
    # clear display
    global num_actors
    game_display.fill((255, 255, 255))
    # self.display_img(game_display, x,y)

    # draw grid:
    for i in range(100, 800, 100):
        pygame.draw.line(game_display, (0, 0, 0), [i, 0], [i, 800])
        for j in range(100, 800, 100):
            pygame.draw.line(game_display, (0, 0, 0), [0, j], [800, j])

    # draw objects
    border = 5
    for tile in world.tiles:
        num_actors = size(tile.actors)
        if num_actors == 0:
            continue

        num_in_row_column = ceil(sqrt(num_actors))
        actor_size = int((50 - 2 * border) / num_in_row_column)

        for index, _actor in enumerate(tile.actors):
            print("DRAWING ACTOR " + str(type(_actor)))

            pos_in_row_column = 100
            # offset if multiple actors are on same tile
            multiple_offset = int((100 / num_in_row_column) * index)

            actor: GeneralActor = _actor
            x = (actor.tile.location % 8) * pos_in_row_column + int(multiple_offset % 100) + actor_size + border

            y = int(actor.tile.location / 8) * pos_in_row_column + int(
                multiple_offset / 100) * actor_size * 2 + actor_size + border

            actor_location = (x, y)
            pygame.draw.circle(game_display, (actor.color["R"], actor.color["G"], actor.color["B"]), actor_location,
                               actor_size)
            message_display(game_display, u"" + actor.short_name, actor_location, actor_size)

    pygame.display.update()

    clock.tick(fps)
