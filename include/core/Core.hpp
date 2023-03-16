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
#include "Menu.hpp"
#include <memory>
#include <filesystem>

enum class GState { PLAY, PAUSE, MENU };

class Menu;
class Core {
  public:
    Core(const char *libName);
    ~Core() = default;
    void getAllLib();
    void handleEvent();
    void updateGame();
    void displayGame();
    void gameLoopHandler();
    void loadNextGraph();
    void loadNextGame();
    void restartGame();
    void pushLib(std::string path, std::vector<std::string> &container);
    std::vector<std::string> getGraphPaths();
    std::vector<std::string> getGamePaths();

  private:
    Menu *menu;
    GState gameState_;
    std::unique_ptr<IGraphic> graphLib_;
    std::unique_ptr<IGame> gameLib_;
    DLLoader<IGraphic> graphLoader_ { DLLoader<IGraphic>() };
    DLLoader<IGame> gameLoader_ { DLLoader<IGame>() };
    std::vector<std::string> gamePaths_;
    std::vector<std::string> graphPaths_;
    std::size_t gameIndex_ {0};
    std::size_t graphIndex_ {0};
};

#endif /* !CORE_HPP_ */
