/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

void Menu::menuLoopHandler(std::unique_ptr<IGraphic> &graphLib, Core *core)
{
    text avLib;
    avLib.fontSize = 30;
    avLib.fontPath = "assets/fonts/arial.ttf";
    avLib.m_color = {255, 255, 255, 255};
    avLib.pos = {20, 130};
    avLib.text = "Available libraires";
    text avGame;
    avGame.fontSize = 30;
    avGame.fontPath = "assets/fonts/arial.ttf";
    avGame.m_color = {255, 255, 255, 255};
    avGame.pos = {20, 450};
    avGame.text = "Available games";

    graphLib->createWindow("Arcade", 800, 800);
    while (graphLib) {
        graphLib->clearWindow();
        graphLib->displayText(avLib);
        graphLib->displayText(avGame);
        core->handleEvent();
        graphLib->displayWindow();
    }
    graphLib->destroyWindow();
}