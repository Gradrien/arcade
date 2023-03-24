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
    const char *av1 = "./arcade";
    char *av[1] = {const_cast<char*>(av1)};
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
    const char *av1 = "./arcade";
    const char *av2 = "wrongarg";
    char *av[2] = {const_cast<char*>(av1), const_cast<char*>(av2)};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, wrong_lib)
{
    const char *av1 = "./arcade";
    const char *av2 = "./lib/lib_caca++.so";
    char *av[2] = {const_cast<char*>(av1), const_cast<char*>(av2)};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, wrong_lib2)
{
    const char *av1 = "./arcade";
    const char *av2 = "./lib/arcade_sfml.html";
    char *av[2] = {const_cast<char*>(av1), const_cast<char*>(av2)};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, one_arg)
{
    const char *av1 = "./arcade";
    const char *av2 = "./lib/arcade_sfml.so";
    char *av[2] = {const_cast<char*>(av1), const_cast<char*>(av2)};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 0);
}

Test(checkArgs, two_args)
{
    const char *av1 = "./arcade";
    const char *av2 = "./lib/arcade_sfml.so";
    const char *av3 = "./lib/arcade_ncurses.so";
    char *av[3] = {const_cast<char*>(av1), const_cast<char*>(av2), const_cast<char*>(av3)};
    int ac = 3;

    cr_assert_eq(checkArgs(ac, av), 84);
}

Test(checkArgs, help) {
    const char *av1 = "./arcade";
    const char *av2 = "-h";
    char *av[2] = {const_cast<char*>(av1), const_cast<char*>(av2)};
    int ac = 2;

    cr_assert_eq(checkArgs(ac, av), 0);
}

Test(checkEnv, no_env)
{
    char **env = NULL;

    cr_assert_eq(checkEnv(env), 84);
}

Test(checkEnv, good_env)
{
    char *env[6] = {const_cast<char*>("XDG_RUNTIME_DIR=/run/user/1000"),
                    const_cast<char*>("TERM=xterm-256color"),
                    const_cast<char*>("COLORTERM=truecolor"),
                    const_cast<char*>("SHELL=/bin/bash"),
                    const_cast<char*>("DISPLAY=:0.0"),
                    NULL};

    cr_assert_eq(checkEnv(env), 0);
}

