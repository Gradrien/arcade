/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

/****************************************************************
 * @file Snake.hpp
 * @brief Snake class
 * @details This class is used to handle the Snake game
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include "IGame.hpp"
#include <chrono>
#include <vector>
#include <fstream>

/****************************************************************
 * @brief Direction enum
 * @details This enum is used to handle the direction of the snake
 * @param UP
 * @param DOWN
 * @param LEFT
 * @param RIGHT
 * ***************************************************************/
enum class direction { UP,
    DOWN,
    LEFT,
    RIGHT };

/****************************************************************
 * @brief Player state enum
 * @details This enum is used to handle the state of the player
 * @param ALIVE
 * @param DEAD
 * @param STOP
 * ***************************************************************/
enum class playerState { ALIVE,
    DEAD,
    STOP };

const std::vector<std::vector<std::string>> allMaps = {
    {
        "11111111111111111111",
        "10000000000000000001",
        "10000000000000000001",
        "10020000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000003000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "11111111111111111111",
    },
};

/****************************************************************
 * @class Snake
 * @brief Snake class
 * @details This class is used to handle the Snake game
 * ***************************************************************/
class Snake : public IGame {
  public:
    Snake() = default;
    ~Snake() = default;
    /****************************************************************
     * @brief Get the sprite path
     * @details This function is used to get the sprite path
     * @return std::string
     * ***************************************************************/
    std::string getSpritePath() override;
    /****************************************************************
     * @brief Display the game
     * @details This function is used to display the game
     * @param IGraphic
     * ***************************************************************/
    void display(IGraphic&) override;
    /****************************************************************
     * @brief init the game
     * @details This function is used to init the game and load the map
     * @return int
     * ***************************************************************/
    int init() override;
    /****************************************************************
     * @brief Reset the game
     * @details This function is used to reset the game
     * ***************************************************************/
    void reset() override;
    /****************************************************************
     * @brief Update the game
     * @details This function is used to update the game
     * @param eventKey
     * @return int
     * ***************************************************************/
    int updateGame(eventKey evtKey) override;
    /****************************************************************
     * @brief Get the display size
     * @details This function is used to return the size of the window for the game
     * @return elemSize
     * ************************************************/
    elemSize getDisplaySize() override;

  private:
    void initSnake(int x, int y);
    void initText();
    void loadMap(int index);
    void moveSnake(std::vector<shape>& tmp);
    bool isCollided(shape s1, shape s2);
    void updateDirection(eventKey evtKey);
    void foodHandler();
    void addWall(int x, int y);
    void addFood(int x, int y);
    void resetLevel();
    void saveUserScore();
    void gameOver();
    void restartEvent(eventKey evtKey);
    bool isSnakeInCell(int x, int y);
    direction dir_ { direction::RIGHT };
    int snakeSize_ { 4 };
    std::vector<shape> walls_;
    std::vector<shape> snake_;
    std::vector<shape> food_;
    std::vector<text> texts_;
    int cellWidth_ { 20 };
    int cellHeight_ { 20 };
    int mapIndex_ { 0 };
    int score_ { 0 };
    int timer_ { 0 };
    playerState state { playerState::ALIVE };
    std::chrono::steady_clock::time_point lastUpdateTime_;
};

#endif /* !SNAKE_HPP_ */
