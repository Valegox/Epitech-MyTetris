/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** This program returns the first argument raised to the power
** "second argument", recursively.
*/

int multiply_power(int current_result, int nb, int i, int p)
{
    if (i >= p) {
        return (current_result);
    }
    current_result *= nb;
    i++;
    return (multiply_power(current_result, nb, i, p));
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return (0);
    }
    return (multiply_power(1, nb, 0, p));
}
