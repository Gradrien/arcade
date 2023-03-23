/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCURSESGraphic
*/

/****************************************************************
 * @file NcursesGraphic.hpp
 * @brief NcursesGraphic class
 * @details This class is used to handle the NcursesGraphic
 * @version 0.1
 * @date 2021-03-15
 * *************************************************************/
#ifndef NCURSESGRAPHIC_HPP_
#define NCURSESGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <memory>
#include <ncurses.h>

/****************************************************************
 * @class NcursesGraphic
 * @brief NcursesGraphic class
 * @details This class is used to handle the NcursesGraphic
 * ***************************************************************/
class NcursesGraphic : public IGraphic {
  public:
    NcursesGraphic() = default;
    ~NcursesGraphic() noexcept = default;
    /****************************************************************
     * @brief Create the window
     * @param title
     * @param width
     * @param height
     * @details This function is used to create the window
     * **********************************************************/
    void createWindow(std::string title, int width, int height) override;
    /****************************************************************
     * @brief Display the window
     * @details This function is used to display the window
     * **********************************************************/
    void displayWindow() override;
    /****************************************************************
     * @brief Clear the window
     * @details This function is used to clear the window
     * **********************************************************/
    void clearWindow() override;
    /****************************************************************
     * @brief Destroy the window
     * @details This function is used to destroy the window
     * **********************************************************/
    void destroyWindow() override;
    /****************************************************************
     * @brief Check if the window is open
     * @details This function is used to check if the window is open
     * @return bool
     * **********************************************************/
    bool isOpenWindow() override;
    /****************************************************************
     * @brief Display the text
     * @param text
     * @details This function is used to display the text
     * **********************************************************/
    void displayText(const text& text) override;
    /****************************************************************
     * @brief Display the shape
     * @param shape
     * @details This function is used to display the shape
     * **********************************************************/
    void displayShape(const shape& shape) override;
    /****************************************************************
     * @brief Display the sprite
     * @param sprite
     * @details This function is used to display the sprite
     * **********************************************************/
    void displaySprite(const sprite& sprite) override;
    /****************************************************************
     * @brief Get the event
     * @details This function is used to get the event
     * @return eventKey
     * **********************************************************/
    eventKey getEvent() override;

  private:
    bool isOpen_ { false };
    WINDOW* window_;
    /****************************************************************
     * @brief Draw a rectangle
     * @param shape
     * @details This function is used to draw a rectangle
     * **********************************************************/
    void drawRectangle(const shape& shape);
};

#endif /* !NCURSESGRAPHIC_HPP_ */
