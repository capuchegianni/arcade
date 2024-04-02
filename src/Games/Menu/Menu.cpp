/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "../../../include/Games/Menu/Menu.hpp"
#include "../../../include/Core/LdlWrapper.hpp"
#include "../../../include/Entities/Button/Button.hpp"
#include "../../../include/Entities/Empty/Empty.hpp"
#include "../../../include/Entities/Background/Background.hpp"

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Menu>();
}

Menu::Menu() :
    AGameModule("Menu") {
    this->_gameStatus = GameStatus::WIN;
}

static std::map<int, std::string> getGraphicsList() {
    std::map<int, std::string> graphicsLibs;
    int i = 0;

    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGraphicalModule>>("createLib");
            graphicsLibs[i] = file.path().string();
            i++;
        } catch (...) { }
    }
    return graphicsLibs;
}

static std::map<int, std::string> getGameList() {
    std::map<int, std::string> gameLibs;
    int i = 0;

    for (const auto& file : std::filesystem::directory_iterator("lib")) {
        if (file.path().string().rfind(".so") != file.path().string().size() - 3)
            continue;
        if (file.path().string() == "lib/arcade_menu.so")
            continue;
        try {
            LdlWrapper lib;
            lib.openLib(file.path().string());
            lib.createLib<std::shared_ptr<AGameModule>>("createGame");
            gameLibs[i] = file.path().string();
            i++;
        } catch (...) { }
    }
    return gameLibs;
}

std::vector<std::shared_ptr<AEntities>> Menu::initAllEntities() const {
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_lib.jpg", ASCII(' ', Color(0, 162, 255)), "Button1"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_game.jpg", ASCII(' ', Color(239, 255, 0)), "Button2"));
    entities.push_back(std::make_shared<Background>(0, std::make_pair(0, 0), "assets/images/dinosaure.png", ASCII(' ', Color()), "Background"));
    entities.push_back(std::make_shared<Empty>(0, std::make_pair(0, 0), "assets/images/arrow_left.png", ASCII('<', Color(0, 0, 0)), "Arrow"));
    std::cout << "Menu entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

void Menu::catchInput(Input input) {
    this->initMap();
    if (input == UP || input == RIGHT)
        this->_selectedGame == this->_gameLibs.size() - 1 ? this->_selectedGame = 0 : this->_selectedGame + 1;
    if (input == DOWN || input == LEFT)
        this->_selectedGame == 0 ? this->_selectedGame = this->_gameLibs.size() - 1 : this->_selectedGame - 1;
    if (input == ENTER) {
        this->_gameStatus = GameStatus::RUNNING;
        this->_selectedGame = 0;
    }
    this->updateMap();
}

void Menu::updateMap() {
    this->_map[2].clear();
    for (int i = 0; i < this->_gameLibs.size(); i++) {
        if (i == this->_selectedGame)
            this->_map[2].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, std::make_pair(450, 20 + i * 60), "", ASCII('<', Color()), "Arrow")}));
        else
            this->_map[2].push_back(Tiles({}));
    }
}

void Menu::initMap() {
    if (this->_gameStatus != GameStatus::WIN)
        return;

    std::pair<int, int> graphicButtonPos = std::make_pair(50, 20);
    std::pair<int, int> gameButtonPos = std::make_pair(270, 20);

    this->_graphicsLibs = getGraphicsList();
    this->_gameLibs = getGameList();
    this->_map.clear();
    this->_map.resize(3);
    for (int i = 0; i < this->_graphicsLibs.size(); i++) {
        this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, graphicButtonPos, this->_graphicsLibs[i], ASCII(' ', Color(0, 0, 0)), "Button1")}));
        graphicButtonPos.second += 60;
    }
    for (int i = 0; i < this->_gameLibs.size(); i++) {
        this->_map[1].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, gameButtonPos, this->_gameLibs[i], ASCII(' ', Color(0, 0, 0)), "Button2")}));
        gameButtonPos.second += 60;
    }
    this->_gameStatus = GameStatus::RUNNING;
}
