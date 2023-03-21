/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Core &core)
{
    this->createGuiTextMenu();
    this->setGraphLibText(core.getGraphPaths());
    this->setGameLibText(core.getGamePaths());
}

void Menu::setGameLibText(std::vector<std::string> gamePaths_)
{
    std::vector<std::string> gamePaths = gamePaths_;

    int pos_y = 200;
    for (size_t i = 0; i < gamePaths.size(); i++) {
        text game;
        game.fontSize = 30;
        game.fontPath = "assets/fonts/arial.ttf";
        game.m_color = { 255, 255, 255, 255 };
        game.pos = { 360, pos_y };
        game.text = gamePaths[i];
        this->gameTextMenu_.push_back(game);
        pos_y += 50;
    }
}

void Menu::setGraphLibText(std::vector<std::string> graphPaths_)
{
    std::vector<std::string> graphPaths = graphPaths_;

    int pos_y = 200;
    for (size_t i = 0; i < graphPaths.size(); i++) {
        text lib;
        lib.fontSize = 30;
        lib.fontPath = "assets/fonts/arial.ttf";
        lib.m_color = { 255, 255, 255, 255 };
        lib.pos = { 40, pos_y };
        lib.text = graphPaths[i];
        this->libTextMenu_.push_back(lib);
        pos_y += 50;
    }
}

void Menu::createGuiTextMenu()
{
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
    guiTextMenu_.push_back(avLib);
    guiTextMenu_.push_back(avGame);
    guiTextMenu_.push_back(userEntry);
}

void Menu::handleEvent(eventKey evt, Core& core) {
    switch (evt)
    {
    case eventKey::BARROW:
        core.loadSpecificGraph(core.getGraphPaths()[1]);
        break;
    case eventKey::UARROW:
        core.loadSpecificGraph(core.getGraphPaths()[0]);
        break;
    default:
        break;
    }
}

void Menu::menuLoopHandler(IGraphic &graphLib, Core& core)
{
    if (!graphLib.isOpenWindow())
        graphLib.createWindow("Arcade", 800, 800);
    graphLib.clearWindow();
    for (auto& i : this->libTextMenu_)
        graphLib.displayText(i);
    for (auto& i : this->gameTextMenu_)
        graphLib.displayText(i);
    for (auto& i : this->guiTextMenu_)
        graphLib.displayText(i);
    graphLib.displayWindow();
    core.handleEvent();
}
