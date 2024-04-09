/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

CoreModule::CoreModule() {
    this->getGraphicsList();
    this->getGameList();
    this->_menu.setGraphicsLibs(this->_graphicalLibs);
    this->_menu.setGameLibs(this->_gameLibs);
}

CoreModule::~CoreModule() {
    this->closeGraphicalLib();
    this->closeGameLib();
}


// Misc

void CoreModule::getGraphicsList() {
    int i = 0;

    std::cout << "Loading game libraries..." << std::endl;
    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGraphicalModule>>("createLib");
            this->_graphicalLibs[i] = file.path().string();
            std::cout << "Library '" << file.path().string() << "' loaded" << std::endl;
            lib.closeLib();
            i++;
        } catch (...) {
            continue;
        }
    }
    if (this->_graphicalLibs.empty())
        throw FileError("No graphical libraries found", 84);
}

void CoreModule::getGameList() {
    int i = 0;

    std::cout << "Loading game libraries..." << std::endl;
    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        if (file.path().string() == "lib/arcade_menu.so") {
            this->_menuIsGame = true;
            this->_currentGame = {i, file.path().string()};
            this->_menuIsRunning = true;
        }
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGameModule>>("createGame");
            this->_gameLibs[i] = file.path().string();
            std::cout << "Library '" << file.path().string() << "' loaded" << std::endl;
            lib.closeLib();
            i++;
        } catch (...) {
            continue;
        }
    }
    if (this->_gameLibs.empty())
        throw FileError("No game libraries found", 84);
    if (!this->_menuIsGame) {
        std::cout << "No menu library found, creating default menu" << std::endl;
        this->_gameLibs[i] = "defaultMenu";
        this->_currentGame = {this->_gameLibs.size() - 1, this->_gameLibs[this->_gameLibs.size() - 1]};
        this->_menuIsRunning = true;
    }
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
    if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu") {
        this->getGraphicalModule()->initAssets(this->_menu.initAllEntities());
        this->_menu.getScoreFileInfos();
    } else
        this->changeGame("createGame");
    while(this->getGraphicalModule()->isWindowOpen()) {
        if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu") {
            if (this->_menuIsRunning) {
                this->_player = this->_menu.getPlayer();
                if (this->_player == "")
                    this->_player = "Anonymous";
            }
            this->getGraphicalModule()->showMap(this->_menu.getMap());
            this->getGraphicalModule()->displayWindow();
            this->handleEvents(this->getGraphicalModule()->parseKeyboard());
        } else {
            if (this->_menuIsRunning) {
                this->_player = this->_gameModule->getPlayerName();
                if (this->_player == "")
                    this->_player = "Anonymous";
            }
            this->getGameModule()->updateGame();
            this->getGraphicalModule()->showMap(this->getGameModule()->getMap());
            this->getGraphicalModule()->displayWindow();
            this->handleEvents(this->getGraphicalModule()->parseKeyboard());
        }
    }
}

void CoreModule::startWindow() {
    this->getGraphicalModule()->createWindow("Arcade", {500, 500});
}

void CoreModule::startMenu() {
    this->_menuIsRunning = true;
    if (this->_menuIsGame) {
        for (auto& game : this->_gameLibs) {
            if (game.second == "lib/arcade_menu.so")
                this->_currentGame = {game.first, game.second};
        }
        this->changeGame("createGame");
    } else {
        this->closeGameLib();
        this->_currentGame = {this->_gameLibs.size() - 1, this->_gameLibs[this->_gameLibs.size() - 1]};
        this->getGraphicalModule()->initAssets(this->_menu.initAllEntities());
        this->_menu.getScoreFileInfos();
    }
}

static void updateHighScoreFile(const std::map<std::string, int>& oldScores, const std::string& gameName) {
    std::map<std::pair<std::string, std::string>, int> newScores;

    std::ifstream fileIn("assets/scores.txt");
    std::string line;
    while (std::getline(fileIn, line)) {
        std::istringstream ss(line);
        std::string fileGameName, playerName, scoreStr;
        std::getline(ss, fileGameName, ':');
        std::getline(ss, playerName, ':');
        std::getline(ss, scoreStr, ':');
        newScores[std::make_pair(fileGameName, playerName)] = std::stoi(scoreStr);
    }
    fileIn.close();

    for (const auto& pair : oldScores) {
        if (newScores[std::make_pair(gameName, pair.first)] < pair.second)
            newScores[std::make_pair(gameName, pair.first)] = pair.second;
    }

    std::ofstream fileOut("assets/scores.txt");
    for (const auto& pair : newScores) {
        fileOut << pair.first.first << ':' << pair.first.second << ':' << pair.second << '\n';
    }
    fileOut.close();
}

