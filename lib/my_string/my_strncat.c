/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** This program concatenates n characters of
** the src to the end of the dest string.
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_initial_size = my_strlen(dest);
    int dest_index = dest_initial_size;
    int src_index = 0;

    while (dest_index < dest_initial_size + my_strlen(src)) {
        if (src_index == nb) {
            break;
        }
        dest[dest_index] = src[src_index];
        dest_index++;
        src_index++;
    }
    dest[dest_index] = '\0';
    return (dest);
}
