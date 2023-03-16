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
    this->graphPaths_.push_back(libName);
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
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        if (tmpGraphLoader.getInstance(dir_entry.path())) {
            this->pushLib(dir_entry.path(), this->graphPaths_);
            continue;
        }
        if (tmpGameLoader.getInstance(dir_entry.path())) {
            this->pushLib(dir_entry.path(), this->gamePaths_);
            continue;
        }
    }
}

void Core::pushLib(std::string path, std::vector<std::string>& container)
{
    for (std::string savedPath : container) {
        if (savedPath == path)
            return;
    }
    container.push_back(path);
}

void Core::gameLoopHandler()
{
    shape circleTest = { .pos { 200, 200 },
        .size { 50, 100 },
        .m_color { .r = 0, .g = 151, .b = 255, .a = 255 },
        .replacementChar = '#',
        .text { "Allo" },
        .type = shapeType::RECTANGLE };
    this->graphLib_->createWindow("Arcade", 800, 800);
    while (this->graphLib_) {
        this->graphLib_->clearWindow();
        this->handleEvent();
        this->graphLib_->displayShape(circleTest);
        this->graphLib_->displayWindow();
    }
}

void Core::handleEvent()
{
    switch (this->graphLib_->getEvent()) {
    case eventKey::NULL_EVENT:
        break;
    case eventKey::Q:
        this->graphLib_->destroyWindow();
        break;
    case eventKey::TAB:
        this->loadNextGraph();
        break;
    case eventKey::G:
        this->loadNextGame();
        break;
    case eventKey::M:
        this->gameState_ = GState::MENU;
        break;
    case eventKey::R:
        this->restartGame();
        break;
    default:
        // Send event to game lib
        break;
    }
}

void Core::loadNextGame() { return; }

void Core::loadNextGraph()
{
    this->graphLib_->destroyWindow();
    if ((this->graphIndex_ + 1) >= this->graphPaths_.size()) {
        this->graphIndex_ = 0;
    } else {
        this->graphIndex_ += 1;
    }
    this->graphLib_ = nullptr;
    this->graphLib_ = this->graphLoader_.getInstance(this->graphPaths_[this->graphIndex_]);
    this->graphLib_->createWindow("Arcade", 800, 800);
}

void Core::restartGame() { return; }
