/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** bi_cd_fn
*/

#include "my_exec.h"
#include "lib.h"
#include <stddef.h>
#include <unistd.h>

ssize_t find_my_envar_please(char **env, char *envar)
{
    ssize_t i = 0;

    while (env[i] != NULL) {
        if (envar_comp(env[i], envar) == TRUE) {
            return (i);
        }
        ++i;
    }
    return (-1);
}

char **make_pwd(char *str)
{
    char **pwd = malloc(sizeof(char *) * (4));

    if (pwd == NULL)
        return (NULL);
    pwd[0] = "OOF\0";
    pwd[1] = "PWD\0";
    pwd[2] = str;
    pwd[3] = NULL;
    return (pwd);
}

void go_to_home(char ***env)
{
    size_t i = 0;
    ssize_t pwd = find_my_envar_please(*env, "PWD\0");

    while (env[0][i] != NULL) {
        if (envar_comp(env[0][i], "HOME=\0") == TRUE) {
            if (pwd == (-1)) {
                add_envar(make_pwd(getcwd(NULL, 0)), env);
                return ;
            }
            env[0][pwd] =  my_strconc("PWD=\0", supr_prefix(env[0][i],
            "HOME=\0"));
            chdir(supr_prefix(env[0][pwd], "PWD="));
            return ;
        }
        ++i;
    }
    write(2, "cd: No home directory.\n", 23);
}

void go_to_pwd(char ***env)
{
    ssize_t pwd = find_my_envar_please(*env, "PWD\0");

    if (pwd == (-1))
        add_envar(make_pwd(getcwd(NULL, 0)), env);
    env[0][pwd] = my_strconc("PWD=\0", getcwd(NULL, 0));
}