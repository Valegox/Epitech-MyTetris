/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** This function splits a string into words.
*/

#include <stdlib.h>

char *my_strdup(char const *src);

int my_strlen(char const *str);

char *my_init_string(int size);

void cut_word(char **result, int *result_index,
char *word, int *word_index)
{
    result[*result_index] = my_strdup(word);
    for (int index = 0; word[index] != '\0'; index += 1) {
        word[index] = '\0';
    }
    *word_index = 0;
    *result_index += 1;
}

int is_separator(char c)
{
    return c == ' ' || c == '\t';
}

char **my_str_to_word_array(char const *str, char separator)
{
    char **result = malloc(sizeof(char *) * my_strlen(str));
    int result_index = 0;
    char *word = my_init_string(my_strlen(str));
    int word_index = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == separator && my_strlen(word) > 0) {
            cut_word(result, &result_index, word, &word_index);
        } else if (str[i] != separator) {
            word[word_index] = str[i];
            word[word_index + 1] = '\0';
            word_index++;
        }
    if (my_strlen(word) > 0)
        cut_word(result, &result_index, word, &word_index);
    result[result_index] = NULL;
    free(word);
    return result;
}
