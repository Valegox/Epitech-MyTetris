/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Handle too small window
*/

#include <curses.h>
#include "my_string.h"
#include "my_tetris.h"

int is_window_too_small(map_t *map)
{
    int game_width = 0;
    int game_height = 0;

    game_width = MAP_X + map->width;
    game_height = map->height > 22 ? map->height : 22;
    if (COLS < game_width || LINES < game_height) {
        endwin();
        my_throw_error("Please enlarge your terminal.\n");
        return 1;
    }
    return 0;
}
