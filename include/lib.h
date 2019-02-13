/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stddef.h>
    #include <stdlib.h>

    ssize_t my_strlen(char const *str);
    char *my_strconc(char *left, char *env_line);
    int my_strcomp(char *source, char *compared);
    void my_putstr(char *str);
    char *my_strncpy(char *dest, char *src, size_t n);
    char **my_str_to_wordarray(char *str, char d, int prefix);
    void my_printab(char **tab);
    char **my_tab_alloc(size_t size);
    char *my_str_alloc(size_t size);
    ssize_t my_tablen(char **tab);
    char *supr_prefix(char *str, char *prefix);
    int my_printf(const char *format, ...);
    int my_getnbr(char const *str);
    char *my_itoa(int nbr);
    int my_char_isnum(char c);
    int my_compute_power_rec (int nb, int p);

#endif /* !LIB_H_ */
