from math import sqrt, ceil

import pygame
from numpy import size, clip


def message_display(game_display, text, position, text_size, color=(0, 0, 0)):
    large_text = pygame.font.Font('games\\td2020\\assets\\Cyberbit.ttf', text_size)
    text_surf = large_text.render(text, True, color)
    text_rect = text_surf.get_rect()
    text_rect.center = position
    game_display.blit(text_surf, text_rect)


def display_img(game_display, x, y):
    car_img = pygame.image.load('..\\assets\\racecar.jpg')
    game_display.blit(car_img, (x, y))


def init_visuals(world_width: int, world_height: int, verbose=True):
    if verbose:
        pygame.init()
        # square
        display_width, display_height = world_width * 100, world_height * 100  # for example 800

        game_display = pygame.display.set_mode((display_width, display_height))
        pygame.display.set_caption('TD2020 Python game')
        clock = pygame.time.Clock()

        return game_display, clock
    return None, None


def update_graphics(world, game_display, clock, fps: int = 1):
    from games.td2020.src.Actors import GeneralActor
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

    for tiles in world.tiles:
        for tile in tiles:
            num_actors = size(tile.actors)
            if num_actors == 0:
                continue

            num_in_row_column = ceil(sqrt(num_actors))
            actor_size = int((50 - 2 * border) / num_in_row_column)

            for index, _actor in enumerate(tile.actors):
                # print("DRAWING ACTOR " + str(type(_actor)))

                # offset if multiple actors are on same tile
                multiple_offset = int((100 / num_in_row_column) * index)

                actor: GeneralActor = _actor

                x = actor.x * 100 + int(multiple_offset % 100) + actor_size + border
                y = actor.y * 100 + int(multiple_offset / 100) * actor_size * 2 + actor_size + border

                actor_location = (x, y)

                actor_color = (actor.color["R"], actor.color["G"], actor.color["B"])

                from games.td2020.src.Actors import MyActor
                if isinstance(actor, MyActor):
                    production_percent = float(actor.current_production_time) / float(actor.production_time)  # value between 0 and 1
                    if production_percent != 1:
                        actor_color = (int(float(actor_color[0]) * production_percent + 25.5), int(float(actor_color[1]) * production_percent + 25.5), int(float(actor_color[2]) * production_percent + 25.5))

                pygame.draw.circle(game_display, actor_color, actor_location, actor_size)

                if isinstance(actor, MyActor):
                    if actor.player == -1:
                        player_color = (0, 255, 0)
                    else:
                        player_color = (255, 0, 0)
                    pygame.draw.circle(game_display, player_color, actor_location, actor_size, int(actor_size / 10))
                    production_percent = clip(float(actor.current_production_time) / float(actor.production_time), 0, 1)  # value between 0 and 1

                    if production_percent == 1:
                        message_display(game_display, u"" + actor.current_action, (x, int(y - actor_size / 2)), int(actor_size / 3))
                    else:

                        message_display(game_display, u"" + str(production_percent * 100) + "%", (x, int(y - actor_size / 2)), int(actor_size / 3),
                                        (int(255 - 255 * production_percent), int(255 - 255 * production_percent), int(255 - 255 * production_percent)))

                message_display(game_display, u"" + actor.short_name, actor_location, actor_size)

    pygame.display.update()

    clock.tick(fps)
