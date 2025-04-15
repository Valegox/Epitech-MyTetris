/*
** EPITECH PROJECT, 2021
** My string lib
** File description:
** This file contains all the prototypes of my string lib.
*/

#ifndef MY_STRING
    #define MY_STRING
char *my_fill_string(char *str, int size);
char *my_get_alphanumeric_str(char *str);
int my_get_nbr(char const *str);
char *my_get_str_low_case(char *str);
char *my_init_string(int size);
char *my_insert_at_start(char *str, char c);
char *my_int_to_str(int value);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
int my_replace_char(char *str, char c, char new_c);
char *my_revstr(char *str);
int my_show_word_array(char * const *tab);
char *my_str_capitalize(char *str);
int my_str_includes_char(char *str, char c);
int my_str_is_alpha(char const *str);
int my_str_is_lower_case(char const *str);
int my_str_is_num(char const *str);
int my_str_is_printable(char const *str);
int my_str_is_upper(char const *str);
char **my_str_to_word_array(char const *str, char separator);
char *my_str_up_case(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest , char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
int my_throw_error(char *error_message);
char *my_unsigned_int_to_str(unsigned int value);
#endif
