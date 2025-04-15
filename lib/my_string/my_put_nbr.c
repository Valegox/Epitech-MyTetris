/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** This program displays the number given as parameter.
*/

int my_putchar(char c);

int put_digit(int nb)
{
    int digit_to_display = nb;
    int next_nb;

    while (digit_to_display >= 10) {
        digit_to_display = digit_to_display % 10;
    }
    next_nb = nb - digit_to_display;
    next_nb = next_nb / 10;
    if (next_nb >= 1) {
        put_digit(next_nb);
    }
    my_putchar(digit_to_display + 48);
    return (0);
}

int put_sign(int nb)
{
    if (nb < 0) {
        my_putchar('-');
    }
    return (0);
}

int get_abs(int nb)
{
    if (nb < 0) {
        return (-1 * nb);
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    put_sign(nb);
    if (nb == -2147483648) {
        nb = nb / 10;
        put_digit(get_abs(nb));
        my_putchar('8');
    } else {
        put_digit(get_abs(nb));
    }
    return (0);
}
