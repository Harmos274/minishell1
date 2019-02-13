/*
** EPITECH PROJECT, 2018
** critest
** File description:
** TEST !
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "source.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stderr_eq_str("hello world\n");
}

Test(my_printf, simple_string_but_with_modd, .init = redirect_all_std)
{
    my_printf("hello %s", "world\n");
    cr_assert_stderr_eq_str("hello world\n");
}

Test(my_printf, simple_string_but_with_modi, .init = redirect_all_std)
{
    my_printf("hello to all the %i worlds\n", 3);
    cr_assert_stderr_eq_str("hello to all the 3 worlds\n");
}

/*
Test(my_printf, simple_string_but_with_modx, .init = redirect_all_std)
{
    my_printf("hello to all the %x worlds\n", 16);
    cr_assert_stderr_eq_str("hello to all the 10 worlds\n");
}
*/

/*
Test(my_printf, simple_string_but_with_modX, .init = redirect_all_std)
{
    my_printf("hello to all the %X worlds\n", 16);
    cr_assert_stderr_eq_str("hello to all the 10 worlds\n");
}

Test(my_printf, simple_string_but_with_modb, .init = redirect_all_std)
{
    my_printf("hello to all the %b worlds\n", 16);
    cr_assert_stderr_eq_str("hello to all the 10000 worlds\n");
}
*/

Test(my_printf, simple_string_but_with_modmod, .init = redirect_all_std)
{
    my_printf("hello to all the %% worlds\n", "tété");
    cr_assert_stderr_eq_str("hello to all the % worlds\n");
}

Test(my_printf, simple_string_but_with_testst, .init = redirect_all_std)
{
    my_printf("hello to all the %s worlds\n", NULL);
    cr_assert_stderr_eq_str("hello to all the (null) worlds\n");
}

Test(my_printf, simple_string_but_with_testst_bla, .init = redirect_all_std)
{
    char *truc = malloc(5000);

    truc[0] = 'l';
    truc[1] = 'a';
    truc[2] = 'p';
    truc[3] = 'i';
    truc[4] = 'n';

    my_printf("hello to all theee %s worlds\n", truc);
    cr_assert_stderr_eq_str("hello to all theee lapin worlds\n");
}

Test(my_printf, more_than_five_args, .init = redirect_all_std)
{
    my_printf("hello %s I'm %d years old, I live at %d %s\n", "world", 18, 62, "rue de landegrand");
    cr_assert_stderr_eq_str("hello world I'm 18 years old, I live at 62 rue de landegrand\n");
}

Test(my_printf, more_simple_char, .init = redirect_all_std)
{
    my_printf("%c%c%c%c%c\n", 'l', 'a', 'p', 'i', 'n');
    cr_assert_stderr_eq_str("lapin\n");
}