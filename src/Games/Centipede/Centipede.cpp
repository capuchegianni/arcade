/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Centipede
*/

#include "../../../include/Games/Centipede/Centipede.hpp"

Centipede::Centipede() :
    AGameModule("Centipede") {}

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Centipede>();
}

std::vector<std::shared_ptr<AEntities>> Centipede::initAllEntities() const {
    return std::vector<std::shared_ptr<AEntities>>();
}

void Centipede::catchInput(Input key) {
    (void)key;
}
