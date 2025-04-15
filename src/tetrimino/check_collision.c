/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** check_collision
*/

#include <stdlib.h>
#include <curses.h>
#include "my_string.h"
#include "my_tetris.h"
#include "time.h"

int check_if_last_block(playing_tetrimino_t *tmino, int i, int j)
{
    if (get_tetrimino_at(tmino->tetrimino, j, i) == '*'
    && (get_tetrimino_at(tmino->tetrimino, j, i + 1) == ' '
    || get_tetrimino_at(tmino->tetrimino, j, i + 1) == '\0')) {
        if ((mvinch(tmino->y + i + 2, tmino->x + MAP_X + j + 1)
        & A_CHARTEXT) == '-' || (mvinch(tmino->y + i + 2, tmino->x
        + MAP_X + j + 1) & A_CHARTEXT) == '*') {
            return (1);
        }
    }
    return (0);
}

int intermediate_check(playing_tetrimino_t *tmino, int i)
{
    for (int j = 0; j < tmino->tetrimino->width; j++) {
        if (check_if_last_block(tmino, i, j) == 1) {
            return (1);
        }
    }
    return (0);
}

int check_collision(playing_tetrimino_t *tmino)
{
    for (int i = 0; i < tmino->tetrimino->height; i++) {
        if (intermediate_check(tmino, i) == 1) {
            return (1);
        }
    }
    return (0);
}
