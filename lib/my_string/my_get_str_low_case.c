/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** This program displays a string in lower case.
*/

char *my_strdup(char const *src);

char *my_get_str_low_case(char *str)
{
    char *my_str = my_strdup(str);

    for (int i = 0; my_str[i] != '\0'; i++) {
        if (my_str[i] >= 65 && my_str[i] <= 90) {
            my_str[i] += 32;
        }
    }
    return my_str;
}
