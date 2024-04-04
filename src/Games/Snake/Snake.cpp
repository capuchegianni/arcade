/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "../../../include/Games/Snake/Snake.hpp"

Snake::Snake() :
    AGameModule("Snake") {}

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Snake>();
}

std::vector<std::shared_ptr<AEntities>> Snake::initAllEntities() const {
    return std::vector<std::shared_ptr<AEntities>>();
}

void Snake::catchInput(Input key) {
    (void)key;
}
