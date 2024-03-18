/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesGraphicalModule
*/

#include "../../../include/Graphics/Ncurses/NcursesGraphicalModule.hpp"

NcursesGraphicalModule::NcursesGraphicalModule() :
    AGraphicalModule("Ncurses") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib() {
    return std::make_unique<NcursesGraphicalModule>();
}

void NcursesGraphicalModule::initWindow() {
    return;
}

void NcursesGraphicalModule::destroyWindow() {
    return;
}
