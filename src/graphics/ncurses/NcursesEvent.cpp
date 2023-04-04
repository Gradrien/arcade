/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEvent
*/

#include "NcursesEventKey.hpp"
#include "NcursesGraphic.hpp"

eventKey NcursesGraphic::getEvent()
{
    const char key = wgetch(this->window_);
    if (keyEvent.find(key) == keyEvent.end())
        return eventKey::NULL_EVENT;
    return keyEvent[key];
}
