/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "IGraphic.hpp"
#include "IGame.hpp"
#include "Core.hpp"
#include <string>
#include <vector>
#include <memory>

class Core;

class Menu {
    public:
    Menu(Core &core);
    ~Menu() = default;
    void menuLoopHandler(IGraphic &graphLib, Core &core);
    void handleEvent(eventKey evt, Core &core);
    void display();
    void setGraphLibText(std::vector<std::string> graphPaths_);
    void setGameLibText(std::vector<std::string> gamePaths_);
    void createGuiTextMenu();

    private:
    std::vector<text> guiTextMenu_;
    std::vector<text> gameTextMenu_;
    std::vector<text> libTextMenu_;
    int incrLib_ {0};
    int incrGame_ {0};
    bool isGameSelected_ {false};
};

#endif /* !MENU_HPP_ */
