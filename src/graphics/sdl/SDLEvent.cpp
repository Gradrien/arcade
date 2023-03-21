/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLEvent
*/

#include "SDLEventKey.hpp"
#include "SDLGraphic.hpp"

eventKey SDLGraphic::getEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            return eventKey::Q;
        break;
    case SDL_KEYDOWN:
        if (keyEvent.find(event.key.keysym.sym) == keyEvent.end())
            return eventKey::NULL_EVENT;
        return keyEvent[event.key.keysym.sym];
        break;
    default:
        break;
    }
    return eventKey::NULL_EVENT;
}
