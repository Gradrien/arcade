/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_
#include "IGame.hpp"
#include <vector>

enum class direction { UP, DOWN, LEFT, RIGHT };

class Nibbler : public IGame {
  public:
    Nibbler() = default;
    ~Nibbler() = default;
    std::string getSpritePath() override;
    void display(std::unique_ptr<IGraphic>&) override;
    int init() override;
    void reset() override;
    int updateGame(eventKey evtKey) override;

  private:
    void parseMap(const std::string& path);
    void initNibbler();
    void moveSnake();
    void updateDirection(eventKey evtKey);
    direction dir_ { direction::RIGHT };
    int nibblerSize_ { 4 };
    unsigned int speed_ { 20 };
    std::vector<shape> walls_;
    std::vector<shape> nibbler_;
    std::vector<shape> food_;
    int cellSize_ { 20 };
};

#endif /* !NIBBLER_HPP_ */
