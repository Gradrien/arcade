/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ArgsHandler
*/

#include <string.h>
#include <iostream>

static int check_library(const char *library)
{
    if (strcmp(library, "./lib/arcade_ncurses.so")
    && strcmp(library, "./lib/arcade_sfml.so")
    && strcmp(library, "./lib/arcade_sdl2.so")
    && strcmp(library, "./lib/arcade_ndk++.so")
    && strcmp(library, "./lib/arcade_aalib.so")
    && strcmp(library, "./lib/arcade_libcaca.so")
    && strcmp(library, "./lib/arcade_allegro5.so")
    && strcmp(library, "./lib/arcade_xlib.so")
    && strcmp(library, "./lib/arcade_gtk+.so")
    && strcmp(library, "./lib/arcade_irrlicht.so")
    && strcmp(library, "./lib/arcade_opengl.so")
    && strcmp(library, "./lib/arcade_vulkan.so")
    && strcmp(library, "./lib/arcade_qt5.so"))
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