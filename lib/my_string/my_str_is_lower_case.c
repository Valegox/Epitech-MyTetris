/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** This program returns 1 if the string passed as parameter
** only contains lowercase alphabetical characters. Else, it returns 0.
*/

int my_str_is_lower_case(char const *str)
{
    while (*str != '\0') {
        if (*str < 97 || *str > 122) {
            return (0);
        }
        str++;
    }
    return (1);
}
