/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NcursesGraphic
*/

#include "NcursesGraphic.hpp"
#include <memory>
#include <ncurses.h>

void NcursesGraphic::createWindow(std::string title, int width, int height)
{
    (void)title;
    initscr();
    this->window_ = newwin(height / 20, width / 10, 0, 0);
    this->isOpen_ = true;
    keypad(this->window_, TRUE);
    noecho();
    curs_set(0);
    halfdelay(1);
    clear();
    refresh();
    if (has_colors() == FALSE) {
        endwin();
        //! exit(1); THROW ERROR
    }
    start_color();
    return;
}

void NcursesGraphic::displayWindow()
{
    wrefresh(this->window_);
}

void NcursesGraphic::clearWindow()
{
    werase(this->window_);
}

void NcursesGraphic::destroyWindow()
{
    endwin();
    this->isOpen_ = false;
}

bool NcursesGraphic::isOpenWindow()
{
    return this->isOpen_;
}

void NcursesGraphic::displayText(const text& text)
{
    (void)text;
}

void NcursesGraphic::drawRectangle(const shape& shape)
{
    char str[2] = { shape.replacementChar, 0 };
    for (int x = 0; x < shape.size.width / 10; x++) {
        for (int y = 0; y < shape.size.height / 20; y++) {
            mvwprintw(this->window_, (shape.pos.y / 20) + y, (shape.pos.x / 10) + x, str);
        }
    }
}

void NcursesGraphic::displayShape(const shape& shape)
{
    switch (shape.type) {
    case shapeType::RECTANGLE:
        this->drawRectangle(shape);
        break;
    case shapeType::CIRCLE:
        // this->drawCircle(shape);
        break;
    default:
        break;
    }
    return;
}

void NcursesGraphic::displaySprite(const sprite& sprite)
{
    (void)sprite;
    return;
}
