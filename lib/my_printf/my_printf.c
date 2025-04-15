/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Printf of my lib
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_string.h"
#include "my_printf.h"

void my_print_d_i(va_list);

void my_print_s(va_list);

void my_print_c(va_list);

int is_conversion_modifier(char);

void list_end(va_list list);

void my_va_list_nothing(va_list list)
{
    return;
}

int is_conversion_modifier(char c)
{
    return (c == 'd' || c == 'i' || c == 'o' || c == 's' || c == 'c'
    || c == 'u' || c == 'b' || c == 'p' || c == '%' || c == 'x'
    || c == 'X' || c == 'S');
}

void print_conversion(va_list list, char conversion_modifier)
{
    const var_to_print_t VARS[] = { {'d', &my_print_d_i},
        {'i', &my_print_d_i}, {'s', &my_print_s},
        {'c', &my_print_c}, { '\0', &my_va_list_nothing} };

    for (int j = 0; VARS[j].conversion_modifier != '\0'; j++) {
        if (conversion_modifier == VARS[j].conversion_modifier) {
            VARS[j].print_var(list);
        }
    }
}

int handle_var_printing(va_list list, char *format, int i)
{
    if (is_conversion_modifier(format[i])) {
        print_conversion(list, format[i]);
        return (i);
    }
    my_putchar('%');
    return (i - 1);
}

int my_printf(char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            i = handle_var_printing(list, format, i);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
    return (0);
}
