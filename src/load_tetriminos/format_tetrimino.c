/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Format tetrimino by removing misplaced spaces
*/

#include <stdlib.h>
#include "my_tetris.h"
#include "my_string.h"

char add_formated_char_to_content(char *prev_content, int i,
int *shift, int *after_line)
{
    if (prev_content[i - (*shift)] == '\n') {
        *after_line = 1;
    }
    if (*after_line) {
        (*shift)++;
        return ' ';
    }
    return prev_content[i - (*shift)];
}

char *format_tmino(char *prev_content, int width, int height)
{
    char *content = NULL;
    int i = 0;
    int after_line = 0;
    int shift = 0;

    content = my_init_string((width + 1) * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            i = y * (width + 1) + x;
            content[i] = add_formated_char_to_content(prev_content, i,
            &shift, &after_line);
        }
        after_line = 0;
        i = y * (width + 1) + width;
        while (prev_content[i - shift] != '\n')
            shift--;
        content[i] = '\n';
    }
    return content;
}
