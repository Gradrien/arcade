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
    void menuLoopHandler(std::unique_ptr<IGraphic> &graphLib, Core *core);
    void handleEvent();
    void display();
    void setGraphLib(std::unique_ptr<IGraphic> &graphLib);
    void setGameLib(std::unique_ptr<IGame> &gameLib);

    private:
    std::unique_ptr<IGraphic> &graphLib_;
    std::vector<text> textMenu;
    int selectedGame;
    int selectedGraph;
};

#endif /* !MENU_HPP_ */
