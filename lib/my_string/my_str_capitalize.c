/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** This program capitalizes the first letter of each word in a string.
*/

void upper(char *c)
{
    if (*c >= 97 && *c <= 122) {
        *c -= 32;
    }
}

void lower(char *c)
{
    if (*c >= 65 && *c <= 90) {
        *c += 32;
    }
}

char *my_str_capitalize(char *str)
{
    char *my_str = str;

    upper(my_str);
    while (*my_str != '\0') {
        if (*my_str < 48 || (*my_str > 57 && *str < 65)
            || (*my_str > 90 && *my_str < 97) || (*str > 122)
        ) {
            upper(my_str + 1);
        } else {
            lower(my_str + 1);
        }
        my_str++;
    }
    return (str);
}
