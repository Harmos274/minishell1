/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** show word array
*/

#include "lib.h"
#include <stdlib.h>

int is_good(char c, char d)
{
    if ((c <= ' ' || c >= 127) || c == d)
        return (0);
    return (1);
}

size_t word_count(char *str, char d)
{
    size_t i = 0;
    size_t word = 0;

    while (str && str[i] != '\0') {
        if (is_good(str[i], d) == 1 && is_good(str[i + 1], d) == 0)
            word = word + 1;
        i = i + 1;
    }
    return (word);
}

char **my_str_to_wordtab(char *str, char d, int prefix)
{
    char **wordtab = malloc(sizeof(char *) * (word_count(str, d) + 1));
    size_t y = 0;
    size_t e = prefix;
    size_t len = 0;

    if (!wordtab)
        return (NULL);
    while (str && str[e] != '\0') {
        if (is_good(str[e], d))
            len = len + 1;
        if (is_good(str[e], d) == 1 && is_good(str[e + 1], d) == 0) {
            wordtab[y] = my_str_alloc(sizeof(char) * (len + 1));
            my_strncpy(wordtab[y], &str[e - len + 1], len);
            len = 0;
            y++;
        }
        e++;
    }
    wordtab[y] = NULL;
    return (wordtab);
}