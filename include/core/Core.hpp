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

enum class GState { PLAY, PAUSE, MENU, QUIT, CONTINUE };

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
    void loadSpecificGraph(std::string path);
    void loadSpecificGame(std::string path);
    void loadNextGame();
    void restartGame();
    void quitArcade();
    void coreStateHandler();
    int findPathIndex(const std::string &path, const std::vector<std::string> &vec) const;
    GState getCoreState() const;
    void setCoreState(const GState& state);
    void pushLib(std::string path, std::vector<std::string> &container);
    std::vector<std::string> getGraphPaths();
    std::vector<std::string> getGamePaths();

  private:
    std::unique_ptr<Menu> menu_;
    GState gameState_;
    std::unique_ptr<IGraphic> graphLib_;
    std::unique_ptr<IGame> gameLib_;
    DLLoader<IGraphic> graphLoader_ { DLLoader<IGraphic>() };
    DLLoader<IGame> gameLoader_ { DLLoader<IGame>() };
    std::vector<std::string> gamePaths_;
    std::vector<std::string> graphPaths_;
    std::string currentGraph_;
    std::string currentGame_;
};

#endif /* !CORE_HPP_ */
