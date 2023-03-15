/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLDrawable
*/

#include "SFMLDrawable.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

void SFMLDrawable::displayText(const std::unique_ptr<IWindow>& window, const text& text) const
{
    (void)text;
    (void)window;
    return;
}

void SFMLDrawable::drawRectangle(const std::unique_ptr<IWindow>& window, const shape& shape) const
{
    (void)window;
    sf::Color color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a);
    sf::RectangleShape rect(sf::Vector2f(shape.size.width, shape.size.height));
    rect.setFillColor(sf::Color(shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a));
    rect.setPosition(sf::Vector2f(shape.pos.x, shape.pos.y));
}

void SFMLDrawable::displayShape(const std::unique_ptr<IWindow>& window, const shape& shape) const
{
    (void)shape;
    switch (shape.type)
    {
    case shapeType::RECTANGLE :
        this->drawRectangle(window, shape);
        break;
    default:
        break;
    }
    return;
}

void SFMLDrawable::displaySprite(const std::unique_ptr<IWindow>& window, const sprite& sprite) const
{
    (void)sprite;
    (void)window;
    return;
}

// text& SFMLDrawable::createText()
// {
//     text newText { .pos = { 0, 0 }, .fontSize = 10, .fontPath = "", .m_color = { 0, 0, 0, 0 }, .text = "Hello" };
//     return newText;
// }

// shape& SFMLDrawable::createShape()
// {
//     shape newShape { .pos = { 0, 0 }, .size = { 0, 0 }, .m_color = { 0, 0, 0, 0 }, .replacementChar = '#', .text = "Hello", .type = shapeType::RECTANGLE };
//     return newShape;
// }

// sprite& SFMLDrawable::createSprite()
// {
//     sprite newSprite { .pos = { 0, 0 }, .size = { 0, 0 }, .m_texture = { { 0, 0 }, { 0, 0 }, "" }, .replacementChar = '#', .m_color = { 0, 0, 0, 0 } };
//     return newSprite;
// }
