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
    this->gameState_ = GState::PLAY;
    if (this->gameState_ == GState::MENU)
        this->menu->menuLoopHandler(this->graphLib_, this);
    this->gameLib_ = this->gameLoader_.getInstance(this->gamePaths_[0]);
    this->gameLib_->init();
    this->gameLoopHandler();
}

void Core::getAllLib()
{
    const std::filesystem::path gamePath { "./lib/games/" };
    const std::filesystem::path graphicPath { "./lib/graphics/" };
    for (auto const& dir_entry : std::filesystem::directory_iterator { gamePath }) {
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        this->pushLib(dir_entry.path(), this->gamePaths_);
    }
    for (auto const& dir_entry : std::filesystem::directory_iterator { graphicPath }) {
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        this->pushLib(dir_entry.path(), this->graphPaths_);
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

std::vector<std::string> Core::getGraphPaths() { return this->graphPaths_; }

std::vector<std::string> Core::getGamePaths() { return this->gamePaths_; }

void Core::gameLoopHandler()
{
    this->graphLib_->createWindow("Arcade", 800, 800);
    while (this->graphLib_) {
        this->handleEvent();
        this->graphLib_->clearWindow();
        if (this->gameState_ == GState::MENU)
            this->menu->menuLoopHandler(this->graphLib_, this);
        this->gameLib_->display(this->graphLib_);
        this->graphLib_->displayWindow();
    }
}

void Core::handleEvent()
{
    eventKey evt = this->graphLib_->getEvent();
    switch (evt) {
    case eventKey::NULL_EVENT:
        break;
    case eventKey::Q:
        this->graphLib_->destroyWindow();
        break;
    case eventKey::N:
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
        this->gameLib_->updateGame(evt);
        break;
    }
}

void Core::loadNextGame()
{
    if ((this->gameIndex_ + 1) >= this->gamePaths_.size()) {
        this->gameIndex_ = 0;
    } else {
        this->gameIndex_ += 1;
    }
    this->gameLib_ = nullptr;
    this->gameLib_ = this->gameLoader_.getInstance(this->gamePaths_[this->gameIndex_]);
    this->gameLib_->init();
}

void Core::loadNextGraph()
{
    this->graphLib_->destroyWindow();
    if ((this->graphIndex_ + 1) >= this->graphPaths_.size()) {
        this->graphIndex_ = 0;
    } else {
        this->graphIndex_ += 1;
    }
    std::cout << this->graphIndex_ << std::endl;
    this->graphLib_ = nullptr;
    this->graphLib_ = this->graphLoader_.getInstance(this->graphPaths_[this->graphIndex_]);
    this->graphLib_->createWindow("Arcade", 800, 800);
}

void Core::restartGame() { return; }
