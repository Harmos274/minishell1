/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/

#include <stdarg.h>

void my_put_base_nbr(int nb, char *base);
void my_putchar_varg(va_list ap, int *nbc);
void my_put_nbr(int nb);
void my_put_nbr_varg(va_list ap, int *nbc);
void my_putstr_varg(va_list ap, int *nbc);
int my_printf(const char *format, ...);
int match(char format, char *reader);
void pointr(va_list ap, char c, int *nbc);
void my_putchar(char c);
int my_strlen(char const *src);
void my_put_octa_varg(va_list ap, int *nbc);
void my_put_hex_varg(va_list ap, int *nbc);
void my_put_hexcap_varg(va_list ap, int *nbc);
void my_put_bin_varg(va_list ap, int *nbc);
void my_put_base(int nb, char *base, int *nbc);
void my_putstr_scap_varg(va_list ap, int *nbc);
void my_putchar_modulo(va_list ap, int *nbc);
int my_putstr(char const *str, int *nbc);
