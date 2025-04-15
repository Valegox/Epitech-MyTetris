/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function returns the value of an array at an existing given index.
*/

#include <stdlib.h>
#include "my_array.h"

void *my_get_array_at(my_array_t arr, int index)
{
    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        if (index == elt->index) {
            return elt->value;
        }
    }
    return NULL;
}
