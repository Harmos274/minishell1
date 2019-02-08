/*
** EPITECH PROJECT, 2019
** bootrasp minishell1
** File description:
** my_exec
*/

#include "my_exec.h"
#include "lib.h"
#include <signal.h>

int prompt(char **envp)
{
    ssize_t ret = 0;
    char *stream = NULL;
    size_t n = 0;

    while (ret != -1) {
        my_putstr(getcwd(NULL, 0));
        my_printf(" > ", getcwd(NULL, 0));
        signal(SIGINT, SIG_IGN);
        ret = getline(&stream, &n, stdin);
        if ((ret != -1) && (call_me(stream, &envp) == 84)) {
            return (84);
        }
    }
    write(1, "exit\n", 5);
    return (0);
}