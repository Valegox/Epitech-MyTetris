/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** This program returns 1 if the string passed as
** parameter is printable. Else, it returns 0.
*/

int my_str_is_printable(char const *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str > 126) {
            return (0);
        }
        str++;
    }
    return (1);
}
