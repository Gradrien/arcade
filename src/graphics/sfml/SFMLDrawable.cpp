/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLDrawable
*/

#include "SFMLDrawable.hpp"

void SFMLDrawable::displayText(const text& text) const
{
    (void)text;
    return;
}

void SFMLDrawable::displayShape(const shape& shape) const
{
    (void)shape;
    return;
}

void SFMLDrawable::displaySprite(const sprite& sprite) const
{
    (void)sprite;
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
