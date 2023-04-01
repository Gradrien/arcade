/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include <random>

int random(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);

    return dist(gen);
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

bool Snake::isCollided(shape s1, shape s2)
{
    if (((s1.pos.x + s1.size.width) > s2.pos.x) && (s1.pos.x < (s2.pos.x + s2.size.width))) {
        if (((s1.pos.y + s1.size.height) > s2.pos.y) && (s1.pos.y < (s2.pos.y + s2.size.height))) {
            return true;
        }
    }
    return false;
}

int Snake::init()
{
    loadMap(this->mapIndex_);
    initText();
    lastUpdateTime_ = std::chrono::steady_clock::now();
    return 0;
}

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

void Snake::updateDirection(eventKey evtKey)
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

void Snake::moveSnake(std::vector<shape>& tmp)
{
    if (this->state == playerState::DEAD)
        return;
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

bool Snake::isSnakeInCell(int x, int y)
{
    for (shape part : this->snake_) {
        if (part.pos.x == (x * this->cellWidth_) && part.pos.y == (y * this->cellHeight_)) {
            return true;
        }
    }
    return false;
}

void Snake::gameOver()
{
    this->state = playerState::DEAD;
}

int Snake::updateGame(eventKey evtKey)
{
    std::vector<shape> tmp = this->snake_;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdateTime_).count();

    if (elapsed >= 1000) {
        timer_ += 1;
        lastUpdateTime_ = now;
    }
    if (timer_ < 1)
        return 0;
    if (this->state == playerState::ALIVE)
        this->updateDirection(evtKey);
    if (this->state == playerState::DEAD) {
        if (!this->snake_.empty()) {
            this->snake_.pop_back();
            return 0;
        }
        restartEvent(evtKey);
        return 0;
    }

    if (this->state == playerState::ALIVE)
        this->moveSnake(tmp);
    for (shape wall : this->walls_) {
        if (this->isCollided(tmp[0], wall)) {
            this->gameOver();
            return 0;
        }
    }
    this->snake_ = tmp;
    for (std::size_t i = 1; i < this->snake_.size(); i++) {
        if ((this->snake_[i].pos.x == this->snake_[0].pos.x)
            && (this->snake_[i].pos.y == this->snake_[0].pos.y)) {
            this->state = playerState::DEAD;
            return 0;
        }
    }
    this->foodHandler();
    return 0;
}

std::string Snake::getSpritePath() { return ""; }

void Snake::foodHandler()
{
    int x = random(1, 18);
    int y = random(1, 18);

    for (std::size_t i = 0; i < this->food_.size(); i++) {
        if (isCollided(this->food_[i], this->snake_[0])) {
            shape obj = { .pos { this->snake_[this->snake_.size() - 1].pos.x - this->cellWidth_,
                              this->snake_[this->snake_.size() - 1].pos.y },
                .size { this->cellWidth_, this->cellHeight_ },
                .m_color = { 2, 130, 108, 255 },
                .replacementChar = 'o',
                .text = "",
                .type = shapeType::RECTANGLE };
            this->snake_.push_back(obj);
            if (i + 1 == this->food_.size())
                this->food_.pop_back();
            else {
                std::vector<shape>::iterator it = this->food_.begin() + i;
                this->food_.erase(it);
            }
            while (isSnakeInCell(x, y)) {
                x = random(1, 18);
                y = random(1, 18);
            }
            this->addFood(x, y);
            this->score_ += 1;
        }
    }
}

elemSize Snake::getDisplaySize(void)
{
    elemSize size = { .width = 1200, .height = 800 };
    return size;
}
