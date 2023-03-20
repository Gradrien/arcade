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
    color color[] = { { .r = 255, .g = 255, .b = 255, .a = 255 }, { .r = 240, .g = 0, .b = 0, .a = 255 },
        { .r = 0, .g = 254, .b = 0, .a = 255 }, { .r = 0, .g = 0, .b = 255, .a = 255 } };

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

void Nibbler::initMap() { this->walls_ = allMaps[0]; }

bool Nibbler::isCollided(shape s1, shape s2)
{
    if ((s1.pos.x >= s2.pos.x) && (s1.pos.x <= s2.pos.x + s2.size.width)) {
        if ((s1.pos.y >= s2.pos.y) && (s1.pos.y <= s2.pos.y + s2.size.height)) {
            return true;
        }
    }
    return false;
}

int Nibbler::init()
{
    initNibbler();
    initMap();
    return 0;
}

void Nibbler::display(std::unique_ptr<IGraphic>& graphLib)
{
    if (this->state == playerState::DEAD)
        return;
    for (shape wall : this->walls_) {
        graphLib->displayShape(wall);
    }
    for (shape part : this->nibbler_) {
        graphLib->displayShape(part);
    }
}

void Nibbler::updateDirection(eventKey evtKey)
{
    switch (evtKey) {
    case eventKey::LARROW:
        if (this->dir_ != direction::RIGHT)
            this->dir_ = direction::LEFT;
        break;
    case eventKey::UARROW:
        if (this->dir_ != direction::DOWN)
            this->dir_ = direction::UP;
        break;
    case eventKey::BARROW:
        if (this->dir_ != direction::UP)
            this->dir_ = direction::DOWN;
        break;
    case eventKey::RARROW:
        if (this->dir_ != direction::LEFT)
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
    this->moveSnake();
    for (shape snakePart : this->nibbler_) {
        for (shape wall : this->walls_) {
            if (this->isCollided(snakePart, wall)) {
                this->state = playerState::DEAD;
                return 0;
            }
        }
    }
    return 0;
}

std::string Nibbler::getSpritePath() { return ""; }
