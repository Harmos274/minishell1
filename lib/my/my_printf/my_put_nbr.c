/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include "my.h"

void my_put_base_nbr(int nb, char *base)
{
    if (nb / (my_strlen(base) - 1) != 0)
        my_put_base_nbr(nb / (my_strlen(base) -1) , base);
    my_putchar(base[nb % (my_strlen(base) - 1)]);
}

void my_put_nbr(int nb)
{
    my_put_base_nbr(nb, "0123456789\0");
}
