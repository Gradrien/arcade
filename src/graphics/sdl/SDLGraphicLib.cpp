/*
** EPITECH PROJECT, 2023
** BS
** File description:
** foo_lib
*/

#include <cstdio>
#include <iostream>
#include <memory>
#include "IGraphic.hpp"
#include "SDLGraphic.hpp"

extern "C"
{
    std::unique_ptr<IGraphic> entryPoint(void)
    {
        return (std::make_unique<SDLGraphic>());
    }
}
