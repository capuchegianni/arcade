/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Tiles
*/

#include "../../include/GlobalClasses.hpp"

bool Tiles::isType(TilesType type) {
    return this->_type == type;
}

void Tiles::setType(TilesType type) {
    this->_type = type;
}

TilesType Tiles::getType() const {
    return this->_type;
}
