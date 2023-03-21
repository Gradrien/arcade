/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Core &core)
{
    this->setGraphLibText(core.getGraphPaths());
    this->setGameLibText(core.getGamePaths());
    this->createGuiTextMenu();
}

void Menu::setGameLibText(std::vector<std::string> gamePaths_)
{
    std::vector<std::string> gamePaths = gamePaths_;

    int pos_y = 200;
    for (size_t i = 0; i < gamePaths.size(); i++) {
        text game;
        game.fontSize = 20;
        game.fontPath = "assets/fonts/arial.ttf";
        game.m_color = { 255, 255, 255, 255 };
        game.pos = { 380, pos_y };
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
        lib.fontSize = 20;
        lib.fontPath = "assets/fonts/arial.ttf";
        lib.m_color = { 255, 255, 255, 255 };
        lib.pos = { 60, pos_y };
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
    text selectLibCurs;
    text selectGameCurs;

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
    selectLibCurs.fontSize = 25;
    selectLibCurs.fontPath = "assets/fonts/arial.ttf";
    selectLibCurs.m_color = { 0, 255, 0, 255 };
    selectLibCurs.pos = { 20, 200 };
    selectLibCurs.text = ">";
    selectGameCurs.fontSize = 25;
    selectGameCurs.fontPath = "assets/fonts/arial.ttf";
    selectGameCurs.m_color = { 255, 255, 255, 255 };
    selectGameCurs.pos = { 350, 200 };
    selectGameCurs.text = ">";
    guiTextMenu_.push_back(avLib);
    guiTextMenu_.push_back(avGame);
    guiTextMenu_.push_back(userEntry);
    guiTextMenu_.push_back(selectLibCurs);
    guiTextMenu_.push_back(selectGameCurs);
}

void Menu::handleEvent(eventKey evt, Core& core)
{
    switch (evt)
    {
    case eventKey::A:
        core.loadSpecificGraph(libTextMenu_[incrLib_].text);
        core.setCoreState(GState::PLAY);
        break;
    case eventKey::RARROW:
        isGameSelected_ = true;
        guiTextMenu_[3].m_color = { 255, 255, 255, 255 };
        guiTextMenu_[4].m_color = { 0, 255, 0, 255 };
        break;
    case eventKey::LARROW:
        isGameSelected_ = false;
        guiTextMenu_[3].m_color = { 0, 255, 0, 255 };
        guiTextMenu_[4].m_color = { 255, 255, 255, 255 };
        break;
    case eventKey::BARROW:
        if (isGameSelected_ == false) {
            if (guiTextMenu_[3].pos.y + 50 >= (200 + static_cast<int>(libTextMenu_.size()) * 50)) {
                guiTextMenu_[3].pos.y = 200;
            } else
                guiTextMenu_[3].pos.y += 50;
            if (incrLib_ >= static_cast<int>(libTextMenu_.size()) - 1)
                incrLib_ = 0;
            else
                incrLib_++;
        } else {
            if (guiTextMenu_[4].pos.y + 50 >= (200 + static_cast<int>(gameTextMenu_.size()) * 50)) {
                guiTextMenu_[4].pos.y = 200;
            } else
                guiTextMenu_[4].pos.y += 50;
            core.loadNextGame();
        }
        break;
    case eventKey::UARROW:
         if (isGameSelected_ == false) {
            if (guiTextMenu_[3].pos.y - 50 < 200) {
                guiTextMenu_[3].pos.y = 200 + 50 * (static_cast<int>(libTextMenu_.size() - 1));
            } else {
                guiTextMenu_[3].pos.y -= 50;
            }
            if (incrLib_ <= 0)
                incrLib_ = static_cast<int>(libTextMenu_.size()) - 1;
            else
                incrLib_--;
         } else {
            if (guiTextMenu_[4].pos.y - 50 < 200) {
                guiTextMenu_[4].pos.y = 200 + 50 * (static_cast<int>(gameTextMenu_.size() - 1));
            } else
                guiTextMenu_[4].pos.y -= 50;
            core.loadNextGame();
         }
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
