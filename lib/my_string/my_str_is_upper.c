/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** This program returns 1 if the string passed as parameter only
** contains uppercase alphabetical characters. Else, it returns 0.
*/

int my_str_is_upper(char const *str)
{
    while (*str != '\0') {
        if (*str < 65 || *str > 90) {
            return (0);
        }
        str++;
    }
    return (1);
}
