/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

std::vector<text> Menu::setGameLibText(std::vector<std::string> gamePaths_)
{
    std::vector<text> gameTextMenu2;
    std::vector<std::string> gamePaths = gamePaths_;

    int pos_y = 200;
    for (size_t i = 0; i < gamePaths.size(); i++) {
        text game;
        game.fontSize = 30;
        game.fontPath = "assets/fonts/arial.ttf";
        game.m_color = { 255, 255, 255, 255 };
        game.pos = { 360, pos_y };
        game.text = gamePaths[i];
        gameTextMenu2.push_back(game);
        pos_y += 50;
    }
    return gameTextMenu2;
}

std::vector<text> Menu::setGraphLibText(std::vector<std::string> graphPaths_)
{
    std::vector<text> libTextMenu2;
    std::vector<std::string> graphPaths = graphPaths_;

    int pos_y = 200;
    for (size_t i = 0; i < graphPaths.size(); i++) {
        text lib;
        lib.fontSize = 30;
        lib.fontPath = "assets/fonts/arial.ttf";
        lib.m_color = { 255, 255, 255, 255 };
        lib.pos = { 40, pos_y };
        lib.text = graphPaths[i];
        libTextMenu2.push_back(lib);
        pos_y += 50;
    }
    return libTextMenu2;
}

std::vector<text> Menu::guiTextMenu()
{
    std::vector<text> gameTextMenu;
    text avLib;
    text avGame;
    text userEntry;

    avLib.fontSize = 30;
    avLib.fontPath = "assets/fonts/arial.ttf";
    avLib.m_color = { 255, 255, 255, 255 };
    avLib.pos = { 20, 130 };
    avLib.text = "Available libraires";
    avGame.fontSize = 30;
    avGame.fontPath = "assets/fonts/arial.ttf";
    avGame.m_color = { 255, 255, 255, 255 };
    avGame.pos = { 340, 130 };
    avGame.text = "Available games";
    userEntry.fontSize = 30;
    userEntry.fontPath = "assets/fonts/arial.ttf";
    userEntry.m_color = { 255, 255, 255, 255 };
    userEntry.pos = { 20, 600 };
    userEntry.text = "Enter your name :";
    gameTextMenu.push_back(avLib);
    gameTextMenu.push_back(avGame);
    gameTextMenu.push_back(userEntry);
    return gameTextMenu;
}

void Menu::menuLoopHandler(std::unique_ptr<IGraphic>& graphLib, Core& core)
{
    std::vector<text> libTextMenu = this->setGraphLibText(core.getGraphPaths());
    std::vector<text> gameTextMenu = this->setGameLibText(core.getGamePaths());
    std::vector<text> guiTextMenu = this->guiTextMenu();
    if (!graphLib->isOpenWindow())
        graphLib->createWindow("Arcade", 800, 800);
    while (graphLib->isOpenWindow() && (core.getCoreState() == GState::MENU)) {
        graphLib->clearWindow();
        for (auto& i : libTextMenu)
            graphLib->displayText(i);
        for (auto& i : gameTextMenu)
            graphLib->displayText(i);
        for (auto& i : guiTextMenu)
            graphLib->displayText(i);
        graphLib->displayWindow();
        core.handleEvent();
    }
    core.coreStateHandler();
}
