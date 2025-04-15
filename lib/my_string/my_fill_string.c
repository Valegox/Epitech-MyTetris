/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function fills a string with \0.
*/

#include <stdlib.h>

char *my_fill_string(char *str, int size)
{
    for (int i = 0; i <= size; i++)
        str[i] = '\0';
    return (str);
}
