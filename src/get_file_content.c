/*
** EPITECH PROJECT, 2021
** Tetris
** File description:
** Functions related to file reading
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curses.h>
#include "my_string.h"

int get_file_size(char const *path_name)
{
    struct stat statbuf;

    if (stat(path_name, &statbuf) == -1 ||
    (statbuf.st_mode & S_IFMT) != S_IFREG) {
        return -1;
    }
    return statbuf.st_size;
}

char *get_file_content(char const *path_name)
{
    int fd = 0;
    char *buff = NULL;
    int size = 0;

    size = get_file_size(path_name);
    if (size == -1)
        return NULL;
    buff = my_init_string(size);
    if (buff == NULL)
        return NULL;
    fd = open(path_name, O_RDONLY);
    if (fd == -1)
        return NULL;
    if (read(fd, buff, size) == -1)
        return NULL;
    close(fd);
    return buff;
}
