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

Test(my_str_to_wordarray, simple_space_separator)
{
    char *str = "Roses are red, violet are blue, Omae wa mo shindeiru\n";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, simple_TAB_separator)
{
    char *str = "Roses\tare\tred,\tviolet\tare\tblue,\tOmae\twa\tmo\tshindeiru\n";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, simple_space_and_TAB_separator)
{
    char *str = "Roses\tare red,\tviolet are\tblue, Omae\twa mo shindeiru\n";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, complex_space_separator)
{
    char *str = "Roses     are red,    violet    are blue,"
    "    Omae    wa  mo shindeiru\n";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, complex_space_and_TAB_separator)
{
    char *str = "Roses\t  are\t   red, \t\tviolet are "
    "\tblue, Omae wa mo\t\t\t shindeiru\n";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, character_separator_double_bunk_point)
{
    char *str = "Roses:are:red,:violet:are:blue,:Omae:wa:mo:shindeiru:";
    char **tab = my_str_to_wordarray(str, ':', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, character_separator_double_bunk_point_and_space)
{
    char *str = "Roses:  are:  red,:\t  "
    "violet:are:   blue,:Omae:wa:   \tmo:    \t   shindeiru:";
    char **tab = my_str_to_wordarray(str, ':', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_to_wordarray, character_separator_is_TAB)
{
    char *str = "Roses:  are:  red,:\t  "
    "violet:are:   blue,:Omae:wa:   \tmo:    \t   shindeiru:";
    char **tab = my_str_to_wordarray(str, '\t', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses:\nare:\nred,:\nviolet:are:\nblue,:Omae:wa:\nmo:\nshindeiru:\n");
}

Test(my_str_to_wordarray, test_command_proto)
{
    char *str = "ls\t -l  \t-R       \t-r\t -a";
    char **tab = my_str_to_wordarray(str, '\t', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "ls\n-l\n-R\n-r\n-a\n");
}

Test(my_str_to_wordarray, test_command_proto_with_one_word)
{
    char *str = "ls";
    char **tab = my_str_to_wordarray(str, '\t', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "ls\n");
}

Test(my_str_to_wordarray, many_spaces_at_the_end_of_a_line)
{
    char *str = "ls       ";
    char **tab = my_str_to_wordarray(str, ' ', 0);
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "ls\n");
}