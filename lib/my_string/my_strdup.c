/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** This function allocates memory and copies a string in it.
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *my_str;
    int i = 0;

    my_str = malloc(my_strlen(src) + 1);
    while (i < my_strlen(src)) {
        my_str[i] = src[i];
        i++;
    }
    my_str[i] = '\0';
    return (my_str);
}
