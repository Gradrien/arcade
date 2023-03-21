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
    for (int i = 0; i < this->nibblerSize_; i++) {
        shape obj;
        if (i == 0) {
            obj = { .pos { ((4 * this->cellSize_) - ((this->nibblerSize_ - 1) * cellSize_)), 60 },
                .size { this->cellSize_, this->cellSize_ },
                .m_color = { 123, 148, 144, 255 },
                .replacementChar = 'o',
                .text = "",
                .type = shapeType::RECTANGLE };
        } else {
            obj = { .pos { ((4 * this->cellSize_) - (i * cellSize_)), 60 },
                .size { this->cellSize_, this->cellSize_ },
                .m_color = { 2, 130, 108, 255 },
                .replacementChar = 'o',
                .text = "",
                .type = shapeType::RECTANGLE };
        }
        this->nibbler_.push_back(obj);
    }
}

void Nibbler::initMap() { this->walls_ = wallMaps[0]; }

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
    this->food_ = fruitMaps[0];
    return 0;
}

void Nibbler::display(std::unique_ptr<IGraphic>& graphLib)
{
    if (this->state == playerState::DEAD)
        return;
    for (shape wall : this->walls_) {
        graphLib->displayShape(wall);
    }
    for (shape fruit : this->food_) {
        graphLib->displayShape(fruit);
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
    for (shape wall : this->walls_) {
        if (this->isCollided(this->nibbler_[0], wall)) {
            this->state = playerState::DEAD;
            return 0;
        }
    }
    this->foodHandler();
    return 0;
}

std::string Nibbler::getSpritePath() { return ""; }

void Nibbler::foodHandler()
{
    for (std::size_t i = 0; i < this->food_.size(); i++) {
        if (isCollided(this->food_[i], this->nibbler_[0])) {
            shape obj = { .pos { this->nibbler_[this->nibbler_.size() - 1].pos.x - this->cellSize_,
                              this->nibbler_[this->nibbler_.size() - 1].pos.y },
                .size { this->cellSize_, this->cellSize_ },
                .m_color = { 2, 130, 108, 255 },
                .replacementChar = 'o',
                .text = "",
                .type = shapeType::RECTANGLE };
            this->nibbler_.push_back(obj);
            if (i + 1 == this->food_.size())
                this->food_.pop_back();
            else {
                std::vector<shape>::iterator it = this->food_.begin() + i;
                this->food_.erase(it);
            }
        }
    }
}
