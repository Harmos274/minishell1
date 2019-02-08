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
    write(1, str, my_strlen(str));
}