/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function sets the value of an array at an existing given index.
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_array.h"

my_array_t my_set_array_at(my_array_t arr, int index, void *value)
{
    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        if (index == elt->index) {
            elt->value = value;
            return arr;
        }
    }
    my_throw_error("my_set_array_at: Index out of range.\n");
    return arr;
}
