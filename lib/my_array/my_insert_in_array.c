/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function inserts an element in an array at an existing given index.
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_array.h"

void increment_element_indexes_from(my_array_element_t *from_elt)
{
    for (my_array_element_t *elt = from_elt; elt != NULL;
    elt = elt->next_element) {
        elt->index += 1;
    }
}

my_array_t insert_element(my_array_t arr, int index, void *value,
my_array_element_t *old_elt)
{
    my_array_element_t *new_element = malloc(sizeof(my_array_element_t));

    new_element->index = index;
    new_element->value = value;
    new_element->next_element = old_elt;
    if (old_elt->prev_element == NULL) {
        new_element->prev_element = NULL;
    } else {
        new_element->prev_element = old_elt->prev_element;
        old_elt->prev_element->next_element = new_element;
    }
    old_elt->prev_element = new_element;
    increment_element_indexes_from(old_elt);
    if (index == 0) {
        arr.first_element = new_element;
    }
    return arr;
}

my_array_t my_insert_in_array(my_array_t arr, int index, void *value)
{
    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        if (index == elt->index) {
            return insert_element(arr, index, value, elt);
        }
    }
    my_throw_error("my_insert_in_array: Index out of range.\n");
    return arr;
}
