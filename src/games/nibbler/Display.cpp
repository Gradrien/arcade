/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Display
*/

#include "Nibbler.hpp"

elemSize Nibbler::getDisplaySize()
{
    elemSize size = { .width = 800, .height = 800 };
    return size;
}

void Nibbler::initText()
{
    text score;
    text timer;
    text gameOver;
    text youWon;

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
    gameOver.fontSize = 30;
    gameOver.fontPath = "assets/fonts/arial.ttf";
    gameOver.m_color = { 255, 0, 0, 255 };
    gameOver.pos = { 200, 350 };
    gameOver.text = "YOU LOST! Press R to restart";
    gameOver.size = { static_cast<int>(gameOver.fontSize * 1.33 * 0.46 * gameOver.text.length()), static_cast<int>(gameOver.fontSize * 1.33) };
    youWon.fontSize = 30;
    youWon.fontPath = "assets/fonts/arial.ttf";
    youWon.m_color = { 0, 255, 0, 255 };
    youWon.pos = { 200, 350 };
    youWon.text = "YOU WON! Press R to restart";
    youWon.size = { static_cast<int>(youWon.fontSize * 1.33 * 0.46 * youWon.text.length()), static_cast<int>(youWon.fontSize * 1.33) };
    this->texts_.push_back(score);
    this->texts_.push_back(timer);
    this->texts_.push_back(gameOver);
    this->texts_.push_back(youWon);
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

void Nibbler::display(IGraphic& graphLib)
{
    if (this->state == playerState::DEAD) {
        for (std::size_t i = 0; i < (texts_.size() - 1); ++i) {
            graphLib.displayText(texts_[i]);
        }
        return;
    }
    if (this->state == playerState::WON) {
        for (std::size_t i = 0; i < texts_.size(); ++i) {
            if (i != 2)
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
    for (shape part : this->nibbler_) {
        graphLib.displayShape(part);
    }
    texts_[0].text = "Score: " + std::to_string(score_);
    texts_[1].text = "Timer: " + std::to_string(timer_);
    for (std::size_t i = 0; i < 2; ++i) {
        graphLib.displayText(texts_[i]);
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
    this->remainingFood_ = 0;
    for (std::size_t y = 0; y < allMaps[index].size(); y++) {
        for (std::size_t x = 0; x < allMaps[index][y].size(); x++) {
            switch (allMaps[index][y][x]) {
            case '1':
                this->addWall(x, y);
                break;
            case '2':
                this->addFood(x, y);
                this->remainingFood_++;
                break;
            case '3':
                this->initNibbler(x * this->cellWidth_, y * this->cellHeight_);
            default:
                break;
            }
        }
    }
}
