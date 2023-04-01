/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

/****************************************************************************
 * @file Core.hpp
 * @brief Core class
 * @version 0.1
 * @date 2021-03-15
 ***************************************************************************/
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

/********************************************************
 * @brief Enum for game state
 * This enum is used to get the current state of the game
 * @param PLAY
 * @param PAUSE
 * @param MENU
 * @param QUIT
 * @param CONTINUE
 * *****************************************************/
enum class GState { PLAY, PAUSE, MENU, QUIT, CONTINUE };

/********************************************************
 * @brief Enum for library type
 * This enum is used to get the type of the library
 * @param GRAPHICAL
 * @param GAME
 * *****************************************************/
enum class libType { GRAPHICAL, GAME };

/********************************************************
 * @brief Map for valid libraries
 * This map is used to get the type of the library
 * The type can be GRAPHICAL or GAME
 * *****************************************************/
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
  {"test_game.so", libType::GAME},
  {"arcade_pacman.so", libType::GAME},
  {"arcade_qix.so", libType::GAME},
  {"arcade_centipede.so", libType::GAME},
  {"arcade_solarfox.so", libType::GAME}
};

class Menu;
/********************************************************
 * @brief Core class
 * This class is used to handle the game loop and interact with the game and graphical libraries
 * *****************************************************/
class Core {
  public:
    /********************************************************
     * @brief Core constructor
     * This constructor is used to initialize the core
     * @param libName
     * *****************************************************/
    Core(const char* libName);
    ~Core() = default;
    /********************************************************
     * @brief Get all the libraries
     * This function is used to get all the libraries in the lib folder
     * @return void
     * *****************************************************/
    void getAllLib();
    /********************************************************
     * @brief Check if the library is graphical
     * This function is used to check if the library is graphical before loading it
     * @param libName
     * @return void
     * *****************************************************/
    void isLibGraphical(std::string libName);
    /********************************************************
     * @brief Handle the event and user input
     * This function is used to handle the event
     * @return void
     * *****************************************************/
    void handleEvent();
    /********************************************************
     * @brief Handle the game loop
     * This function is used to handle the game loop
     * and will call the display function of the graphical library
     * @return void
     * *****************************************************/
    void gameLoopHandler();
    /********************************************************
     * @brief Load the next graphical library
     * This function is used to load the next graphical library
     * @return void
     * *****************************************************/
    void loadNextGraph();
    /********************************************************
     * @brief Load a specific graphical library
     * This function is used to load a specific graphical library
     * @param path
     * @return void
     * *****************************************************/
    void loadSpecificGraph(std::string path);
    /********************************************************
     * @brief Load a specific game library
     * This function is used to load a specific game library
     * @param path
     * @return void
     * *****************************************************/
    void loadSpecificGame(std::string path);
    /********************************************************
     * @brief Load the next game library
     * This function is used to load the next game library
     * @return void
     * *****************************************************/
    void loadNextGame();
    /********************************************************
     * @brief Restart the game
     * This function is used to restart the game
     * @return void
     * *****************************************************/
    void restartGame();
    /********************************************************
     * @brief Quit the arcade
     * This function is used to quit the arcade
     * @return void
     * *****************************************************/
    void quitArcade();
    /********************************************************
     * @brief Handle the core state
     * This function is used to handle the core state
     * and redirect eihther to the menu or to the game loop
     * @return void
     * *****************************************************/
    void coreStateHandler();
    /********************************************************
     * @brief Find the index of a path in a vector
     * This function is used to find the index of a path in a vector
     * @param path
     * @param vec
     * @return int
     * *****************************************************/
    int findPathIndex(const std::string& path, const std::vector<std::string>& vec) const;
    /********************************************************
     * @brief Get the core state
     * This function is used to get the core state
     * @return GState
     * *****************************************************/
    GState getCoreState() const;
    /********************************************************
     * @brief Set the core state
     * This function is used to set the core state
     * @param state
     * @return void
     * *****************************************************/
    void setCoreState(const GState& state);
    /********************************************************
     * @brief Push a library path in a vector
     * This function is used to push a library path in a vector
     * @param path
     * @param container
     * @return void
     * *****************************************************/
    void pushLib(std::string path, std::vector<std::string>& container);
    /********************************************************
     * @brief Get the graphical paths
     * This function is used to get the graphical paths
     * @return std::vector<std::string>
     * *****************************************************/
    std::vector<std::string> getGraphPaths();
    /********************************************************
     * @brief Get the game paths
     * This function is used to get the game paths
     * @return std::vector<std::string>
     * *****************************************************/
    std::vector<std::string> getGamePaths();
    /********************************************************
     * @brief Get the current graphical library
     * This function is used to get the current graphical library
     * @return std::string
     * *****************************************************/
    std::string getCurrentGraph() const;
    /********************************************************
     * @brief Get the current game library
     * This function is used to get the current game library
     * @return std::string
     * *****************************************************/
    std::string getCurrentGame() const;
    /********************************************************
     * @brief Set the current graphical library
     * This function is used to set the current graphical library
     * @param currentGraph
     * @return void
     * *****************************************************/
    void setCurrentGraph(const std::string& currentGraph);
    /********************************************************
     * @brief Set the current game library
     * This function is used to set the current game library
     * @param currentGame
     * @return void
     * *****************************************************/
    void setCurrentGame(const std::string& currentGame);

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
