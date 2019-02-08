/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** chained_list
*/

#ifndef CHAINED_LIST_H_
    #define CHAINED_LIST_H_

    #include <stddef.h>
    #include <stdlib.h>


    typedef struct save_list_s save_list_t;
    struct save_list_s
    {
        chained_env_t *first;
        int nbr_elmnt;
    };

    typedef struct chained_env_s chained_env_t;
    struct chained_env_s
    {
        char *envar;
        chained_env_t *next;
    };

#endif /* !CHAINED_LIST_H_ */
