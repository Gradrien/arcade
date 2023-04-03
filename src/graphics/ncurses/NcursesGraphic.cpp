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
    if (!initscr())
        throw std::runtime_error("Failed to create ncurses window");
    this->window_ = newwin(height / 20 + 2, width / 10 + 2, 0, 0);
    if (!this->window_)
        throw std::runtime_error("Failed to create ncurses window");
    this->isOpen_ = true;
    keypad(this->window_, TRUE);
    noecho();
    curs_set(0);
    nodelay(this->window_, TRUE);
    clear();
    refresh();
    wclear(this->window_);
    wrefresh(this->window_);
    if (has_colors() == FALSE) {
        delwin(this->window_);
        endwin();
        throw std::runtime_error("Failed to create ncurses window");
    }
    start_color();
    return;
}

void NcursesGraphic::displayWindow()
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    box(this->window_, ACS_VLINE, ACS_HLINE);
    if (this->window_)
        wrefresh(this->window_);
}

void NcursesGraphic::clearWindow()
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    werase(this->window_);
}

void NcursesGraphic::destroyWindow()
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    delwin(this->window_);
    endwin();
    this->window_ = nullptr;
    this->isOpen_ = false;
}

bool NcursesGraphic::isOpenWindow()
{
    return this->isOpen_;
}

void NcursesGraphic::displayText(const text& text)
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    int colorNb = (text.m_color.r + text.m_color.g + text.m_color.b) / 3;
    init_color(colorNb, (text.m_color.r * 1000 / 255), (text.m_color.g * 1000 / 255), (text.m_color.b * 1000 / 255));
    init_pair(colorNb, colorNb, COLOR_BLACK);
    wattron(this->window_, COLOR_PAIR(colorNb));
    mvwprintw(this->window_, (text.pos.y / 20) + 1, (text.pos.x / 10) + 1, text.text.c_str());
    wattroff(this->window_, COLOR_PAIR(colorNb));
}

void NcursesGraphic::drawRectangle(const shape& shape)
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    char str[2] = { shape.replacementChar, 0 };
    for (int x = 0; x < shape.size.width / 10; x++) {
        for (int y = 0; y < shape.size.height / 20; y++) {
            mvwprintw(this->window_, (shape.pos.y / 20) + y + 1, (shape.pos.x / 10) + x + 1, str);
        }
    }
}

void NcursesGraphic::displayShape(const shape& shape)
{
    if (!this->window_)
        throw std::runtime_error("Failed to get window");
    int colorNb = (shape.m_color.r + shape.m_color.g + shape.m_color.b) / 3;
    init_color(colorNb, shape.m_color.r * 1000 / 256, shape.m_color.g * 1000 / 256, shape.m_color.b * 1000 / 256);
    init_pair(colorNb, colorNb, colorNb);
    wattron(this->window_, COLOR_PAIR(colorNb));
    switch (shape.type) {
    case shapeType::RECTANGLE:
        this->drawRectangle(shape);
        break;
    case shapeType::CIRCLE:
        this->drawRectangle(shape);
        break;
    default:
        break;
    }
    wattroff(this->window_, COLOR_PAIR(colorNb));
    return;
}

void NcursesGraphic::displaySprite(const sprite& sprite)
{
    shape spriteShape;
    spriteShape.m_color = sprite.m_color;
    spriteShape.pos = sprite.pos;
    spriteShape.replacementChar = sprite.replacementChar;
    spriteShape.size = sprite.size;
    spriteShape.type = shapeType::RECTANGLE;
    this->drawRectangle(spriteShape);
    return;
}
