/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLEventKey
*/

#ifndef SDLEVENTKEY_HPP_
#define SDLEVENTKEY_HPP_
#include "IGraphic.hpp"
#include <unordered_map>
#include <SDL2/SDL.h>

std::unordered_map<char, eventKey> keyEvent = { { 'a', eventKey::A },
    { 'b', eventKey::B }, { 'c', eventKey::C }, { 'd', eventKey::D },
    { 'e', eventKey::E }, { 'f', eventKey::F }, { 'g', eventKey::G },
    { 'h', eventKey::H }, { 'i', eventKey::I }, { 'j', eventKey::J },
    { 'k', eventKey::K }, { 'l', eventKey::L }, { 'm', eventKey::M },
    { 'n', eventKey::N }, { 'o', eventKey::O }, { 'p', eventKey::P },
    { 'q', eventKey::Q }, { 'r', eventKey::R }, { 's', eventKey::S },
    { 't', eventKey::T }, { 'u', eventKey::U }, { 'v', eventKey::V },
    { 'w', eventKey::W }, { 'x', eventKey::X }, { 'y', eventKey::Y },
    { 'z', eventKey::Z }, { SDLK_SPACE, eventKey::SPACE },
    { SDLK_ESCAPE, eventKey::ESCAPE }, { SDLK_RETURN, eventKey::ENTER },
    { SDLK_LEFT, eventKey::LARROW }, { SDLK_RIGHT, eventKey::RARROW },
    { SDLK_DOWN, eventKey::BARROW }, { SDLK_UP, eventKey::UARROW },
    { SDLK_BACKSPACE, eventKey::DELETE }, { SDLK_DELETE, eventKey::SUPR },
    { SDLK_KP_TAB, eventKey::TAB }, { SDLK_1, eventKey::ONE },
    {SDLK_2, eventKey::TWO }, {SDLK_3, eventKey::THREE },
    {SDLK_4, eventKey::FOUR }, {SDLK_5, eventKey::FIVE },
    {SDLK_6, eventKey::SIX }, {SDLK_7, eventKey::SEVEN },
    {SDLK_8, eventKey::EIGHT }, {SDLK_9, eventKey::NINE },
    {SDLK_0, eventKey::ZERO }, { SDLK_LCTRL, eventKey::CTRL },
    { SDLK_LALT, eventKey::ALT }, { SDLK_LSHIFT, eventKey::SHIFT } };

#endif /* !SDLEVENTKEY_HPP_ */
