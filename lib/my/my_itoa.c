/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_revatoi
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t my_intlen(int nbr)
{
    int x = 10;
    int i = 0;

    if (nbr < 0) {
        nbr = -nbr;
        ++i;
    }
    while (nbr % x != nbr) {
        x *= 10;
        ++i;
    }
    return (i + 1);
}

char *my_itoa(int nbr)
{
    char *str = malloc(sizeof(char) * (my_intlen(nbr) + 2));
    int x = 10;
    int i = 0;
    int cc = 0;

    if (str == NULL)
        return (NULL);
    while ((cc = nbr % x) != nbr) {
        if (cc >= 10)
            cc /= x/10;
        str[i] = cc + '0';
        x *= 10;
        ++i;
    }
    str[i] = nbr/(x/10) + '0';

    return (str);
}