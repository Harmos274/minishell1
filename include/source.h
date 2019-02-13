/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#ifndef SOURCE_H_
    #define SOURCE_H_

    char *make_path(char *path, char **env_path);
    char *my_pathconc(char *left, char *right);
    char *grepath(char **envp);
    int envar_comp(char *env_line, char *compa);
#endif /* !SOURCE_H_ */
