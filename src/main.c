/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Main file of the project.
*/

#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "my_string.h"
#include "my_printf.h"
#include "my_tetris.h"

game_keys_t *get_default_keys(void)
{
    game_keys_t *keys = NULL;

    keys = malloc(sizeof(game_keys_t));
    keys->left = KEY_LEFT;
    keys->right = KEY_RIGHT;
    keys->turn = KEY_UP;
    keys->drop = KEY_DOWN;
    keys->quit = 'q';
    keys->pause = ' ';
    return keys;
}

tetris_t *get_default_tetris(void)
{
    tetris_t *tetris = NULL;

    tetris = malloc(sizeof(tetris_t));
    tetris->playing_tmino = NULL;
    tetris->map = malloc(sizeof(map_t));
    tetris->map->width = 10;
    tetris->map->height = 20;
    tetris->keys = get_default_keys();
    tetris->level = 1;
    tetris->with_next = 1;
    tetris->debug_mode = 0;
    tetris->destroyed_lines = 0;
    tetris->lines_counter = 0;
    tetris->score = 0;
    tetris->high_score = get_high_score();
    return tetris;
}

tetris_t *get_tetris(int ac, char **av)
{
    tetris_t *tetris = NULL;

    tetris = get_default_tetris();
    if (!tetris)
        return NULL;
    tetris = parse_options(ac, av, tetris);
    if (!tetris)
        return NULL;
    if (tetris->debug_mode)
        debug_tetris_data(tetris);
    tetris->tetriminos = load_tetriminos(tetris->debug_mode, tetris->map);
    if (my_get_array_length(tetris->tetriminos) == 0) {
        my_printf("No tetriminos found\n");
        return NULL;
    }
    return tetris;
}

int main(int ac, char **av)
{
    tetris_t *tetris = NULL;
    int status = 0;

    tetris = get_tetris(ac, av);
    if (!tetris) {
        return ERROR_STATUS;
    }
    srand(time(NULL));
    if (!tetris->debug_mode) {
        status = game_loop(tetris);
    }
    if (status == 0) {
        free_tetris(tetris);
    }
    return status;
}
