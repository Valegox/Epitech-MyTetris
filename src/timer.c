/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Timer
*/

#include <curses.h>
#include "time.h"

void print_timer(clock_t time)
{
    int elapsed_sec = 0;
    int printed_minutes = 0;
    int printed_seconds = 0;

    elapsed_sec = time / CLOCKS_PER_SEC;
    printed_minutes = elapsed_sec / 60;
    printed_seconds = elapsed_sec - printed_minutes * 60;
    mvprintw(11, 10, "          ");
    mvprintw(11, 10, "%i:%i", printed_minutes, printed_seconds);
}
