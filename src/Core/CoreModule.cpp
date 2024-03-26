/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

CoreModule::~CoreModule() {
    this->closeGraphicalLib();
}


// Misc

void CoreModule::checkFile(const std::string& path) const {
    if (path.empty())
        throw FileError("Invalid empty filename", 84);
    if (path.rfind(".so") != path.size() - 3)
        throw FileError("Invalid file extension", 84);
    if (!std::filesystem::exists("lib"))
        throw FileError("Directory 'lib' not found", 84);
    if (!std::filesystem::exists(path))
        throw FileError("File '" + path + "' not found", 84);
}

void CoreModule::startGame() {
    // this->initEntities();
    this->getGraphicalModule()->createWindow("Arcade", {500, 500});
    std::cout << this->getGraphicalModule()->getLibraryType() << " window created" << std::endl;
    while (this->getGraphicalModule()->isWindowOpen()) {
        this->getGraphicalModule()->displayWindow();
        Input input = this->getGraphicalModule()->parseKeyboard();
    }
}

void CoreModule::changeGame(const std::string& path, const std::string& func) {
    this->closeGameLib();
    this->loadGameLibrary(path, func);
}

void CoreModule::changeGraphics(const std::string& path, const std::string& func) {
    this->closeGraphicalLib();
    this->loadGraphicalLibrary(path, func);
}

void CoreModule::initEntities(const std::vector<IEntities>& entities) {
    (void)entities;
    return;
}


// Graphical libraries

void CoreModule::closeGraphicalLib() {
    if (this->_graphicalLib.getHandle()) {
        if (this->_graphicalModule)
            this->_graphicalModule->destroyWindow();
        this->_graphicalModule.reset();
        dlclose(this->_graphicalLib.getHandle());
        std::cout << "Library closed" << std::endl;
    }
}

void CoreModule::loadGraphicalLibrary(const std::string& path, const std::string& func) {
    this->_graphicalLib.openLib(path);
    this->_graphicalModule = this->_graphicalLib.createGraphicalLib(func);
}

std::shared_ptr<AGraphicalModule>& CoreModule::getGraphicalModule() {
    return this->_graphicalModule;
}

LdlWrapper& CoreModule::getGraphicalLib() {
    return this->_graphicalLib;
}


// Game libraries

void CoreModule::closeGameLib() {
    if (this->_gameLib.getHandle()) {
        this->_gameModule.reset();
        dlclose(this->_gameLib.getHandle());
        std::cout << "Game library closed" << std::endl;
    }
}

void CoreModule::loadGameLibrary(const std::string& path, const std::string& func) {
    this->_gameLib.openLib(path);
    this->_gameModule = this->_gameLib.createGameLib(func);
}

std::shared_ptr<AGameModule>& CoreModule::getGameModule() {
    return this->_gameModule;
}

LdlWrapper& CoreModule::getGameLib() {
    return this->_gameLib;
}
