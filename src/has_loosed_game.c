/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** Check if player has loosed game
*/

#include <curses.h>
#include "my_tetris.h"

int has_loosed_game(map_t *map)
{
    for (int x = MAP_X + 1; x < MAP_X + 1 + map->width; x++) {
        if ((mvinch(0, x) & A_CHARTEXT) != '-') {
            return 1;
        }
    }
    return 0;
}
