/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** bi_command
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "my_exec.h"
#include "lib.h"

void bi_cd(_UNUSED_ char *com, char **flag, char ***env)
{
    static char *oldpwd = NULL;

    if (my_tablen(flag) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return ;
    }
    if (flag[1] == NULL) {
        oldpwd = getcwd(NULL, 0);
        go_to_home(env);
    }
    else if (flag[1][0] != '-' && (oldpwd = getcwd(NULL, 0))
    && chdir(flag[1]) != 0)
        my_printf("%s: %s.\n", flag[1], strerror(errno));
    else {
        if (flag[1][0] == '-')
            chdir(oldpwd);
        go_to_pwd(env);
    }
}

void bi_env(_UNUSED_ char *com, _UNUSED_ char **flag, char ***env)
{
    my_printab(*env);
}

void bi_setenv(char *com, char **flag, _UNUSED_ char ***env)
{
    if (flag[1] == NULL)
        bi_env(com, flag, env);
    else {
        add_envar(flag, env);
    }
}

void bi_unsetenv(_UNUSED_ char *com, char **flag, _UNUSED_ char ***env)
{
    if (flag[1] == NULL)
        write(2, "unsetenv: Too few arguments.\n", 29);
    else {
        remove_envar(flag, env);
    }
}

void bi_exit(_UNUSED_ char *com, _UNUSED_ char **flag, _UNUSED_ char ***env)
{
    write(1, "exit", 5);
    exit (0);
}
