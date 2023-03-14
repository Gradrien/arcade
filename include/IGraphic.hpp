/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_
#include <iostream>

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

enum class shapeType { RECTANGLE, CIRCLE, TRIANGLE };

struct coord {
    int x;
    int y;
};

struct elemSize {
    int width;
    int height;
};

struct texture {
    coord pos;
    elemSize size;
    const std::string& path;
};

struct color {
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};

struct sprite {
    coord pos;
    elemSize size;
    texture texture;
    char replacementChar;
    color color;
};

struct text {
    coord pos;
    int fontSize;
    std::string fontPath;
    color color;
    std::string text;
};

struct shape {
    coord pos;
    elemSize size;
    color color;
    char replacementChar;
    std::string text;
    shapeType type;
};

class IWindow {
    virtual void createWindow(std::string title, int width, int height) = 0;
    virtual void destroyWindow() = 0;
};

class IDrawable {
    virtual void displayText(const text& text) const = 0;
    virtual void displayShape(const shape& shape) const = 0;
    virtual void displaySprite(const sprite& sprite) const = 0;
    virtual text& createText() = 0;
    virtual shape& createShape() = 0;
    virtual sprite& createSprite() = 0;
};

class IGraphic {
  public:
    virtual ~IGraphic() = 0;
    virtual IWindow& getWindow() const = 0;
    virtual IDrawable& getDrawable() const = 0;
    virtual eventKey getEvent() const = 0;
};

#endif /* !IGRAPHIC_HPP_ */
