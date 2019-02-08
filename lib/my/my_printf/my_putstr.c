/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** disp char of a str
*/

#include "my.h"

int my_putstr(char const *str, int *nbc)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
        *nbc += 1;
    }
    return (0);
}
