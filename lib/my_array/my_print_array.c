/*
** EPITECH PROJECT, 2021
** My array
** File description:
** This function prints all the elements of an array, with their index.
*/

#include <stdlib.h>
#include "my_array.h"
#include "my_printf.h"

int my_print_array(my_array_t arr)
{
    int status = 0;

    for (my_array_element_t *elt = arr.first_element; elt != NULL;
    elt = elt->next_element) {
        status = my_printf("Element %i %s\n", elt->index, elt->value);
        if (status != 0) {
            return status;
        }
    }
    return 0;
}
