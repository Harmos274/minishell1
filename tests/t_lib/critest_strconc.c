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

Test(my_strconc, simple_test_without_trap)
{
    char *left = "Then you're left in the dust\0";
    char *in_the_dust = "Unless I stuck by ya\0";
    char *complete = my_strconc(left, in_the_dust);

    cr_assert(complete != NULL);
    cr_assert_str_eq(complete,
        "Then you're left in the dustUnless I stuck by ya\0");
}

Test(my_strconc, test_with_spaces_on_beginning_and_end)
{
    char *left = "Then you're left in  \t the dust\0";
    char *in_the_dust = "   \tUnless I stuck by ya\0";
    char *complete = my_strconc(left, in_the_dust);

    cr_assert(complete != NULL);
    cr_assert_str_eq(complete,
        "Then you're left in  \t the dust   \tUnless I stuck by ya\0");
}

Test(my_strconc, test_with_null_string)
{
    char *left = NULL;
    char *in_the_dust = NULL;
    char *complete = my_strconc(left, in_the_dust);

    cr_assert(complete == NULL);
}

Test(my_strconc, test_with_left_null)
{
    char *left = NULL;
    char *in_the_dust = "aaaaaaa";
    char *complete = my_strconc(left, in_the_dust);

    cr_assert(complete == NULL);
}

Test(my_strconc, test_with_in_the_dust_null)
{
    char *left = "aaaaaaa";
    char *in_the_dust = NULL;
    char *complete = my_strconc(left, in_the_dust);

    cr_assert(complete == NULL);
}
