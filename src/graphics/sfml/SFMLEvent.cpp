/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEvent
*/

#include "SFMLEventKey.hpp"
#include "SFMLGraphic.hpp"

eventKey SFMLGraphic::getEvent()
{
    sf::Event event;
    if (!this->window_.pollEvent(event))
        return eventKey::NULL_EVENT;
    if (event.type == sf::Event::Closed)
        return eventKey::QUIT;
    if (event.type != sf::Event::KeyPressed)
        return eventKey::NULL_EVENT;
    if (keyEvent.find(event.key.code) == keyEvent.end())
        return eventKey::NULL_EVENT;
    return keyEvent[event.key.code];
}
