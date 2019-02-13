/*
** EPITECH PROJECT, 2018
** my_put_char
** File description:
** put char
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar_varg(va_list ap, int *nbc)
{
    char c = (char)va_arg(ap, int);

    (void)nbc;
    write(2, &c, 1);
    *nbc += 1;
}
