/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ActionsMenu
*/

#include "Menu.hpp"

void Menu::applyChanges(Core& core)
{
    core.loadSpecificGraph("./lib/" + libTextMenu_[incrLib_].text + ".so");
    core.loadSpecificGame("./lib/" + gameTextMenu_[incrGame_].text + ".so");
    core.setCoreState(GState::PLAY);
}
void Menu::chooseGame()
{
    isGameSelected_ = true;
    guiTextMenu_[3].m_color = { 255, 255, 255, 0 };
    guiTextMenu_[4].m_color = { 0, 255, 0, 255 };
}

void Menu::chooseLib()
{
    isGameSelected_ = false;
    guiTextMenu_[3].m_color = { 0, 255, 0, 255 };
    guiTextMenu_[4].m_color = { 255, 255, 255, 0 };
}

void Menu::moveUp(Core& core)
{
    if (isGameSelected_ == false) {
        if (guiTextMenu_[3].pos.y - 50 < 240) {
            guiTextMenu_[3].pos.y = 240 + 50 * (static_cast<int>(libTextMenu_.size() - 1));
        } else {
            guiTextMenu_[3].pos.y -= 50;
        }
        if (incrLib_ <= 0)
            incrLib_ = static_cast<int>(libTextMenu_.size()) - 1;
        else
            incrLib_--;
        core.setCurrentGraph("./lib/" + libTextMenu_[incrLib_].text + ".so");
        for (size_t i = 0; i < libTextMenu_.size(); i++)
            libTextMenu_[i].m_color = { 255, 255, 255, 255 };
        libTextMenu_[incrLib_].m_color = { 0, 255, 0, 255 };
    } else {
        if (guiTextMenu_[4].pos.y - 50 < 240) {
            guiTextMenu_[4].pos.y = 240 + 50 * (static_cast<int>(gameTextMenu_.size() - 1));
        } else
            guiTextMenu_[4].pos.y -= 50;
        if (incrGame_ <= 0)
            incrGame_ = static_cast<int>(gameTextMenu_.size()) - 1;
        else
            incrGame_--;
        core.setCurrentGame("./lib/" + gameTextMenu_[incrGame_].text + ".so");
        for (size_t i = 0; i < gameTextMenu_.size(); i++)
            gameTextMenu_[i].m_color = { 255, 255, 255, 255 };
        gameTextMenu_[incrGame_].m_color = { 0, 255, 0, 255 };
    }
}

void Menu::moveDown(Core& core)
{
    if (isGameSelected_ == false) {
        if (guiTextMenu_[3].pos.y + 50 >= (240 + static_cast<int>(libTextMenu_.size()) * 50)) {
            guiTextMenu_[3].pos.y = 240;
        } else
            guiTextMenu_[3].pos.y += 50;
        if (incrLib_ >= static_cast<int>(libTextMenu_.size()) - 1)
            incrLib_ = 0;
        else
            incrLib_++;
        core.setCurrentGraph("./lib/" + libTextMenu_[incrLib_].text + ".so");
        for (size_t i = 0; i < libTextMenu_.size(); i++)
            libTextMenu_[i].m_color = { 255, 255, 255, 255 };
        libTextMenu_[incrLib_].m_color = { 0, 255, 0, 255 };
    } else {
        if (guiTextMenu_[4].pos.y + 50 >= (240 + static_cast<int>(gameTextMenu_.size()) * 50)) {
            guiTextMenu_[4].pos.y = 240;
        } else
            guiTextMenu_[4].pos.y += 50;
        if (incrGame_ >= static_cast<int>(gameTextMenu_.size()) - 1)
            incrGame_ = 0;
        else
            incrGame_++;
        core.setCurrentGame("./lib/" + gameTextMenu_[incrGame_].text + ".so");
        for (size_t i = 0; i < gameTextMenu_.size(); i++)
            gameTextMenu_[i].m_color = { 255, 255, 255, 255 };
        gameTextMenu_[incrGame_].m_color = { 0, 255, 0, 255 };
    }
}
