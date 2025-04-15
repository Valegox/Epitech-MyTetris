/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function initializes a string with a given size.
*/

#include <stdlib.h>

char *my_init_string(int size)
{
    char *str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i <= size; i++)
        str[i] = '\0';
    return (str);
}
