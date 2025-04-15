/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** This program contains a function that takes 2 parameters:
** str and to_find. It returns str by removing every characters
** before the occurence "to_find".
*/

int are_similar(char *str_test, char *to_find_test)
{
    int found_similarity = 1;

    while (*to_find_test != '\0') {
        if (*str_test != *to_find_test) {
            found_similarity = 0;
            break;
        }
        str_test++;
        to_find_test++;
    }
    return (found_similarity);
}

char *my_strstr(char *str, char const *to_find)
{
    if (*to_find == '\0') {
        return (str);
    }
    while (*str != '\0') {
        if (*str == *to_find && are_similar(str, (char *)to_find)) {
            return (str);
        }
        str++;
    }
    return (void *) 0;
}
