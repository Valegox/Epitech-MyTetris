/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** This program counts the length of a string.
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return count;
}
