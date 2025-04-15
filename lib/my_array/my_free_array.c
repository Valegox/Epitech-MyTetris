/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function frees an array and all its elements from the memory.
*/

#include <stdlib.h>
#include "my_array.h"

int my_free_array(my_array_t arr)
{
    int freed_elements = 0;

    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        if (elt->prev_element != NULL) {
            free(elt->prev_element);
            freed_elements++;
        }
    }
    if (arr.last_element != NULL) {
        free(arr.last_element);
        freed_elements++;
    }
    return freed_elements;
}
