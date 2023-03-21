/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLGraphic
*/

#include "SDLGraphic.hpp"
#include <SDL2/SDL.h>
#include <memory>

void SDLGraphic::createWindow(std::string title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        //! ERROR
        exit(84);
    }
    this->window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!this->window_) {
        //! THROW ERROR
        exit(84);
    }
    this->renderer_ = SDL_CreateRenderer(this->window_, -1, 0);
    this->isOpen_ = true;
    this->surface_ = SDL_GetWindowSurface(this->window_);
    return;
}

void SDLGraphic::displayWindow()
{
    SDL_RenderPresent(this->renderer_);
    return;
}

void SDLGraphic::clearWindow()
{
    if (!this->renderer_) {
        //! THROW ERROR
    }
    SDL_SetRenderDrawColor(this->renderer_, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer_);
    return;
}

void SDLGraphic::destroyWindow()
{
    this->isOpen_ = false;
    if (this->renderer_)
        SDL_DestroyRenderer(this->renderer_);
    if (this->window_)
        SDL_DestroyWindow(this->window_);
    this->window_ = NULL;
}

bool SDLGraphic::isOpenWindow()
{
    return this->isOpen_;
}

void SDLGraphic::displayText(const text& text)
{
    (void)text;
    // TTF_Font* Sans = TTF_OpenFont(m_text.fontPath.c_str(), m_text.fontSize);

    // SDL_Color textColor = {m_text.m_color.r, m_text.m_color.g, m_text.m_color.b, m_text.m_color.b};

    // SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, m_text.text.c_str(), textColor);

    // SDL_Texture* Message = SDL_CreateTextureFromSurface(this->renderer_, surfaceMessage);

    // SDL_Rect Message_rect; // create a rect
    // Message_rect.x = m_text.pos.x; // controls the rect's x coordinate
    // Message_rect.y = m_text.pos.y; // controls the rect's y coordinte
    // Message_rect.w = 500; // controls the width of the rect
    // Message_rect.h = 100; // controls the height of the rect
    // SDL_RenderCopy(this->renderer_, Message, NULL, &Message_rect);

    // // Don't forget to free your surface and texture
    // SDL_FreeSurface(surfaceMessage);
    // SDL_DestroyTexture(Message);
    // return;
}

void SDLGraphic::drawRectangle(const shape& shape)
{
    // (void)shape;
    SDL_Rect rect;
    rect.x = shape.pos.x;
    rect.y = shape.pos.y;
    rect.w = shape.size.width;
    rect.h = shape.size.height;
    if (!this->renderer_) {
        //! THROW ERROR
    }
    SDL_SetRenderDrawColor(this->renderer_, shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a);
    SDL_RenderDrawRect(this->renderer_, &rect);
    SDL_RenderFillRect(this->renderer_, &rect);
    return;
}

void SDLGraphic::drawCircle(const shape& shape)
{
    // (void)shape;
    SDL_SetRenderDrawColor(this->renderer_, shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a);
    int radius = shape.size.width / 2;
    for (int width = 0; width < radius * 2; width++) {
        for (int height = 0; height < radius * 2; height++) {
            int distX = radius - width;
            int distY = radius - height;
            if ((distX * distX + distY * distY) <= (radius * radius)) {
                SDL_RenderDrawPoint(this->renderer_, shape.pos.x + distX + radius, shape.pos.y + distY + radius);
            }
        }
    }
}

void SDLGraphic::displayShape(const shape& shape)
{
    switch (shape.type) {
    case shapeType::RECTANGLE:
        this->drawRectangle(shape);
        break;
    case shapeType::CIRCLE:
        this->drawCircle(shape);
        break;
    default:
        break;
    }
    return;
}

void SDLGraphic::displaySprite(const sprite& sprite)
{
    (void)sprite;
    return;
}
