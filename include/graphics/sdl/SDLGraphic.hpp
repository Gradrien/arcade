/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLGraphic
*/

#ifndef SDLGRAPHIC_HPP_
#define SDLGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <unordered_map>

class SDLGraphic : public IGraphic {
  public:
    SDLGraphic() = default;
    ~SDLGraphic() noexcept = default;
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
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Surface* surface_;
    std::unordered_map<int, TTF_Font*> fonts_;
    void drawRectangle(const shape& shape);
    void drawCircle(const shape& shape);
    bool isOpen_ { false };
};

#endif /* !SFMLGRAPHIC_HPP_ */
