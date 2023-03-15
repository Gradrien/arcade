/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLGraphic
*/

#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_
#include "SFMLDrawable.hpp"
#include "SFMLWindow.hpp"
#include <memory>

class SFMLGraphic : public IGraphic {
  public:
    SFMLGraphic() = default;
    ~SFMLGraphic() noexcept = default;
    const std::unique_ptr<IWindow>& getWindow() const override;
    const std::unique_ptr<IDrawable>& getDrawable() const override;
    eventKey getEvent() const override;
  private:
    const std::unique_ptr<IWindow> window = std::make_unique<SFMLWindow>();
    const std::unique_ptr<IDrawable> drawables = std::make_unique<SFMLDrawable>();
};

#endif /* !SFMLGRAPHIC_HPP_ */
