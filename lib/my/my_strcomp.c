/*
** EPITECH PROJECT, 2019
** miishell
** File description:
** my_strcomp
*/

#include "lib.h"
#include <stddef.h>

int my_strcomp(char *source, char *compared)
{
    size_t i = 0;

    if (!source || !compared)
        return (84);
    if (my_strlen(source) != my_strlen(compared))
        return (0);
    while (source && source[i] != '\0') {
        if (source[i] != compared[i])
            return (0);
        i++;
    }
    return (1);
}