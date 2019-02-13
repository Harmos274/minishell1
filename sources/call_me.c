/*
** EPITECH PROJECT, 2019
** miishel
** File description:
** call_me
*/

#include "my_exec.h"
#include "lib.h"
#include "enum.h"
#include <sys/wait.h>
#include <sys/types.h>

char *my_pathconc(char *left, char *right)
{
    char *str = my_str_alloc(sizeof(char) *
    (my_strlen(left) + my_strlen(right) + 2));
    size_t i = 0;
    size_t e = 0;

    if (str == NULL || left == NULL || right == NULL)
        return (right);
    while (left && (left[i] != '\0')) {
        str[i] = left[i];
        ++i;
    }
    str[i] = '/';
    ++i;
    while (right && right[e] != '\0') {
        str[i] = right[e];
        ++e;
        ++i;
    }
    str[i] = '\0';
    return (str);
}

char *make_path(char *path, char **env_path)
{
    size_t i = 0;

    if (access(path, X_OK) == 0 || path == NULL)
        return (path);
    while (env_path[i] != NULL) {
        if (access(my_pathconc(env_path[i], path), X_OK) == 0) {
            return (my_pathconc(env_path[i], path));
        }
        ++i;
    }
    return (path);
}

void my_exec(char **env_path, char *path, char **flag, char **envp)
{
    pid_t child_pid = fork();
    int stat_val = 0;

    path = make_path(path, env_path);
    flag[0] = path;
    if (child_pid == -1)
        exit (ERROR);
    else if (child_pid == 0) {
        if (execve(path, flag, envp) == -1) {
            my_printf("%s: Command not found.\n", path);
            exit (0);
        }
    } else {
        waitpid(child_pid, &stat_val, 0);
        kill(child_pid, 0);
        if (WIFSIGNALED(stat_val)) {
            if (WCOREDUMP(stat_val))
                write(2, "Segmentation fault (core dumped)\n", 33);
        }
    }
}

char *grepath(char **envp)
{
    size_t i = 0;

    while (envp && envp[i] != NULL) {
        if (envar_comp(envp[i], "PATH") == TRUE) {
            return (envp[i]);
        }
        ++i;
    }
    return (NULL);
}

int call_me(char *stream, char ***envp)
{
    char **env_path = NULL;
    char **arg = NULL;

    if (stream[0] == '\n')
        return (0);
    env_path = my_str_to_wordarray(grepath(*envp), ':', 5);
    arg = my_str_to_wordarray(stream, ' ', 0);
    if (built_in_command(arg[0], arg, envp) == -1)
        my_exec(env_path, arg[0], arg, *envp);
    return (0);
}