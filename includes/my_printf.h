/*
** EPITECH PROJECT, 2021
** My prinf lib
** File description:
** My printf header
*/

#ifndef MY_PRINTF_HEADER_
    #define MY_PRINTF_HEADER_
    #include <stdarg.h>
struct var_to_print {
    char conversion_modifier;
    void (*print_var)(va_list);
};
typedef struct var_to_print var_to_print_t;
int my_printf(char *format, ...);
#endif
