/*
** EPITECH PROJECT, 2019
** minishel
** File description:
** built_in
*/

#include "my_exec.h"
#include "lib.h"

char **create_bi_tab(void)
{
    char **bi_tab = malloc(sizeof(char *) * 6);

    bi_tab[0] = "cd\0";
    bi_tab[1] = "env\0";
    bi_tab[2] = "setenv\0";
    bi_tab[3] = "unsetenv\0";
    bi_tab[4] = "exit\0";
    bi_tab[5] = NULL;
    return (bi_tab);
}

int bi_comp(char *path)
{
    char **comp_tab = create_bi_tab();
    size_t i = 0;

    while (comp_tab[i] != NULL) {
        if (my_strcomp(path, comp_tab[i]) == 1) {
            return (i);
        }
        i++;
    }
    return (-1);
}

int built_in_command(char *com, char **flag, char ***envp)
{
    int i = bi_comp(com);
    void (*ptr[5])(char *, char **, char ***) = {&bi_cd, &bi_env,
    &bi_setenv, &bi_unsetenv, &bi_exit};

    if (i == -1)
        return (-1);
    ptr[i](com, flag, envp);
    return (0);
}