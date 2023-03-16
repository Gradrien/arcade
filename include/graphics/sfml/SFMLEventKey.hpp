/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEventKey
*/

#ifndef SFMLEVENTKEY_HPP_
#define SFMLEVENTKEY_HPP_
#include "IGraphic.hpp"
#include <SFML/Window/Event.hpp>
#include <unordered_map>

std::unordered_map<sf::Keyboard::Key, eventKey> keyEvent = { { sf::Keyboard::Key::A, eventKey::A },
    { sf::Keyboard::Key::B, eventKey::B }, { sf::Keyboard::Key::C, eventKey::C }, { sf::Keyboard::Key::D, eventKey::D },
    { sf::Keyboard::Key::E, eventKey::E }, { sf::Keyboard::Key::F, eventKey::F }, { sf::Keyboard::Key::G, eventKey::G },
    { sf::Keyboard::Key::H, eventKey::H }, { sf::Keyboard::Key::I, eventKey::I }, { sf::Keyboard::Key::J, eventKey::J },
    { sf::Keyboard::Key::K, eventKey::K }, { sf::Keyboard::Key::L, eventKey::L }, { sf::Keyboard::Key::M, eventKey::M },
    { sf::Keyboard::Key::N, eventKey::N }, { sf::Keyboard::Key::O, eventKey::O }, { sf::Keyboard::Key::P, eventKey::P },
    { sf::Keyboard::Key::Q, eventKey::Q }, { sf::Keyboard::Key::R, eventKey::R }, { sf::Keyboard::Key::S, eventKey::S },
    { sf::Keyboard::Key::T, eventKey::T }, { sf::Keyboard::Key::U, eventKey::U }, { sf::Keyboard::Key::V, eventKey::V },
    { sf::Keyboard::Key::W, eventKey::W }, { sf::Keyboard::Key::X, eventKey::X }, { sf::Keyboard::Key::Y, eventKey::Y },
    { sf::Keyboard::Key::Z, eventKey::Z }, { sf::Keyboard::Key::Space, eventKey::SPACE },
    { sf::Keyboard::Key::Escape, eventKey::ESCAPE }, { sf::Keyboard::Key::Enter, eventKey::ENTER },
    { sf::Keyboard::Key::Left, eventKey::LARROW }, { sf::Keyboard::Key::Right, eventKey::RARROW },
    { sf::Keyboard::Key::Down, eventKey::BARROW }, { sf::Keyboard::Key::Up, eventKey::UARROW },
    { sf::Keyboard::Key::BackSpace, eventKey::DELETE }, { sf::Keyboard::Key::Delete, eventKey::SUPR },
    { sf::Keyboard::Key::Tab, eventKey::TAB }, { sf::Keyboard::Key::Num1, eventKey::ONE },
    { sf::Keyboard::Key::Num2, eventKey::TWO }, { sf::Keyboard::Key::Num3, eventKey::THREE },
    { sf::Keyboard::Key::Num4, eventKey::FOUR }, { sf::Keyboard::Key::Num5, eventKey::FIVE },
    { sf::Keyboard::Key::Num6, eventKey::SIX }, { sf::Keyboard::Key::Num7, eventKey::SEVEN },
    { sf::Keyboard::Key::Num8, eventKey::EIGHT }, { sf::Keyboard::Key::Num9, eventKey::NINE },
    { sf::Keyboard::Key::Num0, eventKey::ZERO }, { sf::Keyboard::Key::LControl, eventKey::CTRL },
    { sf::Keyboard::Key::LAlt, eventKey::ALT }, { sf::Keyboard::Key::LShift, eventKey::SHIFT } };

#endif /* !SFMLEVENTKEY_HPP_ */
