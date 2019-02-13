/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr
*/

#include "lib.h"
#include <unistd.h>

void my_putstr(char *str)
{
    size_t i = 0;

    while (str && str[i] != '\0') {
        write(1, &str[i], 1);
        ++i;
    }
}