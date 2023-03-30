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
#include <unordered_map>

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
    Menu();
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
     * @details This function is used to set the graph lib text
     * ************************************************/
    void setGraphLibText();
    /****************************************************************
     * @brief Set the Game Lib Text object
     * @details This function is used to set the game lib text
     * ************************************************/
    void setGameLibText();
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
    /****************************************************************
     * @brief Handle the user input
     * @details This function is used to handle the user input
     * @param evt
     * @param core
     * ************************************************/
    void handleUserInput(eventKey evt, Core &core);
    /****************************************************************
     * @brief Tell if the user is typing
     * @details This function is used to tell if the user is typing and returns a boolean
     * @return true if the user is typing else returns false
     * @param name
     * ************************************************/
    bool isUserTyping() const;
    /****************************************************************
     * @brief Get the User Name object
     * @details This function is used to get the user name
     * @return std::string
     * ************************************************/
    std::string getUserName() const;

    private:
    void setLibNameMenu();
    void createNewUser();
    void deleteChar();
    std::vector<std::string> graphPaths_;
    std::vector<std::string> gamePaths_;
    std::vector<text> titleMenu_;
    std::vector<text> guiTextMenu_;
    std::vector<text> gameTextMenu_;
    std::vector<text> libTextMenu_;
    text userName_;
    int incrLib_ {0};
    int incrGame_ {0};
    bool isGameSelected_ {false};
    bool isUserTyping_ {true};
    int counter_ {0};
    std::chrono::steady_clock::time_point lastUpdateTime_;
    std::unordered_map<eventKey, char> keyMap_ = {
        {eventKey::A, 'a'},
        {eventKey::B, 'b'},
        {eventKey::C, 'c'},
        {eventKey::D, 'd'},
        {eventKey::E, 'e'},
        {eventKey::F, 'f'},
        {eventKey::G, 'g'},
        {eventKey::H, 'h'},
        {eventKey::I, 'i'},
        {eventKey::J, 'j'},
        {eventKey::K, 'k'},
        {eventKey::L, 'l'},
        {eventKey::M, 'm'},
        {eventKey::N, 'n'},
        {eventKey::O, 'o'},
        {eventKey::P, 'p'},
        {eventKey::Q, 'q'},
        {eventKey::R, 'r'},
        {eventKey::S, 's'},
        {eventKey::T, 't'},
        {eventKey::U, 'u'},
        {eventKey::V, 'v'},
        {eventKey::W, 'w'},
        {eventKey::X, 'x'},
        {eventKey::Y, 'y'},
        {eventKey::Z, 'z'},
        {eventKey::ZERO, '0'},
        {eventKey::ONE, '1'},
        {eventKey::TWO, '2'},
        {eventKey::THREE, '3'},
        {eventKey::FOUR, '4'},
        {eventKey::FIVE, '5'},
        {eventKey::SIX, '6'},
        {eventKey::SEVEN, '7'},
        {eventKey::EIGHT, '8'},
        {eventKey::NINE, '9'},
        {eventKey::SPACE, ' '}
    };
};

#endif /* !MENU_HPP_ */
