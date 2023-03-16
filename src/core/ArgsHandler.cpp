/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ArgsHandler
*/

#include <string.h>
#include <iostream>
#include <fcntl.h>

static int check_library(const char *library)
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
    if (check_library(av[1]) == 84)
        return 84;
    return 0;
}