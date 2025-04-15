/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** This program returns the square root
** of a number given as argument.
*/

int my_compute_square_root(int nb)
{
    if (nb == 1) {
        return (1);
    }
    for (int i = 0; i <= nb / 2; i++) {
        if (i * i == nb) {
            return (i);
        }
        if (i * i > nb) {
            return (0);
        }
    }
    return (0);
}
