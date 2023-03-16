/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** TestGameLib
*/

#include "TestGame.hpp"

extern "C"
{
    std::unique_ptr<IGame> entryPoint(void)
    {
        return (std::make_unique<TestGame>());
    }
}
