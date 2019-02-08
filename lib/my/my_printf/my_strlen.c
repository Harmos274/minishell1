/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count cases
*/

int my_strlen(char const *src)
{
    int i = 0;

    while (src[i++] != '\0')
        i++;
    return (i);
}
