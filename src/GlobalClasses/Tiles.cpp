/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Tiles
*/

#include "../../include/GlobalClasses/Tiles.hpp"

Tiles::Tiles(std::vector<std::shared_ptr<AEntities>> entities, int size) :
    _entities(entities),
    _size(size) {}

std::vector<std::shared_ptr<AEntities>> Tiles::getEntities() const {
    return this->_entities;
}

void Tiles::setEntities(std::vector<std::shared_ptr<AEntities>> entities) {
    this->_entities = entities;
}

int Tiles::getSize() const {
    return this->_size;
}

void Tiles::setSize(int size) {
    this->_size = size;
}
