/*
** EPITECH PROJECT, 2018
** put_base
** File description:
** put thing into base something
*/

#include "my.h"

void my_printf_put_base(int nb, char *base, int *nbc)
{
    if (nb / (my_printf_strlen(base) - 1) != 0)
        my_printf_put_base(nb / (my_printf_strlen(base) -1) , base, nbc);
    my_printf_putchar(base[nb % (my_printf_strlen(base) - 1)]);
    *nbc += 1;
}
