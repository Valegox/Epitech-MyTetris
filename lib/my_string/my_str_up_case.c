/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** This program displays a string in upper case.
*/

char *my_str_up_case(char *str)
{
    char *my_str = str;

    while (*my_str != '\0') {
        if (*my_str >= 97 && *my_str <= 122) {
            *my_str -= 32;
        }
        my_str++;
    }
    return str;
}
