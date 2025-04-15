/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** Functions that print variables for my_printf
*/

#include <stdarg.h>
#include "my_string.h"

void my_print_d_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void my_print_s(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void my_print_c(va_list list)
{
    my_putchar(va_arg(list, int));
}
