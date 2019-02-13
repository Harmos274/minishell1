/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my_str_isnum
*/

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int e = 0;

    while (str[e] != '\0')
    {
        if (my_char_isnum(str[e]) == 1)
            e++;
        else
            return (0);
    }
    return (1);
}
