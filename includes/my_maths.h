/*
** EPITECH PROJECT, 2021
** My maths lib
** File description:
** This file contains all the prototypes of my maths lib.
*/

#ifndef MY_MATHS
    #define MY_MATHS
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_get_nb_length(unsigned int value);
int my_is_prime(int nb);
long long my_power(long long a, long long b);
char *my_unsigned_nbr_to_base(unsigned int nb, char *base_digits);
#endif
