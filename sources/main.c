/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main
*/

#include "my_exec.h"
#include "lib.h"
#include <unistd.h>

char **oskour_oskour(void)
{
    char **env = malloc(sizeof(char *) * 7);

    env[0] = "HOSTTYPE=x86_64-linux\0";
    env[1] = "VENDOR=unknown\0";
    env[2] = "OSTYPE=linux\0";
    env[3] = "MACHTYPE=x86_64\0";
    env[4] = "SHLVL=1\0";
    env[5] = my_strconc("PWD=\0", getcwd(NULL, 0));
    env[6] = NULL;
    return (env);
}

void shlvl_evol(char ***envp)
{
    ssize_t shlvl = find_my_envar_please(*envp, "SHLVL\0");
    char **flag = NULL;

    if (shlvl == -1) {
        flag = malloc(sizeof(char *) * 4);
        flag[0] = "WESHLVL\0";
        flag[1] = "SHLVL\0";
        flag[2] = "1\0";
        flag[3] = NULL;
        add_envar(flag, envp);
    } else {
        envp[0][shlvl] =  my_strconc("SHLVL=\0", my_itoa
        (my_getnbr(envp[0][shlvl]) + 1));
    }
}

int main(_UNUSED_ int ac, _UNUSED_ char **av, char **envp)
{
    if (envp[0] == NULL)
        envp = oskour_oskour();
    else
        shlvl_evol(&envp);
    if (prompt(envp) == 84)
        return (84);
    return (0);
}