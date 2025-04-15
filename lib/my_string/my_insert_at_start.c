/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function inserts c at the start of str.
*/

#include <stdlib.h>

char *my_init_string(int size);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_insert_at_start(char *str, char c)
{
    char *result = my_init_string(my_strlen(str) + 1);

    result[0] = c;
    my_strcat(result, str);
    return (result);
}
