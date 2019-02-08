/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** disp char of a str
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>

void my_putstr_varg(va_list ap, int *nbc)
{
    int a = 0;
    char *str = va_arg(ap, char *);

    if (str == NULL) {
        my_putstr("(null)", nbc);
        return ;
    }
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
        *nbc += 1;
    }
}
