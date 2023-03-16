/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const char* libName)
{
    if (!libName)
        throw ArcadeError("Invalid number of argument");
    this->graphLib_ = this->graphLoader_.getInstance(libName);
    if (!this->graphLib_)
        throw ArcadeError("Graphic lib cannot be loaded");
    this->getAllLib();
    this->gameState_ = GState::MENU;
    this->gameLoopHandler();
}

void Core::getAllLib()
{
    DLLoader<IGraphic> tmpGraphLoader {};
    DLLoader<IGame> tmpGameLoader {};
    const std::filesystem::path path { "./lib" };
    for (auto const& dir_entry : std::filesystem::directory_iterator { path }) {
        if (tmpGraphLoader.getInstance(dir_entry.path())) {
            graphPaths.push_back(dir_entry.path());
            continue;
        }
        if (tmpGameLoader.getInstance(dir_entry.path())) {
            gamePaths.push_back(dir_entry.path());
            continue;
        }
    }
}

void Core::gameLoopHandler() {
    this->graphLib_->createWindow("Arcade", 800, 800);
    while (this->graphLib_) {
        this->graphLib_->clearWindow();
        this->graphLib_->displayWindow();
    }
}
