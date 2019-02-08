/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env_shell
*/

#include "my_exec.h"

void env_shlvl(char **line_new_env, char **env)
{
    char *compa = "SHLVL\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = env[i];
            return ;
        }
        i++;
    }
}

void env_pwd(char **line_new_env, char **env)
{
    char *compa = "PWD\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = env[i];
            return ;
        }
        i++;
    }
}

void env_user(char **line_new_env, char **env)
{
    char *compa = "USER\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = env[i];
            return ;
        }
        i++;
    }
}

void env_logname(char **line_new_env, char **env)
{
    char *compa = "LOGNAME\0";
    size_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], compa) == TRUE) {
            *line_new_env = env[i];
            return ;
        }
        i++;
    }
}

char **clean_env(char **envp)
{
    char **new_env = malloc(sizeof(char *) * 11);
    void (*ptr[6])(char **, char **) = {&env_shlvl, &env_pwd,
    &env_logname, &env_user, &env_group, &env_host};
    size_t i = 4;

    if (new_env == NULL)
        return (NULL);
    new_env[0] = "HOSTTYPE=x86_64-linux\0";
    new_env[1] = "VENDOR=unknown\0";
    new_env[2] = "OSTYPE=linux\0";
    new_env[3] = "MACHTYPE=x86_64\0";
    while (i != 10) {
        ptr[i - 4](&new_env[i], envp);
        i++;
    }
    new_env[11] = NULL;
    return (new_env);
}
