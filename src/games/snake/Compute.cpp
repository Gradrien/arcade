/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Compute
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

bool Snake::isCollided(const shape& s1, const shape& s2)
{
    if (((s1.pos.x + s1.size.width) > s2.pos.x) && (s1.pos.x < (s2.pos.x + s2.size.width))) {
        if (((s1.pos.y + s1.size.height) > s2.pos.y) && (s1.pos.y < (s2.pos.y + s2.size.height))) {
            return true;
        }
    }
    return false;
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
    for (const shape& part : this->snake_) {
        if (part.pos.x == (x * this->cellWidth_) && part.pos.y == (y * this->cellHeight_)) {
            return true;
        }
    }
    return false;
}

void Snake::saveUserScore()
{
    std::ofstream file("./score.txt", std::ios::app);

    if (file.is_open()) {
        file << " " << score_ << std::endl;
        file.close();
    }
}

void Snake::gameOver()
{
    this->state = playerState::DEAD;
    saveUserScore();
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
    for (const shape& wall : this->walls_) {
        if (this->isCollided(tmp[0], wall)) {
            this->gameOver();
            return 0;
        }
    }
    this->snake_ = tmp;
    for (std::size_t i = 1; i < this->snake_.size(); i++) {
        if ((this->snake_[i].pos.x == this->snake_[0].pos.x)
            && (this->snake_[i].pos.y == this->snake_[0].pos.y)) {
            this->gameOver();
            return 0;
        }
    }
    this->foodHandler();
    return 0;
}

void Snake::foodHandler()
{
    int x = random(1, 18);
    int y = random(1, 18);

    for (std::size_t i = 0; i < this->food_.size(); i++) {
        if (isCollided(this->food_[i], this->snake_[0])) {
            const shape obj = { .pos { this->snake_[this->snake_.size() - 1].pos.x - this->cellWidth_,
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
                const std::vector<shape>::iterator it = this->food_.begin() + i;
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
