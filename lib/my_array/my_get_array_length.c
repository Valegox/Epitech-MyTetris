/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function returns the length of a given array.
*/

#include <stdlib.h>
#include "my_array.h"

int my_get_array_length(my_array_t arr)
{
    if (arr.last_element == NULL) {
        return 0;
    }
    return arr.last_element->index + 1;
}
