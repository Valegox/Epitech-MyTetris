/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function returns 1 if str includes c, else 0.
*/

int my_str_includes_char(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (1);
    return (0);
}
