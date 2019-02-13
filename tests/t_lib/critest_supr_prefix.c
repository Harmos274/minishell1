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
#include <unistd.h>

Test(supr_prefix, simple_supr)
{
    char *string = "I love the curry, because it's very good.\0";
    char *result = supr_prefix(string, "I love the cury");

    cr_assert(result != NULL);
    cr_assert_str_eq(result,
        "y, because it's very good.\0");
}

Test(supr_prefix, simple_supr_with_false_prefix)
{
    char *string = "I love the curry, because it's very good.\0";
    char *result = supr_prefix(string, "jsqkfldsfI love the cury");

    cr_assert(result != NULL);
    cr_assert_str_eq(result,
        "e it's very good.\0");
}

Test(supr_prefix, with_null_string)
{
    char *string = NULL;
    char *result = supr_prefix(string, "jsqkfldsfI love the cury");

    cr_assert(result == NULL);
}

Test(supr_prefix, with_null_result)
{
    char *string = "hello";
    char *result = supr_prefix(string, NULL);

    cr_assert(result == NULL);
}
