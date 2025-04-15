/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** This program returns 1 if the string passed as
** parameter contains only digits. Else, it returns 0.
*/

int my_str_is_num(char const *str)
{
    while (*str != '\0') {
        if (*str < 48 || *str > 57) {
            return (0);
        }
        str++;
    }
    return (1);
}
