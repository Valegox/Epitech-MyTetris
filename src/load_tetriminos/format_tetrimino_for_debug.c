/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Format tetrimino by removing misplaced spaces for debug
*/

#include <stdlib.h>
#include "my_tetris.h"
#include "my_printf.h"
#include "my_string.h"

void print_tmino_for_debug(tetrimino_t *tmino)
{
    char **lines = NULL;
    int x = 0;

    lines = my_str_to_word_array(tmino->content, '\n');
    for (int y = 0; lines[y] != NULL; y++) {
        for (x = tmino->width - 1; x > 0 && lines[y][x] == ' '; x--) {
            lines[y][x] = '\0';
        }
        lines[y][x + 1] = '\0';
        my_printf("%s\n", lines[y]);
        free(lines[y]);
    }
    free(lines);
}
