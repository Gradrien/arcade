/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include <iostream>
#include <sstream>
#include<string>
#include "Menu.hpp"

Menu::Menu()
{
    this->setLibNameMenu();
    this->setGraphLibText();
    this->setGameLibText();
    this->createGuiTextMenu();
    this->createTitleMenu();
    lastUpdateTime_ = std::chrono::steady_clock::now();
}

std::vector<std::string> Menu::getTop3Scores()
{
    std::ifstream infile("score.txt");
    std::string line;
    std::vector<std::pair<unsigned long long, std::string>> scores;
    std::vector<std::string> top3;

    while (std::getline(infile, line)) {
        std::string username;
        unsigned long long score = 0;
        std::stringstream ss(line);
        ss >> username >> score;
        scores.emplace_back(score, username);
    }
    std::sort(scores.rbegin(), scores.rend());
    for (std::size_t i = 0; i < std::min((size_t)3, scores.size()); i++) {
        top3.push_back(scores[i].second + "  " + std::to_string(scores[i].first));
    }
    return top3;
}

void Menu::handleEvent(eventKey evt, Core& core)
{
    if (isUserTyping_ == true)
        return handleUserInput(evt, core);
    switch (evt) {
    case eventKey::A:
        applyChanges(core);
        saveUserName();
        break;
    case eventKey::RARROW:
        chooseGame();
        break;
    case eventKey::LARROW:
        chooseLib();
        break;
    case eventKey::UARROW:
        moveUp(core);
        break;
    case eventKey::BARROW:
        moveDown(core);
        break;
    case eventKey::T:
        isUserTyping_ = true;
        break;
    case eventKey::ENTER:
        isUserTyping_ = false;
        break;
    default:
        break;
    }
}

void Menu::highlightTitle(const int count)
{
    for (size_t i = 0; i < titleMenu_.size(); ++i) {
        if (static_cast<int>(i) == count) {
            titleMenu_[i].m_color = { 0, 255, 0, 255 };
            titleMenu_[i + 2].m_color = { 0, 255, 0, 255 };
        } else {
            titleMenu_[i].m_color = { 255, 255, 255, 255 };
        }
    }
}

void Menu::highlightSelected(Core& core)
{
    for (std::size_t i = 0; i < this->libTextMenu_.size(); i++) {
        libTextMenu_[i].m_color = { 255, 255, 255, 255 };
        if (core.getCurrentGraph() == "./lib/" + libTextMenu_[i].text + ".so"
            || core.getCurrentGraph() == "lib/" + libTextMenu_[i].text + ".so") {
            libTextMenu_[i].m_color = { 0, 255, 0, 255 };
            incrLib_ = static_cast<int>(i);
            guiTextMenu_[3].pos.y = 240 + 50 * static_cast<int>(i);
        }
    }
    for (std::size_t i = 0; i < this->gameTextMenu_.size(); i++) {
        gameTextMenu_[i].m_color = { 255, 255, 255, 255 };
        if (core.getCurrentGame() == "./lib/" + gameTextMenu_[i].text + ".so")
            gameTextMenu_[i].m_color = { 0, 255, 0, 255 };
        if (core.getCurrentGame() == "")
            gameTextMenu_[0].m_color = { 0, 255, 0, 255 };
    }
}

void Menu::loopTitle()
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdateTime_).count();

    if (elapsed >= 200) {
        counter_++;
        if (counter_ > 5)
            counter_ = 0;
        lastUpdateTime_ = now;
    }
    switch (counter_) {
    case 0:
        highlightTitle(0);
        break;
    case 1:
        highlightTitle(1);
        break;
    case 2:
        highlightTitle(2);
        break;
    case 3:
        highlightTitle(3);
        break;
    case 4:
        highlightTitle(4);
        break;
    case 5:
        highlightTitle(5);
        break;
    }
}

void Menu::menuLoopHandler(IGraphic& graphLib, Core& core)
{
    if (!graphLib.isOpenWindow())
        graphLib.createWindow("Arcade", 800, 800);
    graphLib.clearWindow();
    highlightSelected(core);
    loopTitle();
    if (isUserTyping_ == false) {
        for (auto& i : this->scoreText_)
            graphLib.displayText(i);
        for (auto& i : this->libTextMenu_)
            graphLib.displayText(i);
        for (auto& i : this->gameTextMenu_)
            graphLib.displayText(i);
        for (std::size_t i = 0; i < this->guiTextMenu_.size(); i++)
            if (i != 2)
                graphLib.displayText(guiTextMenu_[i]);
        for (auto& i : this->titleMenu_)
            graphLib.displayText(i);
    } else {
        graphLib.displayText(guiTextMenu_[2]);
        graphLib.displayText(userName_);
    }
    graphLib.displayWindow();
    core.handleEvent();
}
