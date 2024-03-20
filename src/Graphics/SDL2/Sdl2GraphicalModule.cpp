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

void Sdl2GraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    (void)name;
    (void)size;
    return;
}

void Sdl2GraphicalModule::setWindowSize(const std::vector<int> &size) {
    (void)size;
    return;
}

void Sdl2GraphicalModule::setWindowTitle(const std::string &title) {
    (void)title;
    return;
}

void Sdl2GraphicalModule::displayWindow() {
    return;
}

void Sdl2GraphicalModule::clearWindow(Color color) {
    (void)color;
    return;
}

bool Sdl2GraphicalModule::isWindowOpen() {
    return true;
}

void Sdl2GraphicalModule::pollEvents() {
    return;
}

void Sdl2GraphicalModule::displayText(const std::string &text) {
    (void)text;
    return;
}

std::any Sdl2GraphicalModule::initText() {
    return std::any();
}

void Sdl2GraphicalModule::setTextColor(const Color& color) {
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFont(const std::string& path) {
    (void)path;
    return;
}

void Sdl2GraphicalModule::setTextOutline(const bool& hasOutline) {
    (void)hasOutline;
    return;
}

void Sdl2GraphicalModule::setTextOutlineThickness(const int& thickness) {
    (void)thickness;
    return;
}

void Sdl2GraphicalModule::setTextOutlineColor(const Color& color) {
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFillColor(const Color& color) {
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextSize(const int& size) {
    (void)size;
    return;
}

void Sdl2GraphicalModule::setTextPosition(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}

void Sdl2GraphicalModule::setTextOrigin(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}
