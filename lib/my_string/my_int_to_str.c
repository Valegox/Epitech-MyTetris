/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function converts an int to string
*/

#include <stdlib.h>

char *my_init_string(int size);

char *my_revstr(char *str);

int my_get_nb_length_for_str(unsigned int value)
{
    int count = 0;

    while (value != 0) {
        value /= 10;
        count++;
    }
    return (count);
}

char *my_int_to_str(int value)
{
    char *result = my_init_string(my_get_nb_length_for_str(value));
    int i = 0;
    int prev_nbr = value;

    if (value < 0)
        value *= -1;
    if (value == 0) {
        result[0] = '0';
        result[1] = '\0';
    } else
        for (i = 0; value != 0; i++) {
            result[i] = (value % 10) + '0';
            value = value / 10;
        }
    if (prev_nbr < 0)
        result[i] = '-';
    my_revstr(result);
    return (result);
}
