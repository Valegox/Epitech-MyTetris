/*
** EPITECH PROJECT, 2021
** My array lib
** File description:
** This file contains all the prototypes of my array lib.
*/

#ifndef MY_ARRAY
    #define MY_ARRAY

struct my_array_element {
    int index;
    void *value;
    struct my_array_element *next_element;
    struct my_array_element *prev_element;
};
typedef struct my_array_element my_array_element_t;

struct my_array {
    my_array_element_t *first_element;
    my_array_element_t *last_element;
};
typedef struct my_array my_array_t;

my_array_t my_create_array(void);

my_array_t my_append_in_array(my_array_t arr, void *value);

int my_print_array(my_array_t arr);

void *my_get_array_at(my_array_t arr, int index);

int my_get_array_length(my_array_t arr);

my_array_t my_set_array_at(my_array_t arr, int index, void *value);

my_array_t my_insert_in_array(my_array_t arr, int index, void *value);

my_array_t my_remove_from_array(my_array_t arr, int index);

int my_free_array(my_array_t arr);

#endif
