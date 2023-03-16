/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** TestGame
*/

#ifndef TESTGAME_HPP_
#define TESTGAME_HPP_
#include "IGame.hpp"
#include "IGraphic.hpp"
#include <string>

class TestGame : public IGame {
  public:
    TestGame() = default;
    ~TestGame() noexcept = default;
    std::string getSpritePath() override;
    void display(std::unique_ptr<IGraphic>&) override;
    int init() override;
    void reset() override;
    int updateGame(eventKey evtKey) override;

  private:
    shape rect;
};

#endif /* !TESTGAME_HPP_ */
