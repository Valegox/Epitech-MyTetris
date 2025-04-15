/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** game_loop
*/

#include <stdlib.h>
#include <curses.h>
#include "my_tetris.h"
#include "time.h"

int pause_game(game_keys_t *keys)
{
    int ch = 0;

    mvprintw(0, 0, "Pause");
    while (ch != keys->pause) {
        ch = getch();
        if (ch == keys->quit) {
            endwin();
            exit (0);
        }
        refresh();
    }
    mvprintw(0, 0, "     ");
    return (0);
}

void init_ncurses(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
}

void handle_keys(tetris_t *tetris, int ch)
{
    if (ch == tetris->keys->pause)
        pause_game(tetris->keys);
    if (ch == tetris->keys->drop)
        drop_tetrimino(tetris->playing_tmino);
    if (ch == tetris->keys->left || ch == tetris->keys->right)
        move_tetriminos(tetris->playing_tmino, ch, tetris->keys);
    if (ch == tetris->keys->turn)
        rotate_tetrimino_right(tetris->playing_tmino, tetris->map);
}

int update_game(tetris_t *tetris, clock_t *time)
{
    int ch = 0;
    int loosed = 0;

    destroy_complete_lines(tetris);
    handle_gravity(tetris->playing_tmino, tetris->level, time);
    ch = getch();
    handle_keys(tetris, ch);
    print_playing_tetrimino(tetris->playing_tmino);
    loosed = call_new_tetriminos(tetris);
    if (loosed) {
        return tetris->keys->quit;
    }
    mvprintw(6, 9, "%i", tetris->score);
    mvprintw(8, 9, "%i", tetris->destroyed_lines);
    mvprintw(9, 9, "%i", tetris->level);
    refresh();
    return ch;
}

int game_loop(tetris_t *tetris)
{
    int ch = 0;
    clock_t time = clock();

    tetris->playing_tmino = NULL;
    init_ncurses();
    if (is_window_too_small(tetris->map))
        return ERROR_STATUS;
    print_ui(tetris->map->width, tetris->map->height);
    tetris->playing_tmino = spawn_tetrimino(tetris->tetriminos, NULL);
    print_playing_tetrimino(tetris->playing_tmino);
    while (ch != tetris->keys->quit) {
        ch = update_game(tetris, &time);
        display_high_score(tetris);
        print_timer(time);
    }
    endwin();
    save_score_if_higher(tetris);
    return SUCCESS_STATUS;
}
