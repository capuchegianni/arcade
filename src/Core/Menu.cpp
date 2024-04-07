/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include "../../include/Core/Menu.hpp"

Menu::Menu() {
    this->_map.resize(4);
}

std::vector<std::shared_ptr<AEntities>> Menu::initAllEntities() const {
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_lib.jpg", ASCII(' ', Color(0, 255, 0)), "Button1"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/button_game.jpg", ASCII(' ', Color(0, 0, 255)), "Button2"));
    entities.push_back(std::make_shared<Background>(0, std::make_pair(0, 0), "assets/images/dinosaure.png", ASCII(' ', Color()), "Background"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/arrow_left.png", ASCII(' ', Color()), "Arrow"));
    entities.push_back(std::make_shared<Button>(0, std::make_pair(0, 0), "assets/images/placeholder.png", ASCII(' ', Color()), "Placeholder"));
    std::cout << "Menu entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

std::unordered_map<Input, std::string> keymap = {
    {SPACE, " "},
    {UP, "z"},
    {LEFT, "q"},
    {DOWN, "s"},
    {RIGHT, "d"},
    {RELOAD, "r"},
    {A, "a"},
    {B, "b"},
    {C, "c"},
    {E, "e"},
    {F, "f"},
    {G, "g"},
    {H, "h"},
    {I, "i"},
    {J, "j"},
    {K, "k"},
    {L, "l"},
    {M, "m"},
    {N, "n"},
    {O, "o"},
    {P, "p"},
    {T, "t"},
    {U, "u"},
    {V, "v"},
    {W, "w"},
    {X, "x"},
    {Y, "y"},
};

int Menu::catchInput(Input input) {
    int gameNumber = this->_gameLibs.size() - 1;
    auto it = keymap.find(input);

    this->initMap();
    if (input == CHANGE_GAME)
        this->_selectedGame = (this->_selectedGame == 0 ? gameNumber : this->_selectedGame - 1);
    if (input == ENTER)
        return this->_selectedGame;
    if (input == DELETE)
        this->_player = this->_player.substr(0, this->_player.size() - 1);
    if (it != keymap.end()) {
        this->_player += it->second;
    }
    this->updateMap();
    return -1;
}

static std::string getGameName(std::string gamePath) {
    std::string prefix = "lib/arcade_";
    std::string suffix = ".so";
    std::string gameName = gamePath;

    if (gameName.rfind(prefix, 0) == 0)
        gameName.erase(0, prefix.length());
    if (gameName.rfind(suffix, gameName.length() - suffix.length()) != std::string::npos)
        gameName.erase(gameName.length() - suffix.length(), suffix.length());

    return gameName;
}

void Menu::updateMap() {
    std::string nameToDisplay = this->_player != "" ? this->_player : "Enter your name";
    std::string gameName = getGameName(this->_gameLibs[this->_selectedGame]);
    std::string scoreToDisplay = this->_scores[{gameName, this->_player}] != "" ? "High score: " + this->_scores[{gameName, this->_player}] : "No high score yet";

    this->_map[0].clear();
    this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0.7, std::make_pair(20, 10), nameToDisplay, ASCII(' ', Color()), "Placeholder")}));
    this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0.7, std::make_pair(340, 10), scoreToDisplay, ASCII(' ', Color()), "Placeholder")}));
    this->_map[3].clear();
    for (size_t i = 0; i < this->_gameLibs.size(); i++) {
        if (static_cast<int>(i) == this->_selectedGame)
            this->_map[3].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(1.2, std::make_pair(450, 60 + i * 60), "<", ASCII(' ', Color()), "Arrow")}));
        else
            this->_map[3].push_back(Tiles({}));
    }
}

void Menu::initMap() {
    if (this->_isInitialized)
        return;

    std::pair<int, int> graphicButtonPos = std::make_pair(50, 60);
    std::pair<int, int> gameButtonPos = std::make_pair(270, 60);

    this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0.7, std::make_pair(20, 10), this->getPlayer(), ASCII(' ', Color()), "Placeholder")}));
    this->_map[0].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(0.7, std::make_pair(340, 10), this->getPlayer(), ASCII(' ', Color()), "Placeholder")}));
    for (size_t i = 0; i < this->_graphicsLibs.size(); i++) {
        this->_map[1].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(1.2, graphicButtonPos, this->_graphicsLibs[i], ASCII(' ', Color(0, 162, 255)), "Button1")}));
        graphicButtonPos.second += 60;
    }
    for (size_t i = 0; i < this->_gameLibs.size(); i++) {
        this->_map[2].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Button>(1.2, gameButtonPos, this->_gameLibs[i], ASCII(' ', Color(239, 255, 0)), "Button2")}));
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

void Menu::setPlayer(const std::string& player) {
    this->_player = player;
}

std::string Menu::getPlayer() const {
    return this->_player;
}

void Menu::getScoreFileInfos() {
    std::ifstream file("assets/scores.txt");
    std::string line;

    if (!file.is_open())
        return;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string gameName, playerName, scoreStr;
        std::getline(ss, gameName, ':');
        std::getline(ss, playerName, ':');
        std::getline(ss, scoreStr, ':');
        this->_scores[std::make_pair(gameName, playerName)] = scoreStr;
    }
    file.close();
}
