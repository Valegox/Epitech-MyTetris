/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function creates an array.
*/

#include <stdlib.h>
#include "my_array.h"

my_array_t my_create_array(void)
{
    my_array_t arr;

    arr.first_element = NULL;
    arr.last_element = NULL;
    return arr;
}
