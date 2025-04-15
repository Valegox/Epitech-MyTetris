/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** This program reverses a string.
*/

int my_strlen(char const *str);

int my_swap_char(char *a, char *b)
{
    char a_value = *a;

    *a = *b;
    *b = a_value;
    return (0);
}

char *my_revstr(char *str)
{
    int str_length = my_strlen(str);
    int i = 0;

    while (i < str_length / 2) {
        my_swap_char(str + i, str + str_length - i - 1);
        i++;
    }
    return (str);
}
