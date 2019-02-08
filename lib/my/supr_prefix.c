/*
** EPITECH PROJECT, 2019
** lib
** File description:
** supr_prefix
*/

#include "lib.h"
#include <stddef.h>
#include <stdio.h>

char *supr_prefix(char *str, char *prefix)
{
    char *new_str = my_str_alloc(sizeof(char) * (my_strlen(str)));
    size_t i = 0;
    size_t j = my_strlen(prefix);

    if (new_str == NULL)
        return (NULL);
    while (str && str[j] != '\0') {
        new_str[i] = str[j];
        ++i;
        ++j;
    }
    return (new_str);
}