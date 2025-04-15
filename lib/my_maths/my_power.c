/*
** EPITECH PROJECT, 2021
** my_power
** File description:
** This function returns a power b.
*/

long long my_power(long long a, long long b)
{
    long long result = 1;

    for (long long i = 0; i < b; i++)
        result *= a;
    return (result);
}
