/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** This program displays the characters of a string.
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    char *char_to_display = (char *)str;

    while (*char_to_display != '\0') {
        my_putchar(*char_to_display);
        char_to_display++;
    }
    return (0);
}
