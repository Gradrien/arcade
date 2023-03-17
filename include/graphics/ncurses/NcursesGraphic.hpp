/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCURSESGraphic
*/

#ifndef NCURSESGRAPHIC_HPP_
#define NCURSESGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <memory>
#include <ncurses.h>

class NcursesGraphic : public IGraphic {
  public:
    NcursesGraphic() = default;
    ~NcursesGraphic() noexcept = default;
    void createWindow(std::string title, int width, int height) override;
    void displayWindow() override;
    void clearWindow() override;
    void destroyWindow() override;
    bool isOpenWindow() override;
    void displayText(const text& text) override;
    void displayShape(const shape& shape) override;
    void displaySprite(const sprite& sprite) override;
    eventKey getEvent() override;

  private:
    bool isOpen_ { false };
    WINDOW* window_;
    void drawRectangle(const shape& shape);
};

#endif /* !NCURSESGRAPHIC_HPP_ */
