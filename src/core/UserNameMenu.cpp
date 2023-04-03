/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** UserNameMenu
*/

#include "Menu.hpp"

int random(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);

    return dist(gen);
}

bool Menu::isUserTyping() const
{
    return isUserTyping_;
}

void Menu::createNewUser()
{
    if (userName_.text.size() == 0)
        userName_.text = "Player" + std::to_string(random(100, 999));
    isUserTyping_ = false;
    guiTextMenu_[5].text = "Welcome to the Arcade ";
    guiTextMenu_[5].text.append(userName_.text);
}

void Menu::deleteChar()
{
    if (userName_.text.size() > 0)
        userName_.text.pop_back();
}

void Menu::handleUserInput(eventKey evt, Core &core)
{
    userName_.size = { static_cast<int>(userName_.fontSize * 1.33 * 0.46 * userName_.text.length()), static_cast<int>(userName_.fontSize * 1.33) };
    if (isUserTyping_ == true) {
        if (evt == eventKey::DELETE)
            deleteChar();
        else if (evt == eventKey::ENTER)
            createNewUser();
        else if (evt == eventKey::QUIT)
            core.setCoreState(GState::QUIT);
        else if (this->keyMap_.find(evt) != this->keyMap_.end()
            && userName_.text.size() < 10)
            userName_.text += keyMap_[evt];
    }
}

std::string Menu::getUserName() const { return this->userName_.text; }

void Menu::saveUserName()
{
    std::ofstream file("./score.txt", std::ios::app);

    if (file.is_open()) {
        file << userName_.text;
        file.close();
    }
}
