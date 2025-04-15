/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** move_tetrimino
*/

#include <stdlib.h>
#include <curses.h>
#include "my_string.h"
#include "my_tetris.h"
#include "time.h"

int should_call_tetrimino(tetris_t *tetris)
{
    return (mvinch(tetris->playing_tmino->y + 1 +
    tetris->playing_tmino->tetrimino->height, tetris->playing_tmino->x + MAP_X
    + 1) & A_CHARTEXT) == '-'
    || (mvinch(tetris->playing_tmino->y + 1 +
    tetris->playing_tmino->tetrimino->height, tetris->playing_tmino->x + MAP_X
    + 1) & A_CHARTEXT) == '*';
}

int call_new_tetriminos(tetris_t *tetris)
{
    playing_tetrimino_t *prev_tmino = NULL;

    if (should_call_tetrimino(tetris)) {
        if (!can_spawn_tetrimino(tetris)) {
            return 1;
        }
        if (check_collision(tetris->playing_tmino) == 1) {
            tetris->score += 1;
            prev_tmino = tetris->playing_tmino;
            tetris->playing_tmino = spawn_tetrimino(tetris->tetriminos,
            prev_tmino);
            free(prev_tmino->tetrimino->content);
            free(prev_tmino->tetrimino);
            free(prev_tmino);
        }
    }
    return 0;
}

int handle_gravity(playing_tetrimino_t *tmino, int level, clock_t *time)
{
    char empty[tmino->tetrimino->width];

    for (int i = 0; i <= tmino->tetrimino->width; i++)
        empty[i] = '\0';
    for (int i = 0; i < tmino->tetrimino->width; i++)
        empty[i] = ' ';
    if (check_collision(tmino) == 0) {
        if ((clock() - *time) / CLOCKS_PER_SEC >= 1 / level) {
            erase_tetrimino(tmino->tetrimino, tmino->x + MAP_X + 1,
            tmino->y + 1);
            mvprintw(tmino->y + 1, tmino->x + MAP_X + 1, empty);
            tmino->y += 1;
            *time = clock();
        }
    }
    return 0;
}

int drop_tetrimino(playing_tetrimino_t *tmino)
{
    erase_tetrimino(tmino->tetrimino, tmino->x + MAP_X + 1, tmino->y + 1);
    while (check_collision(tmino) == 0) {
        tmino->y += 1;
    }
    return 0;
}

int move_tetriminos(playing_tetrimino_t *tmino, int ch, game_keys_t *keys)
{
    if (ch == keys->left) {
        if ((mvinch(tmino->y + 1, tmino->x + MAP_X) & A_CHARTEXT) != '|') {
            erase_tetrimino(tmino->tetrimino, (tmino->x + MAP_X + 1),
            (tmino->y + 1));
            tmino->x -= 1;
        }
    }
    if (ch == keys->right) {
        if ((mvinch(tmino->y + 1, tmino->x + MAP_X + tmino->tetrimino->width
        + 1) & A_CHARTEXT) != '|') {
            erase_tetrimino(tmino->tetrimino, tmino->x + MAP_X + 1,
            (tmino->y + 1));
            tmino->x += 1;
        }
    }
    return 0;
}
