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
#include <filesystem>
#include <memory>
#include <unordered_map>

enum class GState { PLAY, PAUSE, MENU, QUIT, CONTINUE };

enum class libType { GRAPHICAL, GAME };

static const std::unordered_map<std::string, libType> validLibs {
  {"arcade_ncurses.so", libType::GRAPHICAL},
  {"arcade_sdl2.so", libType::GRAPHICAL},
  {"arcade_ndk++.so", libType::GRAPHICAL},
  {"arcade_aalib.so", libType::GRAPHICAL},
  {"arcade_libcaca.so", libType::GRAPHICAL},
  {"arcade_allegro5.so", libType::GRAPHICAL},
  {"arcade_xlib.so", libType::GRAPHICAL},
  {"arcade_gtk+.so", libType::GRAPHICAL},
  {"arcade_sfml.so", libType::GRAPHICAL},
  {"arcade_irrlicht.so", libType::GRAPHICAL},
  {"arcade_opengl.so", libType::GRAPHICAL},
  {"arcade_vulkan.so", libType::GRAPHICAL},
  {"arcade_qt5.so", libType::GRAPHICAL},
  {"arcade_snake.so", libType::GAME},
  {"arcade_nibbler.so", libType::GAME},
  {"arcade_pacman.so", libType::GAME},
  {"arcade_qix.so", libType::GAME},
  {"arcade_centipede.so", libType::GAME},
  {"arcade_solarfox.so", libType::GAME}
};

class Menu;
class Core {
  public:
    Core(const char* libName);
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
    int findPathIndex(const std::string& path, const std::vector<std::string>& vec) const;
    GState getCoreState() const;
    void setCoreState(const GState& state);
    void pushLib(std::string path, std::vector<std::string>& container);
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
