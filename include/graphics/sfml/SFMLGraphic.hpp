/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class SFMLGraphic : public IGraphic {
  public:
    SFMLGraphic() = default;
    ~SFMLGraphic() noexcept = default;
    void createWindow(std::string title, int width, int height) override;
    void displayWindow() override;
    void clearWindow() override;
    void destroyWindow() override;
    bool isOpenWindow() override;
    void displayText(const text& text) const override;
    void displayShape(const shape& shape) const override;
    void displaySprite(const sprite& sprite) const override;

    eventKey getEvent() const override;
  private:
    void drawRectangle(const shape& shape) const;
    sf::RenderWindow window_;
};

#endif /* !SFMLGRAPHIC_HPP_ */
