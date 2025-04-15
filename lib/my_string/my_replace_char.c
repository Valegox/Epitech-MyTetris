/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function replaces a char by another char in a string.
*/

int my_replace_char(char *str, char c, char new_c)
{
    int found_c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            str[i] = new_c;
            found_c = 1;
        }
    }
    return found_c;
}
