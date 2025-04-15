/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Spawn tetrimino
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include "my_array.h"
#include "my_string.h"
#include "my_tetris.h"

int get_random(int max)
{
    return rand() % max;
}

void print_next_section(tetrimino_t *tmino)
{
    for (int y = 16; y < 20; y++) {
        mvprintw(y, 3, "                   ");
    }
    if (tmino->width > 19 || tmino->height > 4) {
        mvprintw(18, 3, "Too big for preview");
    } else {
        print_tetrimino(tmino, 3, 16);
    }
}

tetrimino_t *dup_tetrimino(my_array_t tetriminos, int index)
{
    tetrimino_t *tmino = NULL;
    tetrimino_t *dup_tmino = NULL;

    tmino = my_get_array_at(tetriminos, index);
    dup_tmino = malloc(sizeof(tetrimino_t));
    dup_tmino->name = tmino->name;
    dup_tmino->width = tmino->width;
    dup_tmino->height = tmino->height;
    dup_tmino->color = tmino->color;
    dup_tmino->content = my_strdup(tmino->content);
    return dup_tmino;
}

playing_tetrimino_t *spawn_tetrimino(my_array_t tetriminos,
playing_tetrimino_t *prev)
{
    playing_tetrimino_t *new_tmino = NULL;

    new_tmino = malloc(sizeof(tetrimino_t));
    if (prev) {
        new_tmino->tetrimino = dup_tetrimino(tetriminos, prev->next_type);
    } else {
        new_tmino->tetrimino = dup_tetrimino(tetriminos,
        get_random(my_get_array_length(tetriminos)));
    }
    new_tmino->x = 0;
    new_tmino->y = 0;
    new_tmino->next_type = get_random(my_get_array_length(tetriminos));
    print_next_section(my_get_array_at(tetriminos, new_tmino->next_type));
    return new_tmino;
}
