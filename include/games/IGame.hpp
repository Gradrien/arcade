/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include <iostream>
#include <memory>
#include "IGraphic.hpp"

class IGame {
  public:
    virtual ~IGame() noexcept = default;
    virtual std::string getSpritePath() = 0;
    virtual void display(std::unique_ptr<IGraphic> &) = 0;
    virtual int init() = 0;
    virtual void reset() = 0;
    virtual int updateGame(eventKey evtKey) = 0;
};

#endif /* !IGAME_HPP_ */
