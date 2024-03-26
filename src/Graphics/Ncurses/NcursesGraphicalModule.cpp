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
    return std::make_shared<NcursesGraphicalModule>();
}

void NcursesGraphicalModule::initWindow(const std::string& name, const std::vector<int>& size) {
    (void)name;
    (void)size;
    return;
}

void NcursesGraphicalModule::destroyWindow() {
    return;
}

void NcursesGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    (void)name;
    (void)size;
    return;
}

void NcursesGraphicalModule::setWindowSize(const std::vector<int> &size) {
    (void)size;
    return;
}

void NcursesGraphicalModule::setWindowTitle(const std::string &title) {
    (void)title;
    return;
}

void NcursesGraphicalModule::displayWindow() {
    return;
}

bool NcursesGraphicalModule::isWindowOpen() {
    return true;
}

Input NcursesGraphicalModule::parseKeyboard() {
    return NONE;
}

void NcursesGraphicalModule::showMap(std::vector<std::vector<Tiles>> &map) {
    (void)map;
    return;
}
