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
    return std::make_shared<Sdl2GraphicalModule>();
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

void Sdl2GraphicalModule::parseKeyboard() {
    return;
}

void Sdl2GraphicalModule::displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color) {
    (void)text;
    (void)pos;
    (void)size;
    (void)color;
    return;
}

std::any Sdl2GraphicalModule::initText(const std::string& text) {
    (void)text;
    return std::any();
}

void Sdl2GraphicalModule::setTextColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFont(const std::any& text, const std::string& path) {
    (void)text;
    (void)path;
    return;
}

void Sdl2GraphicalModule::setTextOutline(const std::any& text, const bool& hasOutline) {
    (void)text;
    (void)hasOutline;
    return;
}

void Sdl2GraphicalModule::setTextOutlineThickness(const std::any& text, const int& thickness) {
    (void)text;
    (void)thickness;
    return;
}

void Sdl2GraphicalModule::setTextOutlineColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFillColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextSize(const std::any& text, const int& size) {
    (void)text;
    (void)size;
    return;
}

void Sdl2GraphicalModule::setTextPosition(const std::any& text, const std::vector<int>& pos) {
    (void)text;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::setTextOrigin(const std::any& text, const std::vector<int>& origin) {
    (void)text;
    (void)origin;
    return;
}

void Sdl2GraphicalModule::drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color) {
    (void)size;
    (void)pos;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setRectangleColor(std::any& rect, const Color& color) {
    (void)rect;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setRectangleSize(std::any& rect, const std::vector<int>& size) {
    (void)rect;
    (void)size;
    return;
}

void Sdl2GraphicalModule::setRectanglePosition(std::any& rect, const std::vector<int>& pos) {
    (void)rect;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::drawCircle(const int& rad, const std::vector<int>& pos, const Color& color) {
    (void)rad;
    (void)pos;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setCircleColor(std::any& circle, const Color& color) {
    (void)circle;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setCircleRadius(std::any& circle, const int& rad) {
    (void)circle;
    (void)rad;
    return;
}

void Sdl2GraphicalModule::setCirclePosition(std::any& circle, const std::vector<int>& pos) {
    (void)circle;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color) {
    (void)path;
    (void)pos;
    (void)scale;
    (void)rotation;
    (void)origin;
    (void)color;
    return;
}

std::any Sdl2GraphicalModule::initSprite(const std::string& path) {
    (void)path;
    return std::any();
}

void Sdl2GraphicalModule::setSpriteTexture(std::any sprite, const std::string& path) {
    (void)sprite;
    (void)path;
    return;
}

void Sdl2GraphicalModule::setSpritePosition(std::any sprite, const std::vector<int>& pos) {
    (void)sprite;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::setSpriteScale(std::any sprite, const std::vector<float>& scale) {
    (void)sprite;
    (void)scale;
    return;
}

void Sdl2GraphicalModule::setSpriteRotation(std::any sprite, const float& rotation) {
    (void)sprite;
    (void)rotation;
    return;
}
