/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** bi_setenv_fn
*/

#include "lib.h"
#include <stddef.h>

char *create_envar(char *envar, char *def)
{
    char *complete_envar = my_str_alloc(sizeof(char) *
    (my_strlen(envar) + my_strlen(def) + 2));
    size_t i = 0;
    size_t e = 0;

    while (envar && envar[i] != '\0') {
        complete_envar[i] = envar[i];
        ++i;
    }
    complete_envar[i] = '=';
    ++i;
    while (def && def[e] != '\0') {
        complete_envar[i] = def[e];
        ++i;
        ++e;
    }
    return (complete_envar);
}

void add_envar(char **flag, char ***env)
{
    size_t i = my_tablen(*env);
    char **new_env = malloc(sizeof(char *) * (i + 2));

    if (new_env == NULL)
        return ;
    i = 0;
    while (env[0][i] != NULL) {
        new_env[i] = env[0][i];
        ++i;
    }
    new_env[i] = create_envar(flag[1], flag[2]);
    new_env[i + 1] = NULL;
    env[0] = new_env;
}