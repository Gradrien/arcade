/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu
*/

/****************************************************************
 * @file Menu.hpp
 * @brief Menu class
 * @details This class is used to display the menu
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef MENU_HPP_
#define MENU_HPP_

#include "IGraphic.hpp"
#include "IGame.hpp"
#include "Core.hpp"
#include <string>
#include <vector>
#include <memory>
#include <chrono>

class Core;

/****************************************************************
 * @class Menu
 * @brief Menu class
 * @details This class is used to display the menu
 * ***************************************************************/
class Menu {
    public:
    /****************************************************************
     * @brief Construct a new Menu object
     * @param core
     * @details This function is used to construct the menu
     ****************************************************************/
    Menu(Core &core);
    ~Menu() = default;
    /****************************************************************
     * @brief Run the menu
     * @param graphLib
     * @param core
     * @details This function is used to run the menu
     * ************************************************/
    void menuLoopHandler(IGraphic &graphLib, Core &core);
    /****************************************************************
     * @brief Handle the event
     * @param evt
     * @param core
     * @details This function is used to handle the event
     * ************************************************/
    void handleEvent(eventKey evt, Core &core);
    /****************************************************************
     * @brief Set the Graph Lib Text object
     * @param graphPaths_
     * @details This function is used to set the graph lib text
     * ************************************************/
    void setGraphLibText(std::vector<std::string> graphPaths_);
    /****************************************************************
     * @brief Set the Game Lib Text object
     * @param gamePaths_
     * @details This function is used to set the game lib text
     * ************************************************/
    void setGameLibText(std::vector<std::string> gamePaths_);
    /****************************************************************
     * @brief Set the Gui Text object
     * @details This function is used to set the gui text
     * ************************************************/
    void createGuiTextMenu();
    /****************************************************************
     * @brief Set the Title Text object
     * @details This function is used to set the title text
     * ************************************************/
    void createTitleMenu();
    /****************************************************************
     * @brief Apply changes after a selection
     * @details This function is used to set the graphics and games libraries and set the game state
     * @param core
     * ************************************************/
    void applyChanges(Core &core);
    /****************************************************************
     * @brief Highlight the selected game
     * @details This function is used to highlight the selected game in green
     * ************************************************/
    void chooseGame();
    /****************************************************************
     * @brief Highlight the selected graphics library
     * @details This function is used to highlight the selected graphics library in green
     * ************************************************/
    void chooseLib();
    /****************************************************************
     * @brief Move in the menu
     * @details This function is used to move up in the menu
     * @param core
     * ************************************************/
    void moveUp(Core &core);
    /****************************************************************
     * @brief Move in the menu
     * @details This function is used to move down in the menu
     * @param core
     * ************************************************/
    void moveDown(Core &core);
    /****************************************************************
     * @brief Highlight the selected game and graphics library on first selection
     * @details This function is used to highlight the selected game and graphics library on first selection
     * @param core
     * ************************************************/
    void highlightSelected(Core &core);
    /****************************************************************
     * @brief Highlight the title
     * @details This function is used to highlight the title
     * @param count
     * ************************************************/
    void highlightTitle(const int count);
    /****************************************************************
     * @brief Loop the title to highlight it letter by letter
     * @details This function is used to loop the title to highlight it letter by letter
     * ************************************************/
    void loopTitle();

    private:
    std::vector<text> titleMenu_;
    std::vector<text> guiTextMenu_;
    std::vector<text> gameTextMenu_;
    std::vector<text> libTextMenu_;
    int incrLib_ {0};
    int incrGame_ {0};
    bool isGameSelected_ {false};
    int counter_ {0};
    std::chrono::steady_clock::time_point lastUpdateTime_;
};

#endif /* !MENU_HPP_ */
