/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/

#include "../../include/Games/AGameModule.hpp"

AGameModule::AGameModule(const std::string gameName) :
    _gameName(gameName) {}

int AGameModule::getScore() const
{
    return this->_score;
}

void AGameModule::setScore(int score) {
    this->_score = score;
}

std::map<std::string, int> AGameModule::getHighScore() const {
    return this->_highScores;
}

void AGameModule::setHighScore(int score, std::string playerName) {
    this->_highScores[playerName] = score;
}

GameStatus AGameModule::getGameStatus() const {
    return this->_gameStatus;
}

void AGameModule::setGameStatus(GameStatus status) {
    this->_gameStatus = status;
}

std::vector<std::vector<Tiles>> AGameModule::getMap() const {
    return this->_map;
}

std::string AGameModule::getPlayerName() const {
    return this->_playerName;
}

void AGameModule::setPlayerName(std::string name) {
    this->_playerName = name;
}

std::string AGameModule::getGameName() const {
    return this->_gameName;
}

void AGameModule::setGameName(std::string name) {
    this->_gameName = name;
}
