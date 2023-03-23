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

static int checkLine(char *str)
{
    char *keyword = NULL;

    if (!str)
        return 84;
    keyword = strtok(str, "=");
    if (strcmp(keyword, "DISPLAY") != 0 && strcmp(keyword, "XDG_RUNTIME_DIR") && strcmp(keyword, "TERM"))
        return 84;
    return EXIT_SUCCESS;
}

int checkEnv(char **env)
{
    if (!env)
        return 84;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (checkLine(env[i]) == 0)
            return EXIT_SUCCESS;
    }
    return 84;
}
