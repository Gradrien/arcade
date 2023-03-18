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
    this->graphLib_->createWindow("Arcade", 800, 800);
    this->graphPaths_.push_back(libName);
    this->getAllLib();
    this->gameState_ = GState::PLAY;
    this->gameLib_ = this->gameLoader_.getInstance(this->gamePaths_[0]);
    this->gameLib_->init();
    this->coreStateHandler();
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

void Core::coreStateHandler()
{
    while (this->gameState_ != GState::QUIT) {
        this->gamePaths_.clear();
        this->graphPaths_.clear();
        this->getAllLib();
        this->handleEvent();
        switch (this->gameState_) {
        case GState::MENU:
            this->menu->menuLoopHandler(this->graphLib_, *this);
            break;
        case GState::PLAY:
        case GState::PAUSE:
            this->gameLoopHandler();
            break;
        default:
            break;
        }
    }
    this->quitArcade();
}

void Core::gameLoopHandler()
{
    if (!this->graphLib_->isOpenWindow())
        this->graphLib_->createWindow("Arcade", 800, 800);
    this->graphLib_->clearWindow();
    this->gameLib_->display(this->graphLib_);
    this->graphLib_->displayWindow();
}

void Core::handleEvent()
{
    eventKey evt = this->graphLib_->getEvent();
    switch (evt) {
    case eventKey::Q:
        this->gameState_ = GState::QUIT;
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
        if (this->gameState_ == GState::PLAY)
            this->gameLib_->updateGame(evt);
        if (this->gameState_ == GState::MENU)
            this->menu->handleEvent(evt, *this);
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
    if (this->graphLib_->isOpenWindow())
        this->graphLib_->destroyWindow();
    if ((this->graphIndex_ + 1) >= this->graphPaths_.size()) {
        this->graphIndex_ = 0;
    } else {
        this->graphIndex_ += 1;
    }
    this->graphLib_ = this->graphLoader_.getInstance(this->graphPaths_[this->graphIndex_]);
}

int Core::findPathIndex(const std::string& path, const std::vector<std::string>& vec) const
{
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == path)
            return static_cast<int>(i);
    }
    return -1;
}

void Core::loadSpecificGraph(std::string path)
{
    int index = this->findPathIndex(path, this->graphPaths_);
    if (index == -1)
        return;
    if (this->graphLib_->isOpenWindow())
        this->graphLib_->destroyWindow();
    this->graphLib_ = this->graphLoader_.getInstance(path);
    this->graphIndex_ = index;
}

void Core::loadSpecificGame(std::string path)
{
    int index = this->findPathIndex(path, this->gamePaths_);
    if (index == -1)
        return;
    this->gameLib_ = this->gameLoader_.getInstance(path);
    this->gameLib_->init();
    this->gameIndex_ = index;
}

void Core::restartGame() { return; }

void Core::quitArcade() { this->graphLib_->destroyWindow(); }

GState Core::getCoreState() const { return this->gameState_; }
