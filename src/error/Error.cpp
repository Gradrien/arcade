/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Error
*/

#include "Error.hpp"

ArcadeError::ArcadeError(const char *msg) : msg_{msg}
{
}

const char* ArcadeError::what() const noexcept
{
    return this->msg_;
}
