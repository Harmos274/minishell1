/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count cases
*/

int my_printf_strlen(char const *src)
{
    int i = 0;

    if (!src)
        return (-1);
    while (src[i] != '\0')
        ++i;
    return (i);
}
