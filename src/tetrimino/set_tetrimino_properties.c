/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Set tetrimino properties
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_tetris.h"

tetrimino_t *set_tetrimino_properties(char *name, char *content,
char **properties)
{
    tetrimino_t *tino = NULL;

    tino = malloc(sizeof(tetrimino_t));
    tino->name = name;
    tino->width = my_get_nbr(properties[0]);
    tino->height = my_get_nbr(properties[1]);
    tino->color = my_get_nbr(properties[2]);
    tino->content = format_tmino(content, tino->width, tino->height);
    return tino;
}
