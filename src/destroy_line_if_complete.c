/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Destroy line if complete
*/

#include <curses.h>
#include "my_tetris.h"

void destroy_line(map_t *map, int pos_y)
{
    int color = 0;

    for (int y = pos_y - 1; y > 1; y--) {
        for (int x = MAP_X + 1; x < MAP_X + 1 + map->width; x++) {
            color = mvinch(y, x) & A_COLOR;
            attron(color);
            mvprintw(y + 1, x, "%c", (mvinch(y, x) & A_CHARTEXT));
            attroff(color);
        }
    }
}

void destroy_complete_lines(tetris_t *tetris)
{
    int is_complete = 1;

    for (int y = 1; y < tetris->map->height + 1; y++) {
        for (int x = MAP_X + 1; x < MAP_X + 1 + tetris->map->width; x++) {
            is_complete = (mvinch(y, x) & A_CHARTEXT) != '*' ? 0 : is_complete;
        }
        if (is_complete) {
            destroy_line(tetris->map, y);
            tetris->destroyed_lines += 1;
            tetris->lines_counter += 1;
            tetris->score += 10;
        }
        if (tetris->lines_counter >= 10) {
            tetris->lines_counter = 0;
            tetris->level += 1;
        }
        is_complete = 1;
    }
}