void CoreModule::reloadGame(bool isChanging) {
    if (isChanging) {
        updateHighScoreFile(this->_gameModule->getHighScore(), this->_gameModule->getGameName());
        if (this->_currentGame.first == static_cast<int>(this->_gameLibs.size() - 1))
            this->_currentGame = {0, this->_gameLibs[0]};
        else
            this->_currentGame = {this->_currentGame.first + 1, this->_gameLibs[this->_currentGame.first + 1]};
    }
    this->changeGame("createGame");
}

void CoreModule::handleEvents(const Input& input) {
    int newGame = -1;

    switch (input) {
    case ESC:
        if (!_menuIsRunning)
            updateHighScoreFile(this->_gameModule->getHighScore(), this->_gameModule->getGameName());
        this->getGraphicalModule()->destroyWindow();
        break;

    case CHANGE_LIB:
        this->changeGraphics("createLib");
        this->startWindow();
        if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu") {
            this->getGraphicalModule()->initAssets(this->_menu.initAllEntities());
            this->_menu.getScoreFileInfos();
        } else
            this->getGraphicalModule()->initAssets(this->getGameModule()->initAllEntities());
        break;

    case CHANGE_GAME:
        if (this->_menuIsRunning) {
            if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu")
                newGame = this->_menu.catchInput(input);
            else
                this->getGameModule()->catchInput(input);
            break;
        }
        this->reloadGame(true);
        break;

    case MENU:
        if (!_menuIsRunning) {
            updateHighScoreFile(this->_gameModule->getHighScore(), this->_gameModule->getGameName());
            this->startMenu();
        }
        break;

    case RELOAD:
        if (this->_menuIsRunning) {
            if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu")
                this->_menu.catchInput(input);
            else
                this->getGameModule()->catchInput(input);
            break;
        }
        this->reloadGame(false);
        break;

    default:
        if (!this->_menuIsGame && this->_currentGame.second == "defaultMenu")
            newGame = this->_menu.catchInput(input);
        else
            this->getGameModule()->catchInput(input);
        break;
    }
    if (newGame != -1) {
        this->_currentGame = {newGame, this->_gameLibs[newGame]};
        this->reloadGame(false);
    }
    newGame = -1;
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
    if (this->_currentGraphic.second == "") {
        for (const auto& lib : this->_graphicalLibs) {
            if (path.substr(path.find_first_of('/') + 1) == lib.second)
                this->_currentGraphic = {lib.first, lib.second};
        }
    }
    this->_graphicalLib.openLib(path);
    this->_graphicalModule = this->_graphicalLib.createLib<std::shared_ptr<AGraphicalModule>>(func);
    std::cout << this->getGraphicalModule()->getLibraryType() << " window created" << std::endl;
}

std::shared_ptr<AGraphicalModule>& CoreModule::getGraphicalModule() {
    return this->_graphicalModule;
}

LdlWrapper& CoreModule::getGraphicalLib() {
    return this->_graphicalLib;
}

void CoreModule::changeGraphics(const std::string& func) {
    if (this->_currentGraphic.first == static_cast<int>(this->_graphicalLibs.size() - 1))
        this->_currentGraphic = {0, this->_graphicalLibs[0]};
    else
        this->_currentGraphic = {this->_currentGraphic.first + 1, this->_graphicalLibs[this->_currentGraphic.first + 1]};
    this->closeGraphicalLib();
    this->loadGraphicalLibrary(this->_currentGraphic.second, func);
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
    std::cout << this->getGameModule()->getGameName() << " game started" << std::endl;
}

std::shared_ptr<AGameModule>& CoreModule::getGameModule() {
    return this->_gameModule;
}

LdlWrapper& CoreModule::getGameLib() {
    return this->_gameLib;
}

void CoreModule::changeGame(const std::string& func) {
    this->closeGameLib();
    this->loadGameLibrary(this->_currentGame.second, func);
    this->getGraphicalModule()->initAssets(this->getGameModule()->initAllEntities());
    this->getGameModule()->setPlayerName(this->_player);
}
