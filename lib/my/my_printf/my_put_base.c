/*
** EPITECH PROJECT, 2018
** put_base
** File description:
** put thing into base something
*/

#include "my.h"

void my_put_base(int nb, char *base, int *nbc)
{
    if (nb / (my_strlen(base) - 1) != 0)
        my_put_base(nb / (my_strlen(base) -1) , base, nbc);
    my_putchar(base[nb % (my_strlen(base) - 1)]);
    *nbc += 1;
}
