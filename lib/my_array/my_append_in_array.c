/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function appends an element at the end of a given array.
*/

#include <stdlib.h>
#include "my_array.h"

my_array_t my_append_in_array(my_array_t arr, void *value)
{
    my_array_element_t *new_element = malloc(sizeof(my_array_element_t));

    new_element->value = value;
    new_element->next_element = NULL;
    if (arr.last_element == NULL) {
        new_element->index = 0;
        new_element->prev_element = NULL;
        arr.first_element = new_element;
        arr.last_element = new_element;
    } else {
        new_element->index = arr.last_element->index + 1;
        new_element->prev_element = arr.last_element;
        arr.last_element->next_element = new_element;
        arr.last_element = new_element;
    }
    return arr;
}
