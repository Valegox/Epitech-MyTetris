/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** This program returns 1 if the argument is prime, else 0.
*/

int my_is_prime(int nb)
{
    if (nb == 1 || nb < 0) {
        return (0);
    }
    for (int i = 2; i <= 9; i++) {
        if (nb % i == 0 && nb != i) {
            return (0);
        }
    }
    return (1);
}
