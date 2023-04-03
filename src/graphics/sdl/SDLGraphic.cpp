/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLGraphic
*/

#include <SDL2/SDL_image.h>
#include <SDLGraphic.hpp>
#include <memory>

void SDLGraphic::createWindow(std::string title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("SDL2 init failed");
    }
    if (TTF_Init() < 0) {
        throw std::runtime_error("Font init failed");
    }
    this->window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!this->window_)
        throw std::runtime_error("Failed to open window");
    this->renderer_ = SDL_CreateRenderer(this->window_, -1, 0);
    if (!this->renderer_)
        throw std::runtime_error("Failed to create renderer");
    this->isOpen_ = true;
    return;
}

void SDLGraphic::displayWindow()
{
    SDL_RenderPresent(this->renderer_);
    return;
}

void SDLGraphic::clearWindow()
{
    if (!this->renderer_)
        throw std::runtime_error("Failed to get renderer");
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
    if (!this->renderer_)
        throw std::runtime_error("Failed to get renderer");
    if (this->fonts_.find(text.fontSize) == this->fonts_.end()) {
        this->fonts_[text.fontSize] = TTF_OpenFont(text.fontPath.c_str(), text.fontSize);
        if (!this->fonts_[text.fontSize])
            throw std::runtime_error("Failed load font");
    }
    Uint8 r = text.m_color.r;
    Uint8 g = text.m_color.g;
    Uint8 b = text.m_color.b;
    Uint8 a = text.m_color.a;
    SDL_Color textColor = { r, g, b, a };
    SDL_Surface* surfaceText = TTF_RenderText_Solid(this->fonts_[text.fontSize], text.text.c_str(), textColor);
    if (!surfaceText)
        return;
    SDL_Texture* SDLtext = SDL_CreateTextureFromSurface(this->renderer_, surfaceText);
    if (!SDLtext)
        return;
    SDL_Rect textRect = { .x = text.pos.x, .y = text.pos.y, .w = text.size.width, .h = text.size.height };
    SDL_RenderCopy(this->renderer_, SDLtext, NULL, &textRect);
    SDL_FreeSurface(surfaceText);
    SDL_DestroyTexture(SDLtext);
    return;
}

void SDLGraphic::drawRectangle(const shape& shape)
{
    SDL_Rect rect;
    rect.x = shape.pos.x;
    rect.y = shape.pos.y;
    rect.w = shape.size.width;
    rect.h = shape.size.height;
    if (!this->renderer_)
        throw std::runtime_error("Failed to get renderer");
    SDL_SetRenderDrawColor(this->renderer_, shape.m_color.r, shape.m_color.g, shape.m_color.b, shape.m_color.a);
    SDL_RenderDrawRect(this->renderer_, &rect);
    SDL_RenderFillRect(this->renderer_, &rect);
    return;
}

void SDLGraphic::drawCircle(const shape& shape)
{
    if (!this->renderer_)
        throw std::runtime_error("Failed to get renderer");
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
    if (!this->renderer_)
        throw std::runtime_error("Failed to get renderer");
    if (!this->spriteSurface_ || !this->spriteTexture_ || sprite.m_texture.path != this->textPath_) {
        this->spriteSurface_ = IMG_Load(sprite.m_texture.path.c_str());
        if (this->spriteSurface_)
            this->spriteTexture_ = SDL_CreateTextureFromSurface(this->renderer_, this->spriteSurface_);
        this->textPath_ = sprite.m_texture.path;
    }
    if (!this->spriteSurface_ || !this->spriteTexture_)
        throw std::runtime_error("Failed to create sprite");
    SDL_Rect rect = { sprite.m_texture.pos.x, sprite.m_texture.pos.y, sprite.m_texture.size.width, sprite.m_texture.size.height };
    SDL_Rect pos = { sprite.pos.x, sprite.pos.y, sprite.size.width, sprite.size.height };
    SDL_RenderCopy(this->renderer_, this->spriteTexture_, &rect, &pos);
    return;
}
