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
#include <chrono>
#include <fstream>
#include <vector>

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
 * @param WON
 * ***************************************************************/
enum class playerState { ALIVE,
    DEAD,
    STOP,
    WON };

const std::vector<std::vector<std::string>> allMaps = {
    {
        "11111111111111111111",
        "10000000000020000001",
        "10111110111111111001",
        "10000020000000200001",
        "10111010101210111001",
        "10001000020000100001",
        "10101110111010121001",
        "10001030002000100001",
        "10111011111110111001",
        "10020000202000000001",
        "10111011111111111001",
        "10000020000000200001",
        "10111010101010111001",
        "10001000200000100001",
        "10101110111010101001",
        "10001000000000100001",
        "10111011101110111001",
        "10000000202000000001",
        "10011111111111111001",
        "11111111111111111111",
    },
    {
        "11111111111111111111",
        "10020002002020002001",
        "10110100001110101101",
        "12112102000000121121",
        "10000102110020000001",
        "10011100000100111001",
        "12010200000000201021",
        "10000000020000000001",
        "10000111100111100001",
        "10000000002000000001",
        "10000200000000200001",
        "10011110011001111001",
        "10000000011000000001",
        "10020000020000002001",
        "10011010100001011001",
        "10011010000001011001",
        "12000210211201200021",
        "12011110011001111021",
        "10000000003000000001",
        "11111111111111111111",
    },
    {
        "11111111111111111111",
        "10020002002020002001",
        "10110100001110101101",
        "12112100020000121121",
        "10000102110020000001",
        "10011100000100111001",
        "12010200000000201021",
        "10000000020000000001",
        "10000111100111100001",
        "10000000002000000001",
        "10000200000000200001",
        "10011110011001111001",
        "10000000011000000001",
        "10020000020000002001",
        "10011010100001011001",
        "10011010000001011001",
        "12000210211201200021",
        "12011110011001111021",
        "10000000003000000001",
        "11111111111111111111",
    },
    {
        "11111111111111111111",
        "10000000000000000001",
        "10111111101111111001",
        "10200000202000002001",
        "10111111011111111101",
        "10000230000002000001",
        "10111111011111111101",
        "10202000002020000001",
        "10111111011111111101",
        "10200000200000002001",
        "10111111011111111101",
        "10000202020202000001",
        "10111111101111111001",
        "10002000000000200001",
        "10111111011111111101",
        "10200000200000002001",
        "10111111011111111101",
        "10000000002020000001",
        "11111111111111111111",
    },
    {
        "11111111111111111111",
        "10000000202020000001",
        "10111111111111111001",
        "10202000030000202001",
        "10111101111111111001",
        "10000000200002000001",
        "10111111111111111001",
        "10000020000000200001",
        "10111111111111111001",
        "10000200002000000001",
        "10111111111111111001",
        "10000020000000200001",
        "10111111111111111001",
        "10000000200002000001",
        "10111111111111111001",
        "10202000000000202001",
        "10111101111111111001",
        "10000000202020000001",
        "11111111111111111111",
    },
    {
        "11111111111111111111",
        "10020002000020002001",
        "10110100011000101101",
        "12112100000000121121",
        "10000102100120100001",
        "10011100100100111001",
        "12010200000000201021",
        "10000000020000000001",
        "10000111100111100001",
        "10000000002000000001",
        "10000200000000200001",
        "10011110011001111001",
        "10000000011000000001",
        "10020000020000002001",
        "10011010000001011001",
        "10011010000001011001",
        "12000210211201200021",
        "12011110011001111021",
        "10000000003000000001",
        "11111111111111111111",
    },
};

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
    void initNibbler(int x, int y);
    void initText();
    void loadMap(int index);
    void moveSnake(std::vector<shape>& tmp);
    bool isCollided(const shape& s1,const shape& s2);
    void updateDirection(eventKey evtKey);
    void foodHandler();
    void addWall(int x, int y);
    void addFood(int x, int y);
    void resetLevel();
    void restartEvent(eventKey evtKey);
    void chooseDirection();
    bool isNibblerInCell(int x, int y);
    void saveUserScore();
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
