/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** This program returns 1 if the string passed
** as parameter is only alphabetic. Else, it returns 0.
*/

int my_str_is_alpha(char const *str)
{
    while (*str != '\0') {
        if (*str < 65 || (*str > 90 && *str < 97) || *str > 122) {
            return (0);
        }
        str++;
    }
    return (1);
}
