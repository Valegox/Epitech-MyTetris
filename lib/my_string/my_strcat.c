/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** This program concatenates 2 strings.
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_initial_size = my_strlen(dest);
    int dest_index = dest_initial_size;
    int src_index = 0;

    while (dest_index < dest_initial_size + my_strlen(src)) {
        dest[dest_index] = src[src_index];
        dest_index++;
        src_index++;
    }
    dest[dest_index] = '\0';
    return (dest);
}
