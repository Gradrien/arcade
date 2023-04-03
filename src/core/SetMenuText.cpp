/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SetMenuText
*/

#include "Menu.hpp"

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

void Menu::setUserNameText()
{
    userName_.fontSize = 30;
    userName_.fontPath = "assets/fonts/arial.ttf";
    userName_.m_color = { 255, 255, 255, 255 };
    userName_.pos = { 300, 300 };
    userName_.text = "";
    userName_.size = { static_cast<int>(userName_.fontSize * 1.33 * 0.46 * userName_.text.length() - 80), static_cast<int>(userName_.fontSize * 1.33) };
}

void Menu::setAvailableLibText()
{
    text avLib;
    text avGame;

    avLib.fontSize = 30;
    avLib.fontPath = "assets/fonts/arial.ttf";
    avLib.m_color = { 255, 255, 255, 255 };
    avLib.pos = { 100, 170 };
    avLib.text = "Available libraires";
    avLib.size = { static_cast<int>(avLib.fontSize * 1.33 * 0.46 * avLib.text.length() - 80), static_cast<int>(avLib.fontSize * 1.33) };
    avGame.fontSize = 30;
    avGame.fontPath = "assets/fonts/arial.ttf";
    avGame.m_color = { 255, 255, 255, 255 };
    avGame.pos = { 460, 170 };
    avGame.text = "Available games";
    avGame.size = { static_cast<int>(avGame.fontSize * 1.33 * 0.46 * avGame.text.length() - 80), static_cast<int>(avGame.fontSize * 1.33) };
    guiTextMenu_.push_back(avLib);
    guiTextMenu_.push_back(avGame);
}

void Menu::setCursorsMenu()
{
    text selectLibCurs;
    text selectGameCurs;

    selectLibCurs.fontSize = 25;
    selectLibCurs.fontPath = "assets/fonts/arial.ttf";
    selectLibCurs.m_color = { 0, 255, 0, 255 };
    selectLibCurs.pos = { 100, 240 };
    selectLibCurs.text = ">";
    selectLibCurs.size = { 20, 40 };
    selectGameCurs.fontSize = 25;
    selectGameCurs.fontPath = "assets/fonts/arial.ttf";
    selectGameCurs.m_color = { 255, 255, 255, 0 };
    selectGameCurs.pos = { 470, 240 };
    selectGameCurs.text = ">";
    selectGameCurs.size = { 20, 40 };
    guiTextMenu_.push_back(selectLibCurs);
    guiTextMenu_.push_back(selectGameCurs);
}

void Menu::setScoreboardTitle()
{
    text highScoreTit;
    highScoreTit.fontSize = 30;
    highScoreTit.fontPath = "assets/fonts/arial.ttf";
    highScoreTit.m_color = { 255, 255, 255, 255 };
    highScoreTit.pos = { 300, 520 };
    highScoreTit.text = "Scoreboard";
    highScoreTit.size = { static_cast<int>(highScoreTit.fontSize * 1.33 * 0.46 * highScoreTit.text.length()), static_cast<int>(highScoreTit.fontSize * 1.33) };
    this->scoreText_.push_back(highScoreTit);
}

void Menu::setHighScoreText()
{
    int pos_y = 600;
    std::fstream scorefile;
    std::vector<std::string> top3 = getTop3Scores();

    setScoreboardTitle();
    scorefile.open("./score.txt", std::ios::in);
    if (scorefile.is_open()) {
        for (std::size_t i = 0; i < top3.size(); i++) {
            text highScore;
            highScore.fontSize = 25;
            highScore.fontPath = "assets/fonts/arial.ttf";
            highScore.m_color = { 255, 255, 255, 255 };
            highScore.pos = { 300, pos_y };
            highScore.text = std::to_string(i + 1) + ". " + top3[i];
            highScore.size = { static_cast<int>(highScore.fontSize * 1.33 * 0.46 * highScore.text.length()), static_cast<int>(highScore.fontSize * 1.33) };
            this->scoreText_.push_back(highScore);
            pos_y += 50;
        }
        scorefile.close();
    }
}

void Menu::setGameLibText()
{
    int pos_y = 240;

    for (size_t i = 0; i < gamePaths_.size(); i++) {
        text game;
        game.fontSize = 20;
        game.fontPath = "assets/fonts/arial.ttf";
        game.m_color = { 255, 255, 255, 255 };
        game.pos = { 500, pos_y };
        game.text = gamePaths_[i];
        game.text.erase((game.text.length() - 3), 3);
        game.size = { static_cast<int>(game.fontSize * 1.33 * 0.46 * game.text.length()), static_cast<int>(game.fontSize * 1.33) };
        this->gameTextMenu_.push_back(game);
        pos_y += 50;
    }
}

void Menu::setGraphLibText()
{
    int pos_y = 240;

    for (size_t i = 0; i < graphPaths_.size(); i++) {
        text lib;
        lib.fontSize = 20;
        lib.fontPath = "assets/fonts/arial.ttf";
        lib.m_color = { 255, 255, 255, 255 };
        lib.pos = { 140, pos_y };
        lib.text = graphPaths_[i];
        lib.text.erase((lib.text.length() - 3), 3);
        lib.size = { static_cast<int>(lib.fontSize * 1.33 * 0.46 * lib.text.length()), static_cast<int>(lib.fontSize * 1.33) };
        this->libTextMenu_.push_back(lib);
        pos_y += 50;
    }
}

void Menu::setLibNameMenu()
{
    const std::filesystem::path libPath { "./lib/" };

    for (auto const& dir_entry : std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        if (validLibs.find(dir_entry.path().filename()) == validLibs.end())
            continue;
        if (validLibs.at(dir_entry.path().filename()) == libType::GRAPHICAL)
            graphPaths_.push_back(dir_entry.path().filename().c_str());
        else if (validLibs.at(dir_entry.path().filename()) == libType::GAME)
            gamePaths_.push_back(dir_entry.path().filename().c_str());
    }
}

void Menu::createGuiTextMenu()
{
    text userEntry;
    text welcomeMessage;

    setUserNameText();
    setAvailableLibText();
    userEntry.fontSize = 40;
    userEntry.fontPath = "assets/fonts/arial.ttf";
    userEntry.m_color = { 255, 255, 255, 255 };
    userEntry.pos = { 220, 200 };
    userEntry.text = "Please type your name";
    userEntry.size = { static_cast<int>(userEntry.fontSize * 1.33 * 0.46 * userEntry.text.length() - 60), static_cast<int>(userEntry.fontSize * 1.33) };
    guiTextMenu_.push_back(userEntry);
    setCursorsMenu();
    welcomeMessage.fontSize = 40;
    welcomeMessage.fontPath = "assets/fonts/arial.ttf";
    welcomeMessage.m_color = { 255, 255, 255, 255 };
    welcomeMessage.pos = { 100, 400 };
    welcomeMessage.text = "Welcome to the Arcade ";
    welcomeMessage.size = { static_cast<int>(welcomeMessage.fontSize * 1.33 * 0.46 * welcomeMessage.text.length() - 60), static_cast<int>(welcomeMessage.fontSize * 1.33) };
    guiTextMenu_.push_back(welcomeMessage);
    setHighScoreText();
}
