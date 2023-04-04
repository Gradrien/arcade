/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Compute
*/

#include "Nibbler.hpp"

bool Nibbler::isCollided(const shape& s1, const shape& s2)
{
    if (((s1.pos.x + s1.size.width) > s2.pos.x) && (s1.pos.x < (s2.pos.x + s2.size.width))) {
        if (((s1.pos.y + s1.size.height) > s2.pos.y) && (s1.pos.y < (s2.pos.y + s2.size.height))) {
            return true;
        }
    }
    return false;
}

void Nibbler::saveUserScore()
{
    std::ofstream file("./score.txt", std::ios::app);

    if (file.is_open()) {
        file << " " << score_ << std::endl;
        file.close();
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
    case eventKey::ONE:
        this->mapIndex_ += 1;
        if (static_cast<std::size_t>(this->mapIndex_) >= allMaps.size())
            this->mapIndex_ = 0;
        resetLevel();
        break;
    default:
        break;
    }
}

void Nibbler::moveSnake(std::vector<shape>& tmp)
{
    if (this->state == playerState::DEAD || this->state == playerState::WON)
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

int Nibbler::updateGame(eventKey evtKey)
{
    std::vector<shape> tmp = this->nibbler_;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdateTime_).count();

    if (elapsed >= 1000 && timer_ > 0) {
        timer_ -= 1;
        lastUpdateTime_ = now;
    }
    if (timer_ > 78 && score_ == 0)
        return 0;
    if (timer_ == 0)
        this->state = playerState::DEAD;
    if (this->state != playerState::DEAD && this->state != playerState::WON)
        this->updateDirection(evtKey);
    if (this->state == playerState::DEAD || this->state == playerState::WON) {
        if (!this->nibbler_.empty()) {
            this->nibbler_.pop_back();
            return 0;
        }
        restartEvent(evtKey);
        return 0;
    }

    if (this->state == playerState::ALIVE)
        this->moveSnake(tmp);
    for (const shape& wall : this->walls_) {
        if (this->isCollided(tmp[0], wall)) {
            this->chooseDirection();
            return 0;
        }
    }
    this->nibbler_ = tmp;
    for (std::size_t i = 1; i < this->nibbler_.size(); i++) {
        if ((this->nibbler_[i].pos.x == this->nibbler_[0].pos.x)
            && (this->nibbler_[i].pos.y == this->nibbler_[0].pos.y)) {
            this->state = playerState::DEAD;
            saveUserScore();
            return 0;
        }
    }
    this->foodHandler();
    if (this->remainingFood_ <= 0) {
        if (allMaps.size() == static_cast<std::size_t>(this->mapIndex_ + 1)) {
            this->state = playerState::WON;
            return 0;
        } else
            this->mapIndex_++;
        this->resetLevel();
    }
    return 0;
}

void Nibbler::chooseDirection()
{
    const coord pos = { .x = this->nibbler_[0].pos.x / this->cellWidth_, .y = this->nibbler_[0].pos.y / this->cellHeight_ };
    const bool up = (allMaps[this->mapIndex_][pos.y - 1][pos.x] != '1') && !isNibblerInCell(pos.x, pos.y - 1);
    const bool down = (allMaps[this->mapIndex_][pos.y + 1][pos.x] != '1') && !isNibblerInCell(pos.x, pos.y + 1);
    const bool left = (allMaps[this->mapIndex_][pos.y][pos.x - 1] != '1') && !isNibblerInCell(pos.x - 1, pos.y);
    const bool right = (allMaps[this->mapIndex_][pos.y][pos.x + 1] != '1') && !isNibblerInCell(pos.x + 1, pos.y);

    if (this->dir_ == direction::LEFT || this->dir_ == direction::RIGHT) {
        if (up && !down) {
            this->dir_ = direction::UP;
            return;
        }
        if (!up && down) {
            this->dir_ = direction::DOWN;
            return;
        }
    } else {
        if (left && !right) {
            this->dir_ = direction::LEFT;
            return;
        }
        if (!left && right) {
            this->dir_ = direction::RIGHT;
            return;
        }
    }
    this->state = playerState::STOP;
}

void Nibbler::foodHandler()
{
    for (std::size_t i = 0; i < this->food_.size(); i++) {
        if (isCollided(this->food_[i], this->nibbler_[0])) {
            const shape obj = { .pos { this->nibbler_[this->nibbler_.size() - 1].pos.x - this->cellWidth_,
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
                const std::vector<shape>::iterator it = this->food_.begin() + i;
                this->food_.erase(it);
            }
            this->remainingFood_--;
            this->score_ += 1;
        }
    }
}

bool Nibbler::isNibblerInCell(int x, int y)
{
    for (const shape& part : this->nibbler_) {
        if (part.pos.x == (x * this->cellWidth_) && part.pos.y == (y * this->cellHeight_)) {
            return true;
        }
    }
    return false;
}
