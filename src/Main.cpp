/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Main
*/

#include "core/Parser.hpp"

int main(int ac, char **av)
{
    if (checkArgs(ac, av) == 84)
        return 84;
    return 0;
}
