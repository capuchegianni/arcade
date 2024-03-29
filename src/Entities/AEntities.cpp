/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AEntities
*/

#include "../../include/Entities/AEntities.hpp"

AEntities::AEntities(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name) :
    _speed(speed),
    _pos(pos),
    _texturePath(texturePath),
    _ascii(ascii),
    _name(name) {}

double AEntities::getSpeed() const {
    return this->_speed;
}

void AEntities::setSpeed(double speed) {
    this->_speed = speed;
}

std::pair<int, int> AEntities::getPos() const {
    return this->_pos;
}

void AEntities::setPos(std::pair<int, int> pos) {
    this->_pos = pos;
}

std::string AEntities::getName() const {
    return this->_name;
}

void AEntities::setName(std::string name) {
    this->_name = name;
}
