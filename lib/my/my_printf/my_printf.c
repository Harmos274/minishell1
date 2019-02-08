/*
** EPITECH PROJECT, 2018
** critest
** File description:
** TEST !
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

void pointr(va_list ap, char c, int *nbc)
{
    void (*ptr[9])(va_list, int *) = {&my_put_nbr_varg, &my_put_nbr_varg,
    &my_putchar_varg, &my_putstr_varg, &my_put_octa_varg, &my_put_hex_varg,
    &my_put_hexcap_varg, &my_put_bin_varg, &my_putstr_scap_varg};
    char ref[10] = "idcsoxXbS\0";
    int tmp = match(c, ref);

    if (c == '%') {
        my_putchar('%');
        return ;
    }
    if (tmp == -1) {
        my_putchar('%');
        my_putchar(c);
        *nbc += 2;
        return ;
    }
    ptr[tmp](ap, nbc);
}

int match(char format, char *reader)
{
    int e = 0;
    int r = my_strlen(reader);

    while (e != r) {
        if (format == reader[e])
            return (e);
        e++;
    }
    return (-1);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int nbc = 0;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%')
            pointr(ap, format[++i], &nbc);
        else {
            my_putchar(format[i]);
            nbc++;
        }
        i++;
    }
    va_end(ap);
    return (nbc);
}
