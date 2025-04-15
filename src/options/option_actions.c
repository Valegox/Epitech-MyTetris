/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Actions for options
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_tetris.h"

int set_level(__attribute__((unused)) char opt, char *param,
tetris_t *tetris)
{
    int level = 0;

    if (!my_str_is_num(param)) {
        return 84;
    }
    level = my_get_nbr(param);
    if (level <= 0)
        return 84;
    tetris->level = level;
    return 0;
}

int set_key(char opt, char *param, tetris_t *tetris)
{
    int code = 0;

    if (!my_str_is_num(param))
        return 84;
    code = my_get_nbr(param);
    if (code < 0 || code > 127)
        return 84;
    if (opt == 'l')
        tetris->keys->left = code;
    if (opt == 'r')
        tetris->keys->right = code;
    if (opt == 't')
        tetris->keys->turn = code;
    if (opt == 'd')
        tetris->keys->drop = code;
    if (opt == 'q')
        tetris->keys->quit = code;
    if (opt == 'p')
        tetris->keys->pause = code;
    return 0;
}

int set_map_size(__attribute__((unused)) char opt, char *param,
tetris_t *tetris)
{
    char **size = NULL;
    int row = 0;
    int col = 0;

    size = my_str_to_word_array(param, ',');
    if (size[0] == NULL || size[1] == NULL || size[2] != NULL)
        return 84;
    if (!my_str_is_num(size[0]) || !my_str_is_num(size[1]))
        return 84;
    row = my_get_nbr(size[0]);
    col = my_get_nbr(size[1]);
    if (row < 1 || col < 1)
        return 84;
    tetris->map->width = col;
    tetris->map->height = row;
    for (int i = 0; size[i] != NULL; i++)
        free(size[i]);
    free(size);
    return 0;
}

int set_next(__attribute__((unused)) char opt,
__attribute__((unused)) char *param, tetris_t *tetris)
{
    tetris->with_next = 0;
    return 0;
}

int set_debug(__attribute__((unused)) char opt,
__attribute__((unused)) char *param, tetris_t *tetris)
{
    tetris->debug_mode = 1;
    return 0;
}
