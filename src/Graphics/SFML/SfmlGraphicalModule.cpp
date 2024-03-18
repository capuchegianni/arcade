/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#include "../../../include/Graphics/SFML/SfmlGraphicalModule.hpp"

SfmlGraphicalModule::SfmlGraphicalModule() :
    AGraphicalModule("SFML") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib() {
    return std::make_unique<SfmlGraphicalModule>();
}

void SfmlGraphicalModule::initWindow() {
    return;
}

void SfmlGraphicalModule::destroyWindow() {
    return;
}
