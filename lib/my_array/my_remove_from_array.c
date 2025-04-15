/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function removes an element from an array from an existing index.
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_string.h"
#include "my_array.h"

void decrement_element_indexes_from(my_array_element_t *from_elt)
{
    for (my_array_element_t *elt = from_elt; elt != NULL;
    elt = elt->next_element) {
        elt->index -= 1;
    }
}

my_array_t remove_element(my_array_t arr, my_array_element_t *elt_to_rm)
{
    if (!elt_to_rm->prev_element && elt_to_rm->next_element) {
        elt_to_rm->next_element->prev_element = NULL;
        arr.first_element = elt_to_rm->next_element;
    }
    if (elt_to_rm->prev_element && elt_to_rm->next_element) {
        elt_to_rm->next_element->prev_element = elt_to_rm->prev_element;
        elt_to_rm->prev_element->next_element = elt_to_rm->next_element;
    }
    if (elt_to_rm->prev_element && !elt_to_rm->next_element) {
        elt_to_rm->prev_element->next_element = NULL;
        arr.last_element = elt_to_rm->prev_element;
    }
    if (!elt_to_rm->prev_element && !elt_to_rm->next_element) {
        arr.first_element = NULL;
        arr.last_element = NULL;
    }
    decrement_element_indexes_from(elt_to_rm);
    free(elt_to_rm);
    return arr;
}

my_array_t my_remove_from_array(my_array_t arr, int index)
{
    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        if (index == elt->index) {
            return remove_element(arr, elt);
        }
    }
    write(2, "my_remove_from_array: Index out of range.\n", 43);
    return arr;
}
