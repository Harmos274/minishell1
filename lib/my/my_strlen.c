/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strlen
*/

#include <lib.h>
#include <unistd.h>

ssize_t my_strlen(char const *str)
{
    ssize_t i = 0;

    if (!str)
        return (-1);
    while (str && str[i] != '\0') {
        i++;
    }
    return (i);
}