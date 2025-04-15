/*
** EPITECH PROJECT, 2021
** my_get_nbr_base
** File description:
** This function converts a decimal number to a decimal number to a base.
*/

#include "my_maths.h"
#include "my_string.h"
#include <stdlib.h>

int my_strlen(char const *str);

char *my_unsigned_nbr_to_base(unsigned int nb, char *base_digits) {
  int base = my_strlen(base_digits);
  char *result = malloc(sizeof(char) * 64);

  if (nb == 0)
    return ("0");
  for (int i = 0; i < 64; i++)
    result[i] = '\0';
  for (int j = 0; nb > 0; j++) {
    result[j] = base_digits[(nb % my_power(base, j + 1)) / my_power(base, j)];
    nb -= (nb % my_power(base, j + 1));
  }
  my_revstr(result);
  return (result);
}
