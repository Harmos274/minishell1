/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** disp char of a str
*/

#include "my.h"

void my_putstr_scap_varg(va_list ap, int *nbc)
{
    int a = 0;
    char *str = va_arg(ap, char *);

    while (str[a] != '\0') {
        while (((str[a] < 32) || (str[a] >= 127)) && (str[a] != '\0')) {
            my_printf_putchar('\\');
            my_printf_put_base(str[a], "01234567", nbc);
            a++;
            a++;
        }
        if (str[a] == '\0')
            return;
        my_printf_putchar(str[a]);
        a++;
        *nbc += 1;
    }
}
