/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include "my.h"
#include <stdarg.h>

void my_put_nbr_varg(va_list ap, int *nbc)
{
    int power = 1;
    int ab = 0;
    int c = 0;
    int nb = va_arg(ap, int);

    while ((nb / power) > 10)
        power = power * 10;

    while (power > 0) {
        c = nb % power;
        ab = (nb - c) / power;
        my_printf_putchar(ab + '0');
        *nbc += 1;
        nb = c;
        power = power / 10;
        ab = 0;
    }
}
