/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** TestGame
*/

/****************************************************************
 * @file TestGame.hpp
 * @brief TestGame class
 * @details This class is used to handle the TestGame game
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef TESTGAME_HPP_
#define TESTGAME_HPP_
#include "IGame.hpp"
#include "IGraphic.hpp"
#include <string>

/****************************************************************
 * @class TestGame
 * @brief TestGame class
 * @details This class is used to handle the TestGame game
 * **************************************************************/
class TestGame : public IGame {
  public:
    TestGame() = default;
    ~TestGame() noexcept = default;
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
    void display(std::unique_ptr<IGraphic>&) override;
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
    shape rect;
};

#endif /* !TESTGAME_HPP_ */
