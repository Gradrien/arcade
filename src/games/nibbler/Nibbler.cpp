/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

void Nibbler::reset()
{
    this->nibblerSize_ = 4;
}

void Nibbler::initNibbler(int x, int y)
{
    for (int i = 0; i < this->nibblerSize_; i++) {
        shape obj;
        if (i == 0) {
            obj = { .pos { x - (i * this->cellWidth_), y },
                .size { this->cellWidth_, this->cellHeight_ },
                .m_color = { 123, 148, 144, 255 },
                .replacementChar = 'x',
                .text = "",
                .type = shapeType::RECTANGLE };
        } else {
            obj = { .pos { x - (i * this->cellWidth_), y },
                .size { this->cellWidth_, this->cellHeight_ },
                .m_color = { 2, 130, 108, 255 },
                .replacementChar = 'o',
                .text = "",
                .type = shapeType::RECTANGLE };
        }
        this->nibbler_.push_back(obj);
    }
}

void Nibbler::addWall(int x, int y)
{
    shape wall = { .pos { x * this->cellWidth_, y * this->cellHeight_ },
        .size { this->cellWidth_, this->cellHeight_ },
        .m_color { 7, 71, 166, 255 },
        .replacementChar = '#',
        .text = "",
        .type = shapeType::RECTANGLE };
    this->walls_.push_back(wall);
}

void Nibbler::addFood(int x, int y)
{
    shape food = { .pos { x * this->cellWidth_, y * this->cellHeight_ },
        .size { this->cellWidth_, this->cellHeight_ },
        .m_color { 153, 35, 29, 255 },
        .replacementChar = '#',
        .text = "",
        .type = shapeType::RECTANGLE };
    this->food_.push_back(food);
}

void Nibbler::loadMap(int index)
{
    this->cellHeight_ = 800 / allMaps[index].size();
    this->cellWidth_ = 800 / allMaps[index][0].size();
    for (std::size_t y = 0; y < allMaps[index].size(); y++) {
        for (std::size_t x = 0; x < allMaps[index][y].size(); x++) {
            switch (allMaps[index][y][x]) {
            case '1':
                this->addWall(x, y);
                break;
            case '2':
                this->addFood(x, y);
                break;
            case '3':
                this->initNibbler(x * this->cellWidth_, y * this->cellHeight_);
            default:
                break;
            }
        }
    }
}

bool Nibbler::isCollided(shape s1, shape s2)
{
    if (((s1.pos.x + s1.size.width) > s2.pos.x) && (s1.pos.x < (s2.pos.x + s2.size.width))) {
        if (((s1.pos.y + s1.size.height) > s2.pos.y) && (s1.pos.y < (s2.pos.y + s2.size.height))) {
            return true;
        }
    }
    return false;
}

int Nibbler::init()
{
    loadMap(this->mapIndex_);
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
        if (this->dir_ != direction::RIGHT) {
            this->dir_ = direction::LEFT;
            this->state = playerState::ALIVE;
        }
        break;
    case eventKey::UARROW:
        if (this->dir_ != direction::DOWN) {
            this->dir_ = direction::UP;
            this->state = playerState::ALIVE;
        }
        break;
    case eventKey::BARROW:
        if (this->dir_ != direction::UP) {
            this->dir_ = direction::DOWN;
            this->state = playerState::ALIVE;
        }
        break;
    case eventKey::RARROW:
        if (this->dir_ != direction::LEFT) {
            this->dir_ = direction::RIGHT;
            this->state = playerState::ALIVE;
        }
        break;
    default:
        break;
    }
}

void Nibbler::moveSnake(std::vector<shape>&tmp)
{
    for (std::size_t i = tmp.size() - 1; i >= 1; i--) {
        tmp[i].pos.x = tmp[i - 1].pos.x;
        tmp[i].pos.y = tmp[i - 1].pos.y;
    }

    switch (this->dir_) {
    case direction::LEFT:
        tmp[0].pos.x -= this->cellWidth_;
        break;
    case direction::UP:
        tmp[0].pos.y -= this->cellHeight_;
        break;
    case direction::DOWN:
        tmp[0].pos.y += this->cellHeight_;
        break;
    case direction::RIGHT:
        tmp[0].pos.x += this->cellWidth_;
        break;
    default:
        break;
    }
}

int Nibbler::updateGame(eventKey evtKey)
{
    std::vector<shape> tmp = this->nibbler_;
    this->updateDirection(evtKey);
    if (this->state == playerState::ALIVE)
        this->moveSnake(tmp);
    for (shape wall : this->walls_) {
        if (this->isCollided(tmp[0], wall)) {
            this->state = playerState::STOP;
            return 0;
        }
    }
    this->nibbler_ = tmp;
    this->foodHandler();
    return 0;
}

std::string Nibbler::getSpritePath() { return ""; }

void Nibbler::foodHandler()
{
    for (std::size_t i = 0; i < this->food_.size(); i++) {
        if (isCollided(this->food_[i], this->nibbler_[0])) {
            shape obj = { .pos { this->nibbler_[this->nibbler_.size() - 1].pos.x - this->cellWidth_,
                              this->nibbler_[this->nibbler_.size() - 1].pos.y },
                .size { this->cellWidth_, this->cellHeight_ },
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
