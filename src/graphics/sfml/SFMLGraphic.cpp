/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#include "SFMLGraphic.hpp"
#include <memory>

const std::unique_ptr<IWindow>& SFMLGraphic::getWindow() const
{
    return this->window;
}

const std::unique_ptr<IDrawable>& SFMLGraphic::getDrawable() const
{
    return this->drawables;
}

eventKey SFMLGraphic::getEvent() const
{
    return eventKey::LARROW;
}
