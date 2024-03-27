/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AEntities
*/

#include "../../include/Entities/AEntities.hpp"

AEntities::AEntities(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii) :
    _speed(speed),
    _pos(pos),
    _texturePath(texturePath),
    _ascii(ascii) {}

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

std::pair<std::string, ASCII> AEntities::imageToDisplay() const {
    return {this->_texturePath, this->_ascii};
}
