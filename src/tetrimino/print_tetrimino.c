/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Print tetrimino
*/

#include <stdlib.h>
#include <curses.h>
#include "my_string.h"
#include "my_printf.h"
#include "my_tetris.h"

int erase_tetrimino(tetrimino_t *tetrimino, int x, int y)
{
    char **content_lines = NULL;
    int j = 0;

    if (!tetrimino) {
        return ERROR_STATUS;
    }
    content_lines = my_str_to_word_array(tetrimino->content, '\n');
    for (int i = 0; content_lines[i] != NULL; i++) {
        for (j = 0; content_lines[i][j] != '\n' &&
        content_lines[i][j] != '\0'; j++) {
            mvaddstr(y + i, x + j, " ");
        }
        free(content_lines[i]);
    }
    free(content_lines);
    return SUCCESS_STATUS;
}

int erase_playing_tetrimino(playing_tetrimino_t *tmino)
{
    if (!tmino) {
        return ERROR_STATUS;
    }
    erase_tetrimino(tmino->tetrimino, (tmino->x + MAP_X + 1),
    (tmino->y + 1));
    return SUCCESS_STATUS;
}

int print_tetrimino(tetrimino_t *tetrimino, int x, int y)
{
    char **content_lines = NULL;

    if (!tetrimino) {
        return ERROR_STATUS;
    }
    content_lines = my_str_to_word_array(tetrimino->content, '\n');
    attron(COLOR_PAIR(tetrimino->color));
    for (int i = 0; content_lines[i] != NULL; i++) {
        for (int j = 0; content_lines[i][j] != '\0'; j++) {
            content_lines[i][j] == '*' ?
            mvprintw(y + i, x + j, "*") : 0;
        }
        free(content_lines[i]);
    }
    free(content_lines);
    attroff(COLOR_PAIR(tetrimino->color));
    return SUCCESS_STATUS;
}

int print_playing_tetrimino(playing_tetrimino_t *tetrimino)
{
    if (!tetrimino) {
        return ERROR_STATUS;
    }
    return print_tetrimino(tetrimino->tetrimino, tetrimino->x + MAP_X + 1,
    tetrimino->y + 1);
}
