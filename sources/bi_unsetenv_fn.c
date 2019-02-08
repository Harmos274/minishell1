/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** bi_unsetenv_fn
*/

#include <stddef.h>
#include "my_exec.h"

void rip_envar(char *envar, char ***env)
{
    ssize_t envpos = find_my_envar_please(env[0], envar);

    if (envpos == -1)
        return ;
    env[0][envpos][0] = '\0';
}

void remove_envar(char **flag, char ***env)
{
    size_t i = 1;

    while (flag[i] != NULL) {
        rip_envar(flag[i], env);
        ++i;
    }
}