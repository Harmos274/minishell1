/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_alloc
*/

#include <stddef.h>
#include <stdlib.h>

char **my_tab_alloc(size_t size)
{
    char **tab = malloc(size);
    size_t i = 0;

    if (tab == NULL)
        return (NULL);
    while (i != size) {
        tab[i] = NULL;
        i++;
    }
    return (tab);
}

char *my_str_alloc(size_t size)
{
    char *str = malloc(size);
    size_t i = 0;

    if (str == NULL)
        return (NULL);
    while (i != size) {
        str[i] = '\0';
        i++;
    }
    return (str);
}