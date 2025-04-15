/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** This program compares 2 strings.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1 += 1;
        s2 += 1;
    }
    return (0);
}
