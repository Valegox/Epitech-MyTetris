/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** Get high score
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include "my_string.h"
#include "my_tetris.h"

void save_score_if_higher(tetris_t *tetris)
{
    int fd = 0;
    char *new_score_str = NULL;
    int new_score_len = 0;

    fd = open("high_score.txt", O_WRONLY);
    if (fd == -1) {
        return;
    }
    if (tetris->score > tetris->high_score) {
        new_score_str = my_int_to_str(tetris->score);
        new_score_len = my_strlen(new_score_str);
        write(fd, new_score_str, (size_t) new_score_len);
        free(new_score_str);
    }
    close(fd);
}

void display_high_score(tetris_t *tetris)
{
    if (tetris->high_score > tetris->score) {
        mvprintw(5, 14, "%i", tetris->high_score);
    } else {
        mvprintw(5, 14, "%i", tetris->score);
    }
}

int get_high_score(void)
{
    char *high_score_str = NULL;
    int high_score = 0;

    high_score_str = get_file_content("high_score.txt");
    if (!high_score_str || !my_str_is_num(high_score_str)) {
        return 0;
    }
    high_score = my_get_nbr(high_score_str);
    free(high_score_str);
    return high_score;
}
