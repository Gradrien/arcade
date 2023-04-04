/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Main
*/

#include "Core.hpp"
#include "Parser.hpp"

int main(int ac, char** av, char** env)
{
    const int returnVal = checkArgs(ac, av);
    if (returnVal == 84 || checkEnv(env) == 84)
        return 84;
    if (returnVal == 1)
        return 0;
    try {
        Core core { av[1] };
        core.coreStateHandler();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}
