/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** tests_args
*/

#include "Parser.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(checkArgs, no_args)
{
    char *av[1] = {"./arcade"};
    int ac = 1;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, no_args2)
{
    char **av = NULL;
    int ac = 0;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, bad_args)
{
    char *av[2] = {"./arcade", "wrongarg"};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, wrong_lib)
{
    char *av[2] = {"./arcade", "./lib/lib_caca++.so"};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, one_arg)
{
    char *av[2] = {"./arcade", "./lib/arcade_sfml.so"};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 0);
}

Test(checkArgs, two_args)
{
    char *av[3] = {"./arcade", "./lib/arcade_sfml.so", "./lib/arcade_ncurses.so"};
    int ac = 3;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, help) {
    char *av[2] = {"./arcade", "-h"};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 0);
}
