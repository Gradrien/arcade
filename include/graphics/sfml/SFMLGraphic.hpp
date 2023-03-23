/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

/****************************************************************
 * @file SFMLGraphic.hpp
 * @brief SFMLGraphic class
 * @details This class is used to handle the SFML graphic library
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <unordered_map>

/****************************************************************
 * @class SFMLGraphic
 * @brief SFMLGraphic class
 * @details This class is used to handle the SFML graphic library
 * *************************************************************/
class SFMLGraphic : public IGraphic {
  public:
    SFMLGraphic() = default;
    ~SFMLGraphic() noexcept = default;
    /****************************************************************
     * @brief Create the window
     * @param title
     * @param width
     * @param height
     * @details This function is used to create the window
     * **************************************************************/
    void createWindow(std::string title, int width, int height) override;
    /****************************************************************
     * @brief Display the window
     * @details This function is used to display the window
     * **************************************************************/
    void displayWindow() override;
    /****************************************************************
     * @brief Clear the window
     * @details This function is used to clear the window
     * **************************************************************/
    void clearWindow() override;
    /****************************************************************
     * @brief Destroy the window
     * @details This function is used to destroy the window
     * **************************************************************/
    void destroyWindow() override;
    /****************************************************************
     * @brief Check if the window is open
     * @details This function is used to check if the window is open
     * @return bool
     * **************************************************************/
    bool isOpenWindow() override;
    /****************************************************************
     * @brief Display a text
     * @param text
     * @details This function is used to display a text
     * **************************************************************/
    void displayText(const text& text) override;
    /****************************************************************
     * @brief Display a shape
     * @param shape
     * @details This function is used to display a shape
     * **************************************************************/
    void displayShape(const shape& shape) override;
    /****************************************************************
     * @brief Display a sprite
     * @param sprite
     * @details This function is used to display a sprite
     * **************************************************************/
    void displaySprite(const sprite& sprite) override;
    /****************************************************************
     * @brief get the event
     * @details This function is used to get the event
     * @return eventKey
     * **************************************************************/
    eventKey getEvent() override;

  private:
    /****************************************************************
     * @brief Draw a rectangle
     * @param shape
     * @details This function is used to draw a rectangle
     * **************************************************************/
    void drawRectangle(const shape& shape);
    /****************************************************************
     * @brief Draw a circle
     * @param shape
     * @details This function is used to draw a circle
     * **************************************************************/
    void drawCircle(const shape& shape);
    std::unordered_map<const text*, sf::Text> textList;
    std::unordered_map<const shape*, sf::RectangleShape> rectList;
    std::unordered_map<const shape*, sf::CircleShape> circleList;
    sf::RenderWindow window_;
};

#endif /* !SFMLGRAPHIC_HPP_ */
