/*
** EPITECH PROJECT, 2019
** minishell1 (cricri)
** File description:
** critest_str_to_wordarr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "lib.h"
#include "source.h"
#include <unistd.h>

char **env_path(void)
{
    char **env = malloc(sizeof(char *) * 7);

    env[0] = "/usr/local/bin\0";
    env[1] = "/usr/bin\0";
    env[2] = "/bin\0";
    env[3] = "/usr/local/sbin\0";
    env[4] = "NULL\0";
    env[5] = "NULL\0";
    env[6] = NULL;
    return (env);
}

char **env_without_path(void)
{
    char **env = malloc(sizeof(char *) * 7);

    env[0] = "ENV=blabla\0";
    env[1] = "TOTO=TATA\0";
    env[2] = "PA_PATH=TUTUTUTUTUTUUTU\0";
    env[3] = "MIROIR=MIROIR_MON_BEAU_MIROIR\0";
    env[4] = "QUI=EST_LE_PLUS_BEAU\0";
    env[5] = "PAS=ANTOINE\0";
    env[6] = NULL;
    return (env);
}

char **env_with_path(void)
{
    char **env = malloc(sizeof(char *) * 7);

    env[0] = "ENV=blabla\0";
    env[1] = "TOTO=TATA\0";
    env[2] = "PATH=TUTU\0";
    env[3] = "MIROIR=MIROIR_MON_BEAU_MIROIR\0";
    env[4] = "QUI=EST_LE_PLUS_BEAU\0";
    env[5] = "PAS=ANTOINE\0";
    env[6] = NULL;
    return (env);
}

Test(make_path, simple_test_without_trap)
{
    char **env = env_path();
    char *binary_path = make_path("ls", env);

    cr_assert(env != NULL);
    cr_assert_str_eq(binary_path,
        "/usr/bin/ls\0");
}

Test(make_path, simple_test_with_NULL)
{
    char **env = env_path();
    char *binary_path = make_path(NULL, env);

    cr_assert(env != NULL && binary_path == NULL);
}

Test(grepath, simple_test_with_normal_env)
{
    char **env = env_with_path();
    char *str = grepath(env);

    cr_assert(env != NULL && str != NULL);
    cr_assert_str_eq(str,
        "PATH=TUTU");
}

Test(grepath, simple_test_with_NULL_env)
{
    char **env = env_with_path();
    char *str = grepath(NULL);

    cr_assert(env != NULL && str == NULL);
    free(str);
}

Test(grepath, simple_test_with_no_path_env)
{
    char **env = env_without_path();
    char *str = grepath(env);

    cr_assert(env != NULL && str == NULL);
}

Test(my_pathconc, simple_test)
{
    char *str = my_pathconc("/bin", "ls");

    cr_assert(str != NULL);
    cr_assert_str_eq(str,
        "/bin/ls");
    free(str);
}

Test(my_pathconc, test_without_right)
{
    char *str = my_pathconc(NULL, "ls");

    cr_assert(str != NULL);
    cr_assert_str_eq(str,
        "ls");
}

Test(envar_comp, simple_test)
{
    int i = envar_comp("PATH=azea\0", "PATH\0");

    cr_assert(i == 1);
}

Test(envar_comp, simple_test_false)
{
    int i = envar_comp("PATH=azea\0", "ePATH\0");

    cr_assert(i == 0);
}

Test(envar_comp, null_left)
{
    int i = envar_comp(NULL, "ePATH\0");

    cr_assert(i == 84);
}

Test(envar_comp, null_right)
{
    int i = envar_comp("PASTABOX", NULL);

    cr_assert(i == 84);
}

Test(envar_comp, null_right_and_left)
{
    int i = envar_comp(NULL, NULL);

    cr_assert(i == 84);
}