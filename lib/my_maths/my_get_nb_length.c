/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** This function returns the length of an int.
*/

int my_get_nb_length(unsigned int value)
{
    int count = 0;

    while (value != 0) {
        value /= 10;
        count++;
    }
    return (count);
}
