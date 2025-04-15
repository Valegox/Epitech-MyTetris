/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** This program copies n characters from a string into another.
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] == '\0') {
            break;
        }
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src)) {
        dest[n] = '\0';
    }
    return (dest);
}
