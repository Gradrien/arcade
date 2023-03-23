/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Core& core)
{
    this->setGraphLibText(core.getGraphPaths());
    this->setGameLibText(core.getGamePaths());
    this->createGuiTextMenu();
    this->createTitleMenu();
    lastUpdateTime_ = std::chrono::steady_clock::now();
}

void Menu::setGameLibText(std::vector<std::string> gamePaths_)
{
    std::vector<std::string> gamePaths = gamePaths_;

    int pos_y = 240;
    for (size_t i = 0; i < gamePaths.size(); i++) {
        text game;
        game.fontSize = 20;
        game.fontPath = "assets/fonts/arial.ttf";
        game.m_color = { 255, 255, 255, 255 };
        game.pos = { 460, pos_y };
        game.text = gamePaths[i];
        game.text.erase(0, 6);
        game.text.erase((game.text.length() - 3), 3);
        game.size = { static_cast<int>(game.fontSize * 1.33 * 0.46 * game.text.length()), static_cast<int>(game.fontSize * 1.33) };
        this->gameTextMenu_.push_back(game);
        pos_y += 50;
    }
}

void Menu::setGraphLibText(std::vector<std::string> graphPaths_)
{
    std::vector<std::string> graphPaths = graphPaths_;

    int pos_y = 240;
    for (size_t i = 0; i < graphPaths.size(); i++) {
        text lib;
        lib.fontSize = 20;
        lib.fontPath = "assets/fonts/arial.ttf";
        lib.m_color = { 255, 255, 255, 255 };
        lib.pos = { 140, pos_y };
        lib.text = graphPaths[i];
        lib.text.erase(0, 6);
        lib.text.erase((lib.text.length() - 3), 3);
        lib.size = { static_cast<int>(lib.fontSize * 1.33 * 0.46 * lib.text.length()), static_cast<int>(lib.fontSize * 1.33) };
        this->libTextMenu_.push_back(lib);
        pos_y += 50;
    }
}

void Menu::createTitleMenu()
{
    text titleA;
    text titleR;
    text titleC;
    text titleA2;
    text titleD;
    text titleE;

    titleA.fontSize = 50;
    titleA.fontPath = "assets/fonts/arial.ttf";
    titleA.m_color = { 255, 255, 255, 255 };
    titleA.pos = { 280, 60 };
    titleA.text = "A";
    titleA.size = { 25, 40 };
    titleR.fontSize = 50;
    titleR.fontPath = "assets/fonts/arial.ttf";
    titleR.m_color = { 255, 255, 255, 255 };
    titleR.pos = { 320, 60 };
    titleR.text = "R";
    titleR.size = { 25, 40 };
    titleC.fontSize = 50;
    titleC.fontPath = "assets/fonts/arial.ttf";
    titleC.m_color = { 255, 255, 255, 255 };
    titleC.pos = { 360, 60 };
    titleC.text = "C";
    titleC.size = { 25, 40 };
    titleA2.fontSize = 50;
    titleA2.fontPath = "assets/fonts/arial.ttf";
    titleA2.m_color = { 255, 255, 255, 255 };
    titleA2.pos = { 400, 60 };
    titleA2.text = "A";
    titleA2.size = { 25, 40 };
    titleD.fontSize = 50;
    titleD.fontPath = "assets/fonts/arial.ttf";
    titleD.m_color = { 255, 255, 255, 255 };
    titleD.pos = { 440, 60 };
    titleD.text = "D";
    titleD.size = { 25, 40 };
    titleE.fontSize = 50;
    titleE.fontPath = "assets/fonts/arial.ttf";
    titleE.m_color = { 255, 255, 255, 255 };
    titleE.pos = { 480, 60 };
    titleE.text = "E";
    titleE.size = { 25, 40 };
    titleMenu_.push_back(titleA);
    titleMenu_.push_back(titleR);
    titleMenu_.push_back(titleC);
    titleMenu_.push_back(titleA2);
    titleMenu_.push_back(titleD);
    titleMenu_.push_back(titleE);
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
    avLib.pos = { 100, 170 };
    avLib.text = "Available libraires";
    avLib.size = { static_cast<int>(avLib.fontSize * 1.33 * 0.46 * avLib.text.length() - 80), static_cast<int>(avLib.fontSize * 1.33) };
    avGame.fontSize = 30;
    avGame.fontPath = "assets/fonts/arial.ttf";
    avGame.m_color = { 255, 255, 255, 255 };
    avGame.pos = { 420, 170 };
    avGame.text = "Available games";
    avGame.size = { static_cast<int>(avGame.fontSize * 1.33 * 0.46 * avGame.text.length() - 80), static_cast<int>(avGame.fontSize * 1.33) };
    userEntry.fontSize = 30;
    userEntry.fontPath = "assets/fonts/arial.ttf";
    userEntry.m_color = { 255, 255, 255, 255 };
    userEntry.pos = { 100, 600 };
    userEntry.text = "Enter your name :";
    userEntry.size = { static_cast<int>(userEntry.fontSize * 1.33 * 0.46 * userEntry.text.length() - 60), static_cast<int>(userEntry.fontSize * 1.33) };
    selectLibCurs.fontSize = 25;
    selectLibCurs.fontPath = "assets/fonts/arial.ttf";
    selectLibCurs.m_color = { 0, 255, 0, 255 };
    selectLibCurs.pos = { 100, 240 };
    selectLibCurs.text = ">";
    selectLibCurs.size = { 20, 40 };
    selectGameCurs.fontSize = 25;
    selectGameCurs.fontPath = "assets/fonts/arial.ttf";
    selectGameCurs.m_color = { 255, 255, 255, 0 };
    selectGameCurs.pos = { 430, 240 };
    selectGameCurs.text = ">";
    selectGameCurs.size = { 20, 40 };
    guiTextMenu_.push_back(avLib);
    guiTextMenu_.push_back(avGame);
    guiTextMenu_.push_back(userEntry);
    guiTextMenu_.push_back(selectLibCurs);
    guiTextMenu_.push_back(selectGameCurs);
}

void Menu::applyChanges(Core &core)
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

void Menu::moveUp(Core &core)
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

void Menu::moveDown(Core &core)
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

void Menu::handleEvent(eventKey evt, Core& core)
{
    switch (evt) {
    case eventKey::A:
        applyChanges(core);
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

void Menu::highlightSelected(Core &core)
{
    for (std::size_t i = 0; i < this->libTextMenu_.size(); i++) {
        libTextMenu_[i].m_color = { 255, 255, 255, 255 };
        if (core.getCurrentGraph() == "./lib/" + libTextMenu_[i].text + ".so")
            libTextMenu_[i].m_color = { 0, 255, 0, 255 };
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
    switch(counter_) {
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
    for (auto& i : this->libTextMenu_)
        graphLib.displayText(i);
    for (auto& i : this->gameTextMenu_)
        graphLib.displayText(i);
    for (auto& i : this->guiTextMenu_)
        graphLib.displayText(i);
    for (auto& i : this->titleMenu_)
        graphLib.displayText(i);
    graphLib.displayWindow();
    core.handleEvent();
}
