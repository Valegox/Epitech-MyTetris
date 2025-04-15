/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** This program converts an int to a string.
*/

int is_int(int nb, char *last_digit, int sign)
{
    long long next_nb = nb;

    next_nb = next_nb * 10;
    next_nb = next_nb + (*last_digit - 48);

    if (next_nb > 2147483647 && sign > 0) {
        return (0);
    }
    if (next_nb > 2147483648 && sign < 0) {
        return (0);
    }
    return (1);
}

int is_number(char c)
{
    return (c >= '0' && c <= '9');
}

int get_value(char const *str, int nb, int previous_nb, int sign)
{
    int nb_backup = nb;

    if (is_number(*str)) {
        if (!is_int(nb, (char *)str, sign)) {
            return (0);
        }
        nb = nb * 10;
        nb = nb + (*str - 48);
        return (get_value(str + 1, nb, nb_backup, sign));
    }
    nb = nb * sign;
    return (nb);
}

int get_sign(char const *str, int sign)
{
    if (*str == '-') {
        sign = -sign;
    }
    if (*str == '+' || *str == '-') {
        return (get_sign(str + 1, sign));
    } else if (is_number(*str)) {
        return (get_value(str, 0, 0, sign));
    }
    return (0);
}

int my_get_nbr(char const *str)
{
    int result;

    result = get_sign(str, 1);
    return (result);
}
