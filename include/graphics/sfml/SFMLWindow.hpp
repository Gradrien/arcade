/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#ifndef SFMLWINDOW_HPP_
#define SFMLWINDOW_HPP_
#include "IGraphic.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class SFMLWindow : public IWindow {
  public:
    SFMLWindow() = default;
    ~SFMLWindow() noexcept = default;
    void createWindow(std::string title, int width, int height) override;
    void displayWindow() override;
    void clearWindow() override;
    void destroyWindow() override;
    bool isOpenWindow() override;

  private:
    sf::RenderWindow window;
};

#endif /* !SFMLWINDOW_HPP_ */
