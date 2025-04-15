/*
** EPITECH PROJECT, 2021
** my_throw_error
** File description:
** This function sends an error message.
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_throw_error(char *error_message)
{
    return write(2, error_message, my_strlen(error_message));
}
