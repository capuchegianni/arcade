/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "../../../include/Games/Nibbler/Nibbler.hpp"

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Nibbler>();
}

Nibbler::Nibbler() :
    AGameModule("Nibbler") {}

void Nibbler::parseInput(Input input) {
    return;
}
