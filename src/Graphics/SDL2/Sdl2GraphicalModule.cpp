/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl2GraphicalModule
*/

#include "../../../include/Graphics/SDL2/Sdl2GraphicalModule.hpp"

Sdl2GraphicalModule::Sdl2GraphicalModule() :
    AGraphicalModule("SDL2") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib() {
    return std::make_unique<Sdl2GraphicalModule>();
}

void Sdl2GraphicalModule::initWindow() {
    return;
}

void Sdl2GraphicalModule::destroyWindow() {
    return;
}
