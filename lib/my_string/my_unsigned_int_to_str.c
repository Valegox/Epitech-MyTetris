/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function converts an unsigned int to string
*/

#include <stdlib.h>

char *my_init_string(int size);

int my_get_nb_length_for_str(unsigned int value);

char *my_revstr(char *str);

char *my_unsigned_int_to_str(unsigned int value)
{
    char *result = my_init_string(my_get_nb_length_for_str(value));
    int i = 0;

    if (value < 0)
        value *= -1;
    if (value == 0)
        result = "0";
    else
        for (i = 0; value != 0; i++) {
            result[i] = (value % 10) + '0';
            value = value / 10;
        }
    result = my_revstr(result);
    return (result);
}
