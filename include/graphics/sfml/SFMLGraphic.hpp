/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <unordered_map>

class SFMLGraphic : public IGraphic {
  public:
    SFMLGraphic() = default;
    ~SFMLGraphic() noexcept = default;
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
    void drawRectangle(const shape& shape);
    void drawCircle(const shape& shape);
    std::unordered_map<const shape*, sf::RectangleShape> rectList;
    std::unordered_map<const shape*, sf::CircleShape> circleList;
    sf::RenderWindow window_;
};

#endif /* !SFMLGRAPHIC_HPP_ */
