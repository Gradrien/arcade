/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

void Nibbler::reset()
{
    this->mapIndex_ = 0;
    if (!this->walls_.empty())
        this->walls_.clear();
    if (!this->food_.empty())
        this->food_.clear();
    if (!this->nibbler_.empty())
        this->nibbler_.clear();
    this->loadMap(this->mapIndex_);
    this->score_ = 0;
    this->timer_ = 80;
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    this->state = playerState::ALIVE;
    this->dir_ = direction::RIGHT;
}

void Nibbler::resetLevel()
{
    if (!this->walls_.empty())
        this->walls_.clear();
    if (!this->food_.empty())
        this->food_.clear();
    if (!this->nibbler_.empty())
        this->nibbler_.clear();
    this->loadMap(this->mapIndex_);
    this->timer_ += 20;
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    this->state = playerState::ALIVE;
    this->dir_ = direction::RIGHT;
}

int Nibbler::init()
{
    loadMap(this->mapIndex_);
    timer_ = 80;
    initText();
    return 0;
}

void Nibbler::restartEvent(eventKey evtKey)
{
    switch (evtKey) {
    case eventKey::R:
        this->resetLevel();
        break;
    default:
        break;
    }
}

std::string Nibbler::getSpritePath() { return ""; }
