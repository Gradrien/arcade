/*
²** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <chrono>
#include <ctime>

Core::Core(const char* libName)
{
    if (!libName)
        throw ArcadeError("Invalid number of argument");
    this->isLibGraphical(libName);
    this->graphLib_ = this->graphLoader_.getInstance(libName);
    if (!this->graphLib_)
        throw ArcadeError("Graphic lib cannot be loaded");
    this->graphLib_->createWindow("Arcade", 800, 800);
    this->graphPaths_.emplace_back(libName);
    this->currentGraph_ = libName;
    this->getAllLib();
    this->gameState_ = GState::MENU;
    this->gameLib_ = this->gameLoader_.getInstance(this->gamePaths_[0]);
    this->gameLib_->init();
    this->menu_ = std::make_unique<Menu>();
}

void Core::isLibGraphical(const std::string& libName)
{
    const std::filesystem::path libPath { "./lib" };
    std::filesystem::path lib { libName };

    for (auto const& dir_entry : std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        if (validLibs.find(dir_entry.path().filename()) == validLibs.end())
            continue;
        if (validLibs.at(dir_entry.path().filename()) == libType::GAME && dir_entry.path().filename() == lib.filename())
            throw ArcadeError("Invalid library, you must choose a graphical library. Check the README for more information");
    }
}

void Core::getAllLib()
{
    const std::filesystem::path libPath { "./lib" };
    for (auto const& dir_entry : std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().filename().c_str()[0] == '.')
            continue;
        if (validLibs.find(dir_entry.path().filename()) == validLibs.end())
            continue;
        if (validLibs.at(dir_entry.path().filename()) == libType::GAME)
            this->pushLib(dir_entry.path(), this->gamePaths_);
        else
            this->pushLib(dir_entry.path(), this->graphPaths_);
    }
}

void Core::pushLib(const std::string& path, std::vector<std::string>& container)
{
    for (const std::string& savedPath : container) {
        if (savedPath == path)
            return;
    }
    container.push_back(path);
}

std::vector<std::string> Core::getGraphPaths() { return this->graphPaths_; }

std::vector<std::string> Core::getGamePaths() { return this->gamePaths_; }

void Core::coreStateHandler()
{
    std::clock_t start = std::clock();
    while (this->gameState_ != GState::QUIT) {
        const std::clock_t end = std::clock();
        if ((end - start) <= 65000) {
            continue;
        }
        start = std::clock();
        this->gamePaths_.clear();
        this->graphPaths_.clear();
        this->getAllLib();
        this->handleEvent();
        switch (this->gameState_) {
        case GState::MENU:
            this->menu_->menuLoopHandler(*this->graphLib_, *this);
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
    if (!this->graphLib_->isOpenWindow()) {
        const elemSize winSize = this->gameLib_->getDisplaySize();
        this->graphLib_->createWindow("Arcade", winSize.width, winSize.height);
    }
    this->graphLib_->clearWindow();
    this->gameLib_->display(*this->graphLib_);
    this->graphLib_->displayWindow();
}

void Core::handleEvent()
{
    const eventKey evt = this->graphLib_->getEvent();

    if (this->menu_->isUserTyping() && this->gameState_ == GState::MENU)
        return this->menu_->handleEvent(evt, *this);
    switch (evt) {
    case eventKey::QUIT:
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
            this->menu_->handleEvent(evt, *this);
        break;
    }
}

void Core::loadNextGame()
{
    int index = this->findPathIndex(this->currentGame_, this->gamePaths_);
    if (index == -1)
        return;
    index++;
    if (static_cast<std::size_t>(index) >= this->gamePaths_.size())
        index = 0;
    this->gameLib_.release();
    this->gameLib_ = this->gameLoader_.getInstance(this->gamePaths_[index]);
    this->gameLib_->init();
    this->currentGame_ = this->gamePaths_[index];
}

void Core::loadNextGraph()
{
    if (this->graphLib_->isOpenWindow())
        this->graphLib_->destroyWindow();
    int index = this->findPathIndex(this->currentGraph_, this->graphPaths_);
    if (index == -1)
        return;
    index++;
    if (static_cast<std::size_t>(index) >= this->graphPaths_.size())
        index = 0;
    this->graphLib_.release();
    this->graphLib_ = this->graphLoader_.getInstance(this->graphPaths_[index]);
    this->currentGraph_ = this->graphPaths_[index];
}

int Core::findPathIndex(const std::string& path, const std::vector<std::string>& vec) const
{
    const std::filesystem::path libPath { path };
    for (std::size_t i = 0; i < vec.size(); ++i) {
        const std::filesystem::path tmp { vec[i] };
        if (tmp.filename() == libPath.filename())
            return static_cast<int>(i);
    }
    return -1;
}

void Core::loadSpecificGraph(std::string path)
{
    const int index = this->findPathIndex(path, this->graphPaths_);
    if (index == -1)
        return;
    if (this->graphLib_->isOpenWindow())
        this->graphLib_->destroyWindow();
    this->graphLib_.release();
    this->graphLib_ = this->graphLoader_.getInstance(path);
    this->currentGraph_ = path;
}

void Core::loadSpecificGame(std::string path)
{
    const int index = this->findPathIndex(path, this->gamePaths_);
    if (index == -1)
        return;
    this->gameLib_.release();
    this->gameLib_ = this->gameLoader_.getInstance(path);
    this->gameLib_->init();
    this->currentGame_ = path;
}

void Core::restartGame() { this->gameLib_->reset(); }

void Core::quitArcade() { this->graphLib_->destroyWindow(); }

GState Core::getCoreState() const { return this->gameState_; }

void Core::setCoreState(const GState& state) { this->gameState_ = state; }

std::string Core::getCurrentGraph() const { return this->currentGraph_; }

std::string Core::getCurrentGame() const { return this->currentGame_; }

void Core::setCurrentGraph(const std::string& path) { this->currentGraph_ = path; }

void Core::setCurrentGame(const std::string& path) { this->currentGame_ = path; }
