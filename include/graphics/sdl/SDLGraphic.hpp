/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLGraphic
*/

/****************************************************************
 * @file SDLGraphic.hpp
 * @brief SDLGraphic class
 * @details This class is used to handle the SDL graphic library
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef SDLGRAPHIC_HPP_
#define SDLGRAPHIC_HPP_
#include "IGraphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <unordered_map>

/****************************************************************
 * @class SDLGraphic
 * @brief SDLGraphic class
 * @details This class is used to handle the SDL graphic library
 * ***************************************************************/
class SDLGraphic : public IGraphic {
  public:
    SDLGraphic() = default;
    ~SDLGraphic() noexcept = default;
    /****************************************************************
     * @brief Create the window
     * @param title
     * @param width
     * @param height
     * @details This function is used to create the window
     * **************************************************************/
    void createWindow(std::string title, int width, int height) override;
    /****************************************************************
     * @brief Display the window
     * @details This function is used to display the window
     * **************************************************************/
    void displayWindow() override;
    /****************************************************************
     * @brief Clear the window
     * @details This function is used to clear the window
     * **************************************************************/
    void clearWindow() override;
    /****************************************************************
     * @brief Destroy the window
     * @details This function is used to destroy the window
     * **************************************************************/
    void destroyWindow() override;
    /****************************************************************
     * @brief Check if the window is open
     * @details This function is used to check if the window is open
     * @return bool
     * **************************************************************/
    bool isOpenWindow() override;
    /****************************************************************
     * @brief Display the text
     * @param text
     * @details This function is used to display the text
     * **************************************************************/
    void displayText(const text& text) override;
    /****************************************************************
     * @brief Display the shape
     * @param shape
     * @details This function is used to display the shape
     * **************************************************************/
    void displayShape(const shape& shape) override;
    /****************************************************************
     * @brief Display the sprite
     * @param sprite
     * @details This function is used to display the sprite
     * **************************************************************/
    void displaySprite(const sprite& sprite) override;
    /****************************************************************
     * @brief get the event
     * @details This function is used to get the event
     * @return eventKey
     * **************************************************************/
    eventKey getEvent() override;

  private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Surface* surface_;
    std::unordered_map<int, TTF_Font*> fonts_;
    /****************************************************************
     * @brief Draw a rectangle
     * @param shape
     * @details This function is used to draw a rectangle
     * **************************************************************/
    void drawRectangle(const shape& shape);
    /****************************************************************
     * @brief Draw a circle
     * @param shape
     * @details This function is used to draw a circle
     * **************************************************************/
    void drawCircle(const shape& shape);
    bool isOpen_ { false };
    SDL_Surface* spriteSurface_ { NULL };
    SDL_Texture* spriteTexture_ { NULL };
    std::string textPath_;
};

#endif /* !SFMLGRAPHIC_HPP_ */
