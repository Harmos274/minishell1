/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** string to number
*/

#include "lib.h"
#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int nb = 0;
    int p = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            n++;
        if (my_char_isnum(str[i]) == 1) {
            nb = (nb * 10 + (str[i] - '0'));
            p++;
            if (my_char_isnum(str[i + 1]) == 0)
                return (nb * my_compute_power_rec(-1, n));
        }
        i++;
    }
    return (0);
}
