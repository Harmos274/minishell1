/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env_shell_two
*/

#include "my_exec.h"
#include "lib.h"

int envar_comp(char *env_line, char *compa)
{
    size_t i = 0;

    while (env_line[i] != '=') {
        if (env_line[i] != compa[i])
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void env_group(char **line_new_env, char **env)
{
    char *compa = "USER\0";
    char *left = "GROUP=\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = my_strconc(left, env[i]);
            return ;
        }
        i++;
    }
}

void env_host(char **line_new_env, char **env)
{
    char *compa = "USER\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = "HOST=localhost\0";
            return ;
        }
        i++;
    }
}
