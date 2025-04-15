/*
** EPITECH PROJECT, 2021
** My ls
** File description:
** This function filters a string by removing non alphanumeric characters.
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_get_alphanumeric_str(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9')
        || (str[i] >= 'a' && str[i] <= 'z')
        || str[i] >= 'A' && str[i] <= 'Z') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}
