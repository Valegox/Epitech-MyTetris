/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Display user interface as string.
*/

#include <stdlib.h>
#include <curses.h>
#include "my_printf.h"
#include "my_tetris.h"

void print_map_horizontal_border(int x, int y, int width)
{
    int length = x + width + 1;

    mvaddstr(y, x, "+");
    for (x = x + 1; x < length; x++) {
        mvaddstr(y, x, "-");
    }
    mvaddstr(y, x, "+\n");
}

void print_map(int x, int width, int height)
{
    int initial_x = x;
    int length = x + width + 1;

    print_map_horizontal_border(x, 0, width);
    for (int y = 1; y < height + 1; y++) {
        mvaddstr(y, initial_x, "|");
        for (x = initial_x + 1; x < length; x++) {
            mvaddstr(y, x, " ");
        }
        mvaddstr(y, x, "|\n");
    }
    print_map_horizontal_border(initial_x, height + 1, width);
}

int print_ui(int map_width, int map_height)
{
    char *left_side = NULL;

    left_side = get_file_content("user_interface.txt");
    if (!left_side)
        return ERROR_STATUS;
    mvaddstr(0, 0, left_side);
    print_map(MAP_X, map_width, map_height);
    free(left_side);
    return SUCCESS_STATUS;
}
