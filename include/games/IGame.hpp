/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGame
*/

/****************************************************************
 * @file IGame.hpp
 * @brief Interface for game library
 * @version 0.1
 * @date 2021-03-15
 ****************************************************************/
#ifndef IGAME_HPP_
#define IGAME_HPP_
#include <iostream>
#include <memory>
#include "IGraphic.hpp"

/****************************************************************
 * @class IGame
 * @brief Interface for game library
 * @details This interface is used to handle the game library
 * ***************************************************************/
class IGame {
  public:
    virtual ~IGame() noexcept = default;
    /****************************************************************
     * @brief Get the sprite path
     * @details This function is used to get the sprite path
     * ************************************************/
    virtual std::string getSpritePath() = 0;
    /****************************************************************
     * @brief Display the game
     * @param IGraphic&
     * @details This function is used to display the game
     * ************************************************/
    virtual void display(std::unique_ptr<IGraphic> &) = 0;
    /****************************************************************
     * @brief Init the game
     * @details This function is used to init the game
     * @return int
     * ************************************************/
    virtual int init() = 0;
    /****************************************************************
     * @brief Reset the game
     * @details This function is used to reset the game
     * ************************************************/
    virtual void reset() = 0;
    /****************************************************************
     * @brief Update the game
     * @param eventKey
     * @details This function is used to update the game
     * @return int
     * ************************************************/
    virtual int updateGame(eventKey evtKey) = 0;
};

#endif /* !IGAME_HPP_ */
