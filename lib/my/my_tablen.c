/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_tablen
*/

#include <stddef.h>
#include <unistd.h>

ssize_t my_tablen(char **tab)
{
    size_t i = 0;

    if (tab == NULL) {
        return (-1);
    }
    while (tab && tab[i] != NULL) {
        ++i;
    }
    return (i);
}