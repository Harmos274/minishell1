/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strlen
*/

#include <lib.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    if (!str)
        return (84);
    while (str && str[i] != '\0') {
        i++;
    }
    return (i);
}