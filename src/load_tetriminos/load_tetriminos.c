/*
** EPITECH PROJECT, 2021
** Tetris bootstrap
** File description:
** Parse tetriminos
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include "my_string.h"
#include "my_array.h"
#include "my_printf.h"
#include "my_tetris.h"

void append_tetrimino_debug(tetrimino_t *tmino, char *name)
{
    char *name_without_extension = NULL;

    name_without_extension = my_strdup(name);
    name_without_extension[my_strlen(name) - 10] = '\0';
    if (!tmino) {
        my_printf("Tetriminos '%s': error\n", name_without_extension);
    } else {
        my_printf("Tetriminos '%s': size %i*%i, color %i\n",
        name_without_extension, tmino->width, tmino->height, tmino->color);
        print_tmino_for_debug(tmino);
    }
    free(name_without_extension);
}

my_array_t append_tetrimino(my_array_t tetriminos, char *name,
int debug_mode, map_t *map)
{
    tetrimino_t *single_tetrimino = NULL;

    if (name[0] != '.') {
        single_tetrimino = load_single_tetrimino(name, map);
        if (single_tetrimino) {
            tetriminos = my_append_in_array(tetriminos, single_tetrimino);
        }
        if (debug_mode) {
            append_tetrimino_debug(single_tetrimino, name);
        }
    }
    return tetriminos;
}

void debug_number_of_tminos(void)
{
    int count = 0;
    DIR *dir = NULL;
    struct dirent *t_dirent = NULL;

    dir = opendir("tetriminos");
    if (dir) {
        t_dirent = readdir(dir);
        while (t_dirent) {
            count += str_ends_with(t_dirent->d_name, ".tetrimino");
            t_dirent = readdir(dir);
        }
    }
    closedir(dir);
    my_printf("Number of tetriminos: %i\n", count);
}

my_array_t load_tetriminos(int debug_mode, map_t *map)
{
    DIR *dir = NULL;
    struct dirent *t_dirent = NULL;
    my_array_t tetriminos;

    tetriminos = my_create_array();
    dir = opendir("tetriminos");
    if (!dir) {
        my_throw_error("Error: no tetriminos directory found.\n");
        return tetriminos;
    }
    if (debug_mode)
        debug_number_of_tminos();
    t_dirent = readdir(dir);
    while (t_dirent) {
        tetriminos = append_tetrimino(tetriminos, t_dirent->d_name,
        debug_mode, map);
        t_dirent = readdir(dir);
    }
    closedir(dir);
    return tetriminos;
}
