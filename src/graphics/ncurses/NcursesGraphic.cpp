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
    this->window_ = newwin(height / 20 + 2, width / 10 + 2, 0, 0);
    if (!this->window_) {
        exit(84);
        //! THROW ERROR
    }
    this->isOpen_ = true;
    keypad(this->window_, TRUE);
    noecho();
    curs_set(0);
    halfdelay(1);
    clear();
    refresh();
    wclear(this->window_);
    wrefresh(this->window_);
    if (has_colors() == FALSE) {
        endwin();
        //! exit(1); THROW ERROR
    }
    start_color();
    return;
}

void NcursesGraphic::displayWindow()
{
    box(this->window_, ACS_VLINE, ACS_HLINE);
    if (this->window_)
        wrefresh(this->window_);
}

void NcursesGraphic::clearWindow()
{
    if (this->window_)
        werase(this->window_);
}

void NcursesGraphic::destroyWindow()
{
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
    int colorNb = (text.m_color.r + text.m_color.g + text.m_color.b) / 3;
    init_color(colorNb, (text.m_color.r * 1000 / 255), (text.m_color.g * 1000 / 255), (text.m_color.b * 1000 / 255));
    init_pair(colorNb, colorNb, COLOR_BLACK);
    wattron(this->window_, COLOR_PAIR(colorNb));
    mvwprintw(this->window_, (text.pos.y / 20) + 1, (text.pos.x / 10) + 1, text.text.c_str());
    wattroff(this->window_, COLOR_PAIR(colorNb));
}

void NcursesGraphic::drawRectangle(const shape& shape)
{
    char str[2] = { shape.replacementChar, 0 };
    for (int x = 0; x < shape.size.width / 10; x++) {
        for (int y = 0; y < shape.size.height / 20; y++) {
            mvwprintw(this->window_, (shape.pos.y / 20) + y + 1, (shape.pos.x / 10) + x + 1, str);
        }
    }
}

void NcursesGraphic::displayShape(const shape& shape)
{
    int colorNb = (shape.m_color.r + shape.m_color.g + shape.m_color.b) / 3;
    init_color(colorNb, shape.m_color.r * 1000 / 256, shape.m_color.g * 1000 / 256, shape.m_color.b * 1000 / 256);
    init_pair(colorNb, colorNb, COLOR_BLACK);
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
    (void)sprite;
    return;
}
