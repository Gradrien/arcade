/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"

void SFMLWindow::createWindow(std::string title, int width, int height)
{
    this->window.create(sf::VideoMode(width, height), title);
    return;
}

void SFMLWindow::displayWindow()
{
    this->window.display();
    return;
}

void SFMLWindow::clearWindow()
{
    return;
}

void SFMLWindow::destroyWindow()
{
    return;
}

bool SFMLWindow::isOpenWindow()
{
    return this->window.isOpen();
}
