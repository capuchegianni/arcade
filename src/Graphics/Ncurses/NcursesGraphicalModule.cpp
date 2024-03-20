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

void NcursesGraphicalModule::clearWindow(Color color) {
    (void)color;
    return;
}

bool NcursesGraphicalModule::isWindowOpen() {
    return true;
}

void NcursesGraphicalModule::pollEvents() {
    return;
}

void NcursesGraphicalModule::displayText(const std::string &text) {
    (void)text;
    return;
}

std::any NcursesGraphicalModule::initText() {
    return std::any();
}

void NcursesGraphicalModule::setTextColor(const Color& color) {
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextFont(const std::string& path) {
    (void)path;
    return;
}

void NcursesGraphicalModule::setTextOutline(const bool& hasOutline) {
    (void)hasOutline;
    return;
}

void NcursesGraphicalModule::setTextOutlineThickness(const int& thickness) {
    (void)thickness;
    return;
}

void NcursesGraphicalModule::setTextOutlineColor(const Color& color) {
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextFillColor(const Color& color) {
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextSize(const int& size) {
    (void)size;
    return;
}

void NcursesGraphicalModule::setTextPosition(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}

void NcursesGraphicalModule::setTextOrigin(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}
