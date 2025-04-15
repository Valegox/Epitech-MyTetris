/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** This program compares 2 strings.
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2 || (*s1 == '\0' && *s2 == '\0')) {
            return (*s1 - *s2);
        }
        s1 += 1;
        s2 += 1;
    }
    return (0);
}
