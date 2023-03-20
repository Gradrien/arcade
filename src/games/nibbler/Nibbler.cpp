/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

void Nibbler::reset()
{
    this->speed_ = 1;
    this->nibblerSize_ = 4;
}

void Nibbler::initNibbler()
{
    color color[] = {
        {.r = 255, .g = 255, .b = 255, .a = 255},
        {.r = 240, .g = 0, .b = 0, .a = 255},
        {.r = 0, .g = 254, .b = 0, .a = 255},
        {.r = 0, .g = 0, .b = 255, .a = 255}
    };

    for (int i = 0; i < this->nibblerSize_; i++) {
        shape obj = { .pos { ((4 * this->cellSize_) - (i * cellSize_)), 60 },
            .size { this->cellSize_, this->cellSize_ },
            .m_color = color[i],
            .replacementChar = 'o',
            .text = "",
            .type = shapeType::RECTANGLE };
        this->nibbler_.push_back(obj);
    }
}

int Nibbler::init()
{
    initNibbler();
    return 0;
}

void Nibbler::display(std::unique_ptr<IGraphic>& graphLib)
{
    for (shape part : this->nibbler_) {
        graphLib->displayShape(part);
    }
}

void Nibbler::updateDirection(eventKey evtKey)
{
    switch (evtKey) {
    case eventKey::LARROW:
        this->dir_ = direction::LEFT;
        break;
    case eventKey::UARROW:
        this->dir_ = direction::UP;
        break;
    case eventKey::BARROW:
        this->dir_ = direction::DOWN;
        break;
    case eventKey::RARROW:
        this->dir_ = direction::RIGHT;
        break;
    default:
        break;
    }
}

void Nibbler::moveSnake()
{
    for (std::size_t i = this->nibbler_.size() - 1; i >= 1; i--) {
        this->nibbler_[i].pos.x = this->nibbler_[i - 1].pos.x;
        this->nibbler_[i].pos.y = this->nibbler_[i - 1].pos.y;
    }

    switch (this->dir_) {
    case direction::LEFT:
        this->nibbler_[0].pos.x -= this->speed_;
        break;
    case direction::UP:
        this->nibbler_[0].pos.y -= this->speed_;
        break;
    case direction::DOWN:
        this->nibbler_[0].pos.y += this->speed_;
        break;
    case direction::RIGHT:
        this->nibbler_[0].pos.x += this->speed_;
        break;
    default:
        break;
    }
}

int Nibbler::updateGame(eventKey evtKey)
{
    this->updateDirection(evtKey);
    moveSnake();
    return 0;
}

std::string Nibbler::getSpritePath() { return ""; }
