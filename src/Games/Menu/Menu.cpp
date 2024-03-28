/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "../../../include/Games/Menu/Menu.hpp"

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Menu>();
}

Menu::Menu() :
    AGameModule("Menu") {}

void Menu::catchInput(Input input) {
    return;
}

std::vector<std::shared_ptr<AEntities>> Menu::initAllEntities() const {
    return std::vector<std::shared_ptr<AEntities>>();
}
