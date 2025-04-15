/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Error handling functions to load tetrimino
*/

#include <stdlib.h>
#include "my_array.h"
#include "my_tetris.h"
#include "my_string.h"

int is_size_valid(tetrimino_t *tmino, map_t *map)
{
    return tmino->width < map->width && tmino->height < map->height;
}

int are_properties_valid(char **properties)
{
    if (!properties[0] || !properties[1] || !properties[2]
    || !my_str_is_num(properties[0]) || !my_str_is_num(properties[1]) ||
    !my_str_is_num(properties[2]) || my_get_nbr(properties[2]) < 0 ||
    my_get_nbr(properties[2]) > 15) {
        return 0;
    }
    return 1;
}

int str_ends_with(char *str, char *value)
{
    if (my_strlen(str) >= my_strlen(value)) {
        return !my_strcmp(&(str[my_strlen(str) - my_strlen(value)]), value);
    }
    return 0;
}

int are_tmino_characters_valid(char *content)
{
    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] != ' ' && content[i] != '*' &&
        content[i] != '\n') {
            return 0;
        }
    }
    return 1;
}
