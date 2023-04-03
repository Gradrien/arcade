/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Display
*/

#include "Snake.hpp"
#include <random>

void Snake::display(IGraphic& graphLib)
{
    if (this->state == playerState::DEAD) {
        for (std::size_t i = 0; i < texts_.size(); ++i) {
            graphLib.displayText(texts_[i]);
        }
        return;
    }
    for (shape wall : this->walls_) {
        graphLib.displayShape(wall);
    }
    for (shape fruit : this->food_) {
        graphLib.displayShape(fruit);
    }
    for (shape part : this->snake_) {
        graphLib.displayShape(part);
    }
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    for (std::size_t i = 0; i < 2; ++i) {
        graphLib.displayText(texts_[i]);
    }
}

void Snake::addWall(int x, int y)
{
    shape wall = { .pos { x * this->cellWidth_, y * this->cellHeight_ },
        .size { this->cellWidth_, this->cellHeight_ },
        .m_color { 7, 71, 166, 255 },
        .replacementChar = '#',
        .text = "",
        .type = shapeType::RECTANGLE };
    this->walls_.push_back(wall);
}

void Snake::addFood(int x, int y)
{
    shape food = { .pos { x * this->cellWidth_, y * this->cellHeight_ },
        .size { this->cellWidth_, this->cellHeight_ },
        .m_color { 153, 35, 29, 255 },
        .replacementChar = '#',
        .text = "",
        .type = shapeType::RECTANGLE };
    this->food_.push_back(food);
}

void Snake::initText()
{
    text score;
    text timer;
    text gameOver;

    score.fontSize = 30;
    score.fontPath = "assets/fonts/arial.ttf";
    score.m_color = { 255, 255, 255, 255 };
    score.pos = { 50, 0 };
    score.text = "Score: " + std::to_string(score_);
    score.size = { static_cast<int>(score.fontSize * 1.33 * 0.46 * score.text.length()), static_cast<int>(score.fontSize * 1.33) };
    timer.fontSize = 30;
    timer.fontPath = "assets/fonts/arial.ttf";
    timer.m_color = { 255, 255, 255, 255 };
    timer.pos = { 600, 0 };
    timer.text = "Timer: " + std::to_string(timer_);
    timer.size = { static_cast<int>(timer.fontSize * 1.33 * 0.46 * timer.text.length()), static_cast<int>(timer.fontSize * 1.33) };
    gameOver.size = { static_cast<int>(gameOver.fontSize * 1.33 * 0.46 * gameOver.text.length()), static_cast<int>(gameOver.fontSize * 1.33) };
    gameOver.fontSize = 30;
    gameOver.fontPath = "assets/fonts/arial.ttf";
    gameOver.m_color = { 255, 0, 0, 255 };
    gameOver.pos = { 200, 350 };
    gameOver.text = "YOU LOST! Press R to restart";
    gameOver.size = { static_cast<int>(gameOver.fontSize * 1.33 * 0.46 * gameOver.text.length()), static_cast<int>(gameOver.fontSize * 1.33) };
    this->texts_.push_back(score);
    this->texts_.push_back(timer);
    this->texts_.push_back(gameOver);
}

void Snake::initSnake(int x, int y)
{
    for (int i = 0; i < this->snakeSize_; i++) {
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
        this->snake_.push_back(obj);
    }
}
