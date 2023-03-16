/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Main
*/

#include "Parser.hpp"
#include "DLLoader.hpp"
#include "IGraphic.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    // if (checkArgs(ac, av) == 84)
    // return 84;
    DLLoader<IGraphic> testLoader;
    std::unique_ptr<IGraphic> graphLib = testLoader.getInstance("./lib/arcade_sfml.so");
    graphLib->createWindow( "Allo ca marche ?", 400, 400);
    while (1) {
        graphLib->displayWindow();
    }
    return 0;
}
