/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_
#include "iostream"

enum shapeType {
    RECTANGLE,
    CIRCLE,
    TRIANGLE
};

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct elemSize_s {
    int width;
    int height;
} elemSize_t;

typedef struct texture_s {
    int x;
    int y;
    int width;
    int height;
    std::string path;
} texture_t;

typedef struct color_s {
    int r;
    int g;
    int b;
} color_t;

typedef struct sprite_s {
    coord_t pos;
    elemSize_t size;
    texture_t texture;
    char replacementChar;
    color_t color;
} sprite_t;

typedef struct text_s {
    coord_t pos;
    int fontSize;
    std::string fontPath;
    color_t color;
    std::string text;
} text_t;

typedef struct shape_s {
    coord_t pos;
    elemSize_t size;
    color_t color;
    char replacementChar;
    std::string text;
    shapeType type;
} shape_t;

class IGraphic {
  public:
    virtual ~IGraphic() = 0;
    virtual void createWindow(std::string title, int width, int height) = 0;
    virtual void destroyWindow() = 0;
    virtual void displayText(text_t &text) const = 0;
    virtual void displayShape(shape_t &shape) const = 0;
    virtual void displaySprite(sprite_t &sprite) const = 0;
    virtual char getEvent() const = 0;
};

#endif /* !IGRAPHIC_HPP_ */
