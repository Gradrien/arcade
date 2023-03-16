/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** TestGame
*/

#include "TestGame.hpp"

std::string TestGame::getSpritePath()
{
    return "";
}

void TestGame::display(std::unique_ptr<IGraphic>& graphLib)
{
    graphLib->displayShape(this->rect);
}

int TestGame::init()
{
    this->rect = { .pos { 400, 400 }, .size { 200, 200 }, .m_color { .r = 0, .g = 151, .b = 255, .a = 255 }, .replacementChar = '#', .text { "Allo" }, .type = shapeType::RECTANGLE };
    return 0;
}

void TestGame::reset()
{
}

int TestGame::updateGame(eventKey evtKey)
{
    switch (evtKey) {
    case eventKey::BARROW:
        this->rect.pos.y += 10;
        break;
    case eventKey::UARROW:
        this->rect.pos.y -= 10;
        break;
    case eventKey::LARROW:
        this->rect.pos.x -= 10;
        break;
    case eventKey::RARROW:
        this->rect.pos.x += 10;
        break;
    default:
        break;
    }
    return 0;
}
