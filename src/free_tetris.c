/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Free Tetris data from memory
*/

#include <stdlib.h>
#include "my_array.h"
#include "my_tetris.h"

void free_tetriminos(my_array_t tetriminos)
{
    tetrimino_t *tetrimino = NULL;

    for (int i = 0; my_get_array_at(tetriminos, i) != NULL; i++) {
        tetrimino = my_get_array_at(tetriminos, i);
        free(tetrimino->content);
        free(tetrimino);
    }
    my_free_array(tetriminos);
}

void free_tetris(tetris_t *tetris)
{
    if (tetris->playing_tmino) {
        free(tetris->playing_tmino->tetrimino->content);
        free(tetris->playing_tmino->tetrimino);
        free(tetris->playing_tmino);
    }
    free_tetriminos(tetris->tetriminos);
    free(tetris->map);
    free(tetris->keys);
    free(tetris);
}
