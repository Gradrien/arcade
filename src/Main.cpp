/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Main
*/

#include "Parser.hpp"
#include "Core.hpp"

int main(int ac, char **av)
{
    if (checkArgs(ac, av) == 84)
        return 84;
    Core{av[1]};
    return 0;
}
