/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** This programs finds the first pime number greater or
** equal to the number given as a parameter.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int next_nb = nb;

    while (!my_is_prime(next_nb)) {
        next_nb++;
    }
    return (next_nb);
}
