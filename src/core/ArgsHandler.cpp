/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ArgsHandler
*/

#include <string.h>
#include <iostream>
#include <fcntl.h>

int checkLibrary(const char *library)
{
    if (open(library, O_RDONLY) == -1) {
        std::cerr << "Error: library " << library << " not found" << std::endl;
        return 84;
    }
    if (strcmp(strrchr(library, '.'), ".so") != 0)
        return 84;
    return 0;
}

void displayUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t" << "./arcade " << " [library]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tlibrary\t\tlibrary to load" << std::endl;
    std::cout << "NATIVE AVAILABLE LIBRARIES" << std::endl;
    std::cout << "\t./lib/lib_arcade_sfml.so" << std::endl;
    std::cout << "\t./lib/lib_arcade_ncurses.so" << std::endl;
    std::cout << "\t./lib/lib_arcade_sdl2.so" << std::endl;
    std::cout << "Feel free to implement your own library" << std::endl;
}

int checkArgs(int ac, char **av)
{
    if (ac != 2 || !(av && av[1])) {
        displayUsage();
        return 84;
    }
    if (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0) {
        displayUsage();
        return 1;
    }
    if (checkLibrary(av[1]) == 84)
        return 84;
    return 0;
}

int checkEnv(char **env)
{
    if (!env)
        return 84;
    if (!getenv("DISPLAY") || !getenv("XDG_RUNTIME_DIR") || !getenv("TERM") || !getenv("COLORTERM"))
        return 84;
    return 0;
}
