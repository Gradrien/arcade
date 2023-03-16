/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#include "SFMLGraphic.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

void SFMLGraphic::createWindow(std::string title, int width, int height)
{
    this->window_.create(sf::VideoMode(width, height), title);
    return;
}

void SFMLGraphic::displayWindow()
{
    this->window_.display();
    return;
}

void SFMLGraphic::clearWindow()
{
    return;
}

void SFMLGraphic::destroyWindow()
{
    this->window_.close();
}

bool SFMLGraphic::isOpenWindow()
{
    return this->window_.isOpen();
}

void SFMLGraphic::displayText(const text& text)
{
    (void)text;
    return;
}

void SFMLGraphic::drawRectangle(const shape& shape)
{
    sf::Color color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a);
    sf::RectangleShape rect(sf::Vector2f(shape.size.width, shape.size.height));
    rect.setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
    rect.setPosition(sf::Vector2f(shape.pos.x, shape.pos.y));
    window_.draw(rect);
}

void SFMLGraphic::displayShape(const shape& shape)
{
    switch (shape.type)
    {
    case shapeType::RECTANGLE :
        this->drawRectangle(shape);
        break;
    default:
        break;
    }
    return;
}

void SFMLGraphic::displaySprite(const sprite& sprite)
{
    (void)sprite;
    return;
}
eventKey SFMLGraphic::getEvent() const
{
    return eventKey::LARROW;
}
