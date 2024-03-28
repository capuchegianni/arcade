/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

CoreModule::~CoreModule() {
    this->closeGraphicalLib();
    this->closeGameLib();
}


// Misc

static std::deque<std::string> getGraphicsList() {
    std::deque<std::string> graphicsLibs;

    std::cout << "Loading graphical libraries..." << std::endl;
    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGraphicalModule>>("createLib");
            graphicsLibs.push_back(file.path().string());
            std::cout << "Library '" << file.path().string() << "' loaded" << std::endl;
        } catch (...) {
            continue;
        }
    }
    return graphicsLibs;
}

static std::deque<std::string> getGameList() {
    std::deque<std::string> gameLibs;

    std::cout << "Loading game libraries..." << std::endl;
    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        if (file.path().string() == "lib/arcade_menu.so")
            continue;
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGameModule>>("createGame");
            gameLibs.push_back(file.path().string());
            std::cout << "Library '" << file.path().string() << "' loaded" << std::endl;
            lib.closeLib();
        } catch (...) {
            continue;
        }
    }
    return gameLibs;
}

void CoreModule::getLibraries() {
    this->_graphicalLibs = getGraphicsList();
    this->_gameLibs = getGameList();
}

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
    while (this->getGraphicalModule()->isWindowOpen()) {
        this->getGraphicalModule()->displayWindow();
        this->handleEvents(this->getGraphicalModule()->parseKeyboard());
    }
}

void CoreModule::initEntities(const std::vector<AEntities>& entities) {
    (void)entities;
    return;
}

static std::string nextGraphLib(std::deque<std::string>& graphLibs) {
    std::string nextGraphLib = graphLibs.front();

    graphLibs.pop_front();
    graphLibs.push_back(nextGraphLib);
    return nextGraphLib;
}

static std::string nextGameLib(std::deque<std::string>& gameLibs) {
    std::string nextGameLib = gameLibs.front();

    gameLibs.pop_front();
    gameLibs.push_back(nextGameLib);
    return nextGameLib;
}

void CoreModule::handleEvents(const Input& input) {

    switch (input) {
    case ESC:
        this->getGraphicalModule()->destroyWindow();
        break;

    case CHANGE_LIB:
        this->changeGraphics(nextGraphLib(this->_graphicalLibs), "createLib");
        this->startGame();
        break;

    case CHANGE_GAME:
        this->changeGame(nextGameLib(this->_gameLibs), "createGame");
        break;

    case MENU:
        this->changeGame("lib/arcade_menu.so", "createGame");
        break;

    case RELOAD:
        this->changeGame(this->_currentGamePath, "createGame");
        break;

    case NONE:
        break;

    default:
        this->getGameModule()->parseInput(input);
        break;
    }
}


// Graphical libraries

void CoreModule::closeGraphicalLib() {
    if (this->_graphicalLib.getHandle()) {
        if (this->_graphicalModule)
            this->_graphicalModule->destroyWindow();
        this->_graphicalModule.reset();
        this->_graphicalModule = nullptr;
        this->_graphicalLib.closeLib();
        std::cout << "Library closed" << std::endl;
    }
}

void CoreModule::loadGraphicalLibrary(const std::string& path, const std::string& func) {
    this->_graphicalLib.openLib(path);
    this->_graphicalModule = this->_graphicalLib.createLib<std::shared_ptr<AGraphicalModule>>(func);
    this->_currentGraphicalPath = path;
    std::cout << this->getGraphicalModule()->getLibraryType() << " window created" << std::endl;
}

std::shared_ptr<AGraphicalModule>& CoreModule::getGraphicalModule() {
    return this->_graphicalModule;
}

LdlWrapper& CoreModule::getGraphicalLib() {
    return this->_graphicalLib;
}

void CoreModule::changeGraphics(const std::string& path, const std::string& func) {
    this->closeGraphicalLib();
    this->loadGraphicalLibrary(path, func);
}


// Game libraries

void CoreModule::closeGameLib() {
    if (this->_gameLib.getHandle()) {
        this->_gameModule.reset();
        this->_gameModule = nullptr;
        this->_gameLib.closeLib();
        std::cout << "Game library closed" << std::endl;
    }
}

void CoreModule::loadGameLibrary(const std::string& path, const std::string& func) {
    this->_gameLib.openLib(path);
    this->_gameModule = this->_gameLib.createLib<std::shared_ptr<AGameModule>>(func);
    this->_currentGamePath = path;
    std::cout << this->getGameModule()->getGameName() << " game started" << std::endl;
}

std::shared_ptr<AGameModule>& CoreModule::getGameModule() {
    return this->_gameModule;
}

LdlWrapper& CoreModule::getGameLib() {
    return this->_gameLib;
}

void CoreModule::changeGame(const std::string& path, const std::string& func) {
    this->closeGameLib();
    this->loadGameLibrary(path, func);
}
