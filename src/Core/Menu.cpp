/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include "../../include/Core/Menu.hpp"
#include "../../include/Entities/Button/Button.hpp"
#include "../../include/Entities/Empty/Empty.hpp"
#include "../../include/Entities/Background/Background.hpp"

Menu::Menu() {
    this->_map.resize(3);
}

std::vector<std::shared_ptr<AEntities>> Menu::initAllEntities() const {
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_lib.jpg", ASCII(' ', Color(239, 255, 0)), "Button1"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_game.jpg", ASCII(' ', Color(0, 162, 255)), "Button2"));
    entities.push_back(std::make_shared<Background>(0, std::make_pair(0, 0), "assets/images/dinosaure.png", ASCII(' ', Color()), "Background"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/arrow_left.png", ASCII(' ', Color(0, 0, 0)), "Arrow"));
    std::cout << "Menu entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

int Menu::catchInput(Input input) {
    int gameNumber = this->_gameLibs.size() - 1;

    this->initMap();
    if (input == DOWN || input == RIGHT)
        this->_selectedGame = (this->_selectedGame == gameNumber ? 0 : this->_selectedGame + 1);
    if (input == UP || input == LEFT)
        this->_selectedGame = (this->_selectedGame == 0 ? gameNumber : this->_selectedGame - 1);
    if (input == ENTER)
        return this->_selectedGame;
    this->updateMap();
    return -1;
}

void Menu::updateMap() {
    this->_map[2].clear();
    for (size_t i = 0; i < this->_gameLibs.size(); i++) {
        if (static_cast<int>(i) == this->_selectedGame)
            this->_map[2].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, std::make_pair(450, 20 + i * 60), "^", ASCII('^', Color(0, 0, 0)), "Arrow")}));
        else
            this->_map[2].push_back(Tiles({}));
    }
}

void Menu::initMap() {
    if (this->_isInitialized)
        return;

    std::pair<int, int> graphicButtonPos = std::make_pair(50, 20);
    std::pair<int, int> gameButtonPos = std::make_pair(270, 20);

    for (size_t i = 0; i < this->_graphicsLibs.size(); i++) {
        this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, graphicButtonPos, this->_graphicsLibs[i], ASCII(' ', Color(0, 162, 255)), "Button1")}));
        graphicButtonPos.second += 60;
    }
    for (size_t i = 0; i < this->_gameLibs.size(); i++) {
        this->_map[1].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0, gameButtonPos, this->_gameLibs[i], ASCII(' ', Color(239, 255, 0)), "Button2")}));
        gameButtonPos.second += 60;
    }
    this->_isInitialized = true;
}

void Menu::setGraphicsLibs(std::map<int, std::string> graphicsLibs) {
    this->_graphicsLibs = graphicsLibs;
}

void Menu::setGameLibs(std::map<int, std::string> gameLibs) {
    size_t i = 0;
    size_t toErase = 0;

    this->_gameLibs = gameLibs;
    for (auto& game : this->_gameLibs) {
        if (game.second == "lib/arcade_menu.so" || game.second == "defaultMenu")
            toErase = i;
        i++;
    }
    this->_gameLibs.erase(toErase);
}

std::vector<std::vector<Tiles>> Menu::getMap() const {
    return this->_map;
}
