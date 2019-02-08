/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** clean_str
*/

#include <stddef.h>

void clean_str(char *str)
{
    size_t i = 0;
    size_t e = 0;

    while (str && str[i]) {
        if ((str[i] != ' ') || (i > 0 && str[i - 1] != ' '))
            str[e++] = str[i];
        i++;
    }
    str[e] = '\0';
}