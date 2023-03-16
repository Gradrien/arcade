/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#include "SFMLGraphic.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

void SFMLGraphic::createWindow(std::string title, int width, int height)
{
    this->window_.create(sf::VideoMode(width, height), title);
    this->window_.setFramerateLimit(60);
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
    if (this->rectList.find(&shape) != this->rectList.end()) {
        this->rectList[&shape].setSize(sf::Vector2f(shape.size.width, shape.size.height));
        this->rectList[&shape].setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
        this->rectList[&shape].setPosition(sf::Vector2f(shape.pos.x, shape.pos.y));
        window_.draw(this->rectList[&shape]);
        return;
    }
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(shape.size.width, shape.size.height));
    rect.setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
    rect.setPosition(sf::Vector2f(shape.pos.x, shape.pos.y));
    this->rectList[&shape] = rect;
    window_.draw(rect);
}

void SFMLGraphic::drawCircle(const shape& shape)
{
    if (this->circleList.find(&shape) != this->circleList.end()) {
        this->circleList[&shape].setRadius(shape.size.width);
        this->circleList[&shape].setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
        this->circleList[&shape].setPosition(shape.pos.x, shape.pos.y);
        window_.draw(this->circleList[&shape]);
        return;
    }
    sf::CircleShape circle(shape.size.width);
    circle.setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
    circle.setPosition(shape.pos.x, shape.pos.y);
    this->circleList[&shape] = circle;
    window_.draw(circle);
}

void SFMLGraphic::displayShape(const shape& shape)
{
    switch (shape.type) {
    case shapeType::RECTANGLE:
        this->drawRectangle(shape);
        break;
    case shapeType::CIRCLE:
        this->drawCircle(shape);
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
