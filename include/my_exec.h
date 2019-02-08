/*
** EPITECH PROJECT, 2019
** bootstrap minishell1
** File description:
** my_exec
*/

#ifndef MY_EXEC_H_
    #define MY_EXEC_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include "enum.h"

    char **clean_env(char **envp);
    void env_group(char **line_new_env, char **env);
    void env_host(char **line_new_env, char **env);
    int envar_comp(char *env_line, char *compa);
    int call_me(char *stream, char ***envp);
    void go_to_home(char ***env);

    int built_in_command(char *com, char **flag, char ***envp);
    void bi_cd(char *com, char **flag, char ***env);
    void bi_env(char *com, char **flag, char ***env);
    void bi_setenv(char *com, char **flag, char ***env);
    void bi_unsetenv(char *com, char **flag, char ***env);
    void bi_exit(char *com, char **flag, char ***env);
    int prompt(char **envp);
    void add_envar(char **flag, char ***env);
    void go_to_pwd(char ***env);
    ssize_t find_my_envar_please(char **env, char *envar);
    void remove_envar(char **flag, char ***env);
    char **make_pwd(char *str);

#endif /* !MY_EXEC_H_ */