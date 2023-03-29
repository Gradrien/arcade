/*
 ** EPITECH PROJECT, 2023
 ** arcade
 ** File description:
 ** IGraphic
 */

/****************************************************************************
 * @file IGraphic.hpp
 * @brief Interface for graphic library
 * @version 0.1
 * @date 2021-03-15
 ***************************************************************************/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_
#include <iostream>
#include <memory>

/****************************
 * @brief Enum for event key
 * This enum is used to get the key pressed
 * *************************/
enum class eventKey {
    NULL_EVENT,
    A,
    Z,
    E,
    R,
    T,
    Y,
    U,
    I,
    O,
    P,
    Q,
    S,
    D,
    F,
    G,
    H,
    J,
    K,
    L,
    M,
    W,
    X,
    C,
    V,
    B,
    N,
    SPACE,
    ESCAPE,
    ENTER,
    LARROW,
    RARROW,
    BARROW,
    UARROW,
    DELETE,
    SUPR,
    TAB,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    ZERO,
    CTRL,
    ALT,
    SHIFT
};

/****************************
 * @brief Enum for shape type
 * This enum is used to store the type of shape
 * @param RECTANGLE
 * @param CIRCLE
 * @param TRIANGLE
 * *************************/
enum class shapeType { RECTANGLE,
    CIRCLE,
    TRIANGLE };

/****************************
 * @brief Struct for coord
 * This struct is used to store x and y position of an element
 * It contains a x and a y
 * *************************/
struct coord {
    int x;
    int y;
};

/****************************
 * @brief Struct for element size
 * This struct is used to store width and height of an element
 * It contains a width and a height
 * *************************/
struct elemSize {
    int width;
    int height;
};

/****************************
 * @brief Struct for texture
 * This struct is used to store texture and its position as well as its size
 * *************************/
struct texture {
    coord pos;
    elemSize size;
    const std::string& path;
};

/****************************
 * @brief Struct for color
 * This struct is used to store color of an element
 * It contains a r, g, b and a
 * *************************/
struct color {
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};

/****************************
 * @brief Struct for sprite
 * This struct is used to store sprite, position, size and color of an element
 * and a replacement char for non-graphical interfaces
 * *************************/
struct sprite {
    coord pos;
    elemSize size;
    texture m_texture;
    char replacementChar;
    color m_color;
};

/****************************
 * @brief Struct for text
 * This struct is used to store text, position, size, font size, font path and
 * color of an element
 * *************************/
struct text {
    coord pos;
    elemSize size;
    int fontSize;
    std::string fontPath;
    color m_color;
    std::string text;
};

/****************************
 * @brief Struct for shape
 * This struct is used to store position, size, color, text, type of an element
 * and a replacement char for non-graphical interfaces
 * *************************/
struct shape {
    coord pos;
    elemSize size;
    color m_color;
    char replacementChar;
    std::string text;
    shapeType type;
};

/****************************
 * @brief Interface for graphic library
 * This interface is used to create a graphic library
 * *************************/
class IGraphic {
  public:
    virtual ~IGraphic() noexcept = default;
    /*********************************************
     * @brief This method is used to display text
     * @param text
     * @return void
     * */
    virtual void displayText(const text& text) = 0;
    /*********************************************
     * @brief This method is used to display shape
     * @param shape
     * @return void
     * */
    virtual void displayShape(const shape& shape) = 0;
    /*********************************************
     * @brief This method is used to display sprite
     * @param sprite
     * @return void
     * */
    virtual void displaySprite(const sprite& sprite) = 0;

    /*********************************************
     * @brief This method is used to create a window
     * @param title
     * @param width
     * @param height
     * @return void
     * */
    virtual void createWindow(std::string title, int width, int height) = 0; // Ajouter dans le constructeur
    /*********************************************
     * @brief This method is used to display window
     * @return void
     * */
    virtual void displayWindow() = 0;
    /*********************************************
     * @brief This method is used to clear window
     * @return void
     * */
    virtual void clearWindow() = 0;
    /*********************************************
     * @brief This method is used to destroy window
     * @return void
     * */
    virtual void destroyWindow() = 0;
    /*********************************************
     * @brief This method is used to check if window is open
     * @return bool
     * */
    virtual bool isOpenWindow() = 0;
    /*********************************************
     * @brief This method is used to get event
     * @return eventKey
     * */
    virtual eventKey getEvent() = 0;
};

#endif /* !IGRAPHIC_HPP_ */
