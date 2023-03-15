/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include "DLLoader.hpp"
#include "Error.hpp"
#include "IGame.hpp"
#include "IGraphic.hpp"
#include <memory>
#include <filesystem>

enum class GState { PLAY, PAUSE, MENU };

class Core {
  public:
    Core(const char *libName);
    ~Core() = default;
    void getAllLib();
    void handleEvent();
    void updateGame();
    void displayGame();
    void gameLoopHandler();

  private:
    eventKey event_;
    GState gameState_;
    std::unique_ptr<IGraphic> graphLib_;
    std::unique_ptr<IGame> gameLib_;
    DLLoader<IGraphic> graphLoader_ { DLLoader<IGraphic>() };
    DLLoader<IGame> gameLoader_ { DLLoader<IGame>() };
    std::vector<std::string> gamePaths;
    std::vector<std::string> graphPaths;
};

#endif /* !CORE_HPP_ */
