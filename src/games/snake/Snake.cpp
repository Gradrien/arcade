/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include <random>

void Snake::reset()
{
    this->mapIndex_ = 0;
    if (!this->walls_.empty())
        this->walls_.clear();
    if (!this->food_.empty())
        this->food_.clear();
    if (!this->snake_.empty())
        this->snake_.clear();
    this->loadMap(this->mapIndex_);
    this->score_ = 0;
    this->timer_ = 0;
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    this->state = playerState::ALIVE;
    this->dir_ = direction::RIGHT;
}

void Snake::resetLevel()
{
    if (!this->walls_.empty())
        this->walls_.clear();
    if (!this->food_.empty())
        this->food_.clear();
    if (!this->snake_.empty())
        this->snake_.clear();
    this->loadMap(this->mapIndex_);
    this->score_ = 0;
    this->timer_ = 0;
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    this->state = playerState::ALIVE;
    this->dir_ = direction::RIGHT;
}

void Snake::loadMap(int index)
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
                this->initSnake(x * this->cellWidth_, y * this->cellHeight_);
            default:
                break;
            }
        }
    }
}

int Snake::init()
{
    loadMap(this->mapIndex_);
    initText();
    lastUpdateTime_ = std::chrono::steady_clock::now();
    return 0;
}

void Snake::restartEvent(eventKey evtKey)
{
    switch (evtKey) {
    case eventKey::R:
        this->resetLevel();
        break;
    default:
        break;
    }
}

std::string Snake::getSpritePath() { return ""; }

elemSize Snake::getDisplaySize()
{
    elemSize size = { .width = 800, .height = 800 };
    return size;
}
