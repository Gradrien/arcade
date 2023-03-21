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

enum class playerState { ALIVE, DEAD, STOP };

const std::vector<std::vector<std::string>> allMaps = { {
    "11111111111111111111",
    "10000000000000000001",
    "10000011111111111111",
    "10020000000001000001",
    "10000000000001000001",
    "10000200000001000001",
    "10000000000001000001",
    "10000000000001000001",
    "10000000000001000001",
    "10020000100000000011",
    "10000000100000000011",
    "10000000100000020011",
    "10000000100000000011",
    "10000000100000000011",
    "10000000100000000011",
    "10000000111111111111",
    "10000200001000000001",
    "10000000001000000001",
    "10003000001000000001",
    "11111111111111111111",
} };

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
    void initNibbler(int x, int y);
    void loadMap(int index);
    void moveSnake(std::vector<shape>& tmp);
    bool isCollided(shape s1, shape s2);
    void updateDirection(eventKey evtKey);
    void foodHandler();
    void addWall(int x, int y);
    void addFood(int x, int y);
    direction dir_ { direction::RIGHT };
    int nibblerSize_ { 4 };
    std::vector<shape> walls_;
    std::vector<shape> nibbler_;
    std::vector<shape> food_;
    int cellWidth_ { 20 };
    int cellHeight_ { 20 };
    int mapIndex_ { 0 };
    playerState state { playerState::ALIVE };
};

#endif /* !NIBBLER_HPP_ */
