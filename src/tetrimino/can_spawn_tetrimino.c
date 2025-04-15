/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** Check if tetrimino can spawn
*/

#include <curses.h>
#include "my_tetris.h"

int can_spawn_line(int y, int tmino_width)
{
    for (int x = MAP_X + 1; x < MAP_X + 1 + tmino_width; x++) {
        if ((mvinch(y, x) & A_CHARTEXT) != ' ') {
            return 0;
        }
    }
    return 1;
}

int can_spawn_tetrimino(tetris_t *tetris)
{
    tetrimino_t *tmino = NULL;

    tmino = my_get_array_at(tetris->tetriminos,
    tetris->playing_tmino->next_type);
    for (int y = 1; y < tmino->height; y++) {
        if (!can_spawn_line(y, tmino->width)) {
            return 0;
        }
    }
    return 1;
}
