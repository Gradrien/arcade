/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <exception>
#include <iostream>

class ArcadeError : public std::exception {
  public:
    ArcadeError(const char* msg);
    ~ArcadeError() override = default;
    const char* what() const noexcept override;

  private:
    const char* msg_;
};

#endif /* !ERROR_HPP_ */
