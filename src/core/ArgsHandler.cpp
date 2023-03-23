/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ArgsHandler
*/

#include <string.h>
#include <iostream>
#include <fcntl.h>

static int checkLibrary(const char *library)
{
    if (open(library, O_RDONLY) == -1) {
        std::cerr << "Error: library " << library << " not found" << std::endl;
        return 84;
    }
    if (strcmp(strrchr(library, '.'), ".so") != 0)
        return 84;
    return 0;
}

int checkArgs(int ac, char **av)
{
    if (ac != 2 || !(av && av[1]))
        return 84;
    if (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0) {
        std::cout << "USAGE: ./arcade [lib_name.so]" << std::endl;
        std::cout << "\tlib_name.so  ->  name of the library" << std::endl;
        return 0;
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
