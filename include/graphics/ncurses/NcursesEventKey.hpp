/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEventKey
*/

/****************************************************************
 * @file NcursesEventKey.hpp
 * @brief NcursesEventKey class
 * @details This file is used to handle the NcursesEventKey
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef NCURSESEVENTKEY_HPP_
#define NCURSESEVENTKEY_HPP_
#include "IGraphic.hpp"
#include <curses.h>
#include <unordered_map>

std::unordered_map<char, eventKey> keyEvent = { { 'a', eventKey::A },
    { 'b', eventKey::B }, { 'c', eventKey::C }, { 'd', eventKey::D },
    { 'e', eventKey::E }, { 'f', eventKey::F }, { 'g', eventKey::G },
    { 'h', eventKey::H }, { 'i', eventKey::I }, { 'j', eventKey::J },
    { 'k', eventKey::K }, { 'l', eventKey::L }, { 'm', eventKey::M },
    { 'n', eventKey::N }, { 'o', eventKey::O }, { 'p', eventKey::P },
    { 'q', eventKey::Q }, { 'r', eventKey::R }, { 's', eventKey::S },
    { 't', eventKey::T }, { 'u', eventKey::U }, { 'v', eventKey::V },
    { 'w', eventKey::W }, { 'x', eventKey::X }, { 'y', eventKey::Y },
    { 'z', eventKey::Z }, { KEY_F0, eventKey::SPACE }, { '\n', eventKey::ENTER },
    { KEY_LEFT, eventKey::LARROW }, { KEY_RIGHT, eventKey::RARROW }, { KEY_DOWN, eventKey::BARROW },
    { KEY_UP, eventKey::UARROW }, { KEY_BACKSPACE, eventKey::DELETE }, { KEY_STAB, eventKey::TAB } };

#endif /* !NCURSESEVENTKEY_HPP_ */
