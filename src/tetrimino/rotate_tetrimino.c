/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Rotate tetrimino
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_printf.h"
#include "my_tetris.h"
#include <curses.h>

char get_tetrimino_at(tetrimino_t *tetrimino, int pos_x, int pos_y)
{
    int index = 0;

    index = (tetrimino->width + 1) * pos_y + pos_x;
    if (index < 0 || index > my_strlen(tetrimino->content)) {
        return '\0';
    }
    return tetrimino->content[index];
}

tetrimino_t set_tetrimino_at(tetrimino_t tetrimino, int pos_x, int pos_y,
char value)
{
    int index = 0;

    index = (tetrimino.width + 1) * pos_y + pos_x;
    if (index < 0 || index >= my_strlen(tetrimino.content)) {
        return tetrimino;
    }
    tetrimino.content[index] = value;
    return tetrimino;
}

void avoid_tetrimino_collision(playing_tetrimino_t *tmino, map_t *map)
{
    int right_border_x = 0;
    int is_colliding = 0;

    right_border_x = map->width + 1;
    is_colliding = tmino->x + tmino->tetrimino->width >= right_border_x;
    while (is_colliding) {
        tmino->x -= 1;
        is_colliding = tmino->x + tmino->tetrimino->width >=
        right_border_x;
    }
}

void rotate_tetrimino_right(playing_tetrimino_t *playing_tmino, map_t *map)
{
    int i = 0;
    char *content = NULL;
    int tmp_height = playing_tmino->tetrimino->height;

    erase_playing_tetrimino(playing_tmino);
    content = my_init_string(my_strlen(playing_tmino->tetrimino->content) * 2);
    for (int x = 0; x < playing_tmino->tetrimino->width; x++) {
        for (int y = playing_tmino->tetrimino->height - 1; y >= 0; y--) {
            content[i] = get_tetrimino_at(playing_tmino->tetrimino, x, y);
            i++;
        }
        content[i] = '\n';
        i++;
    }
    free(playing_tmino->tetrimino->content);
    playing_tmino->tetrimino->height = playing_tmino->tetrimino->width;
    playing_tmino->tetrimino->width = tmp_height;
    playing_tmino->tetrimino->content = content;
    avoid_tetrimino_collision(playing_tmino, map);
}
