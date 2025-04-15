/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Parse single tetrimino
*/

#include <stdlib.h>
#include "my_array.h"
#include "my_string.h"
#include "my_printf.h"
#include "my_tetris.h"

char *get_first_line(char *str, char **content)
{
    char *first_line = NULL;

    first_line = my_init_string(my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            my_strncpy(first_line, str, i);
            *content = &(str[i + 1]);
            return first_line;
        }
    }
    return NULL;
}

void free_properties(char **properties, char *first_line)
{
    for (int i = 0; properties[i] != NULL; i++) {
        free(properties[i]);
    }
    free(properties);
    free(first_line);
}

tetrimino_t *get_tetrimino(char *name, char *file_content,
map_t *map)
{
    tetrimino_t *tino = NULL;
    char **properties = NULL;
    char *content = NULL;
    char *first_line = get_first_line(file_content, &content);

    if (first_line && content) {
        if (!are_tmino_characters_valid(content)) {
            return NULL;
        }
        properties = my_str_to_word_array(first_line, ' ');
        if (are_properties_valid(properties)) {
            tino = set_tetrimino_properties(name, content, properties);
        }
        if (are_properties_valid(properties) && !is_size_valid(tino, map)) {
            return NULL;
        }
        free_properties(properties, first_line);
    }
    return tino;
}

char *cat_name_path(char *name)
{
    char *file_path = NULL;

    file_path = my_init_string(11 + my_strlen(name));
    my_strcat(file_path, "tetriminos/");
    my_strcat(file_path, name);
    return file_path;
}

tetrimino_t *load_single_tetrimino(char *name, map_t *map)
{
    tetrimino_t *tetrimino = NULL;
    char *file_content = NULL;
    char *file_path = NULL;

    file_path = cat_name_path(name);
    file_content = get_file_content(file_path);
    if (!file_content || !str_ends_with(name, ".tetrimino")) {
        free(file_path);
        return NULL;
    }
    tetrimino = get_tetrimino(name, file_content, map);
    if (!tetrimino) {
        free(file_path);
        free(file_content);
        return NULL;
    }
    free(file_path);
    free(file_content);
    return tetrimino;
}
