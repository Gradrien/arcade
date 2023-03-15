/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLDrawable
*/

#ifndef SFMLDRAWABLE_HPP_
#define SFMLDRAWABLE_HPP_
#include "IGraphic.hpp"

class SFMLDrawable : public IDrawable {
  public:
    SFMLDrawable() = default;
    ~SFMLDrawable() noexcept = default;
    void displayText(const text& text) const override;
    void displayShape(const shape& shape) const override;
    void displaySprite(const sprite& sprite) const override;
    // text& createText() override; //Problème de stack ?
    // shape& createShape() override;
    // sprite& createSprite() override;
};

#endif /* !SFMLDRAWABLE_HPP_ */
