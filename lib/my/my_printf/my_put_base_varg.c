/*
** EPITECH PROJECT, 2018
** put_base
** File description:
** put thing into base something
*/

#include <stdarg.h>
#include "my.h"

void my_put_bin_varg(va_list ap, int *nbc)
{
    char base[3] = "01\0";
    int nb = va_arg(ap, int);

    my_printf_put_base(nb, base, nbc);
}

void my_put_hex_varg(va_list ap, int *nbc)
{
    char base[17] = "0123456789abcdef\0";
    int nb = va_arg(ap, int);

    my_printf_put_base(nb, base, nbc);
}

void my_put_hexcap_varg(va_list ap, int *nbc)
{
    char base[17] = "0123456789ABCDEF\0";
    int nb = va_arg(ap, int);

    my_printf_put_base(nb, base, nbc);
}

void my_put_octa_varg(va_list ap, int *nbc)
{
    char base[9] = "01234567\0";
    int nb = va_arg(ap, int);

    my_printf_put_base(nb, base, nbc);
}
