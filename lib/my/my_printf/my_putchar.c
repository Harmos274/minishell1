/*
** EPITECH PROJECT, 2018
** my_put_char
** File description:
** put char
*/

#include <unistd.h>

void my_printf_putchar(char c)
{
    write(2, &c, 1);
}
