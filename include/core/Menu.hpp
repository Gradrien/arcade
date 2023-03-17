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
    Menu() = default;
    ~Menu() = default;
    void menuLoopHandler(std::unique_ptr<IGraphic> &graphLib, Core &core);
    void handleEvent();
    void display();
    std::vector<text> setGraphLibText(std::vector<std::string> graphPaths_);
    std::vector<text> setGameLibText(std::vector<std::string> gamePaths_);
    std::vector<text> guiTextMenu();

    private:
    int selectedGame;
    int selectedGraph;
};

#endif /* !MENU_HPP_ */
