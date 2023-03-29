/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

/****************************************************************
 * @file Nibbler.hpp
 * @brief Nibbler class
 * @details This class is used to handle the Nibbler game
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_
#include "IGame.hpp"
#include <vector>
#include <chrono>

/****************************************************************
 * @brief Direction enum
 * @details This enum is used to handle the direction of the snake
 * @param UP
 * @param DOWN
 * @param LEFT
 * @param RIGHT
 * ***************************************************************/
enum class direction { UP, DOWN, LEFT, RIGHT };

/****************************************************************
 * @brief Player state enum
 * @details This enum is used to handle the state of the player
 * @param ALIVE
 * @param DEAD
 * @param STOP
 * ***************************************************************/
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
                                                        },
    {
        "11111111111111111111",
        "10000000000020000001",
        "10000000000000000001",
        "10020000111111100001",
        "10000000000000100001",
        "10000000000000100001",
        "10000000000000100001",
        "10001111111111111001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000020001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000001000000001",
        "10000000001000000001",
        "10003000001000000001",
        "11111111111111111111",
    } };

/****************************************************************
 * @class Nibbler
 * @brief Nibbler class
 * @details This class is used to handle the Nibbler game
 * ***************************************************************/
class Nibbler : public IGame {
  public:
    Nibbler() = default;
    ~Nibbler() = default;
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
    void display(IGraphic &) override;
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

  private:
    void initNibbler(int x, int y);
    void initText();
    void loadMap(int index);
    void moveSnake(std::vector<shape>& tmp);
    bool isCollided(shape s1, shape s2);
    void updateDirection(eventKey evtKey);
    void foodHandler();
    void addWall(int x, int y);
    void addFood(int x, int y);
    void resetLevel();
    void restartEvent(eventKey evtKey);
    void chooseDirection();
    bool isNibblerInCell(int x, int y);
    direction dir_ { direction::RIGHT };
    int nibblerSize_ { 4 };
    std::vector<shape> walls_;
    std::vector<shape> nibbler_;
    std::vector<shape> food_;
    std::vector<text> texts_;
    int cellWidth_ { 20 };
    int cellHeight_ { 20 };
    int mapIndex_ { 0 };
    int remainingFood_ { 0 };
    int score_ { 0 };
    int timer_ { 0 };
    playerState state { playerState::ALIVE };
    std::chrono::steady_clock::time_point lastUpdateTime_;
};

#endif /* !NIBBLER_HPP_ */
