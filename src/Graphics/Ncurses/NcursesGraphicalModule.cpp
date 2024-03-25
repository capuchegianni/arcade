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

void NcursesGraphicalModule::clearWindow(Color color) {
    (void)color;
    return;
}

bool NcursesGraphicalModule::isWindowOpen() {
    return true;
}

void NcursesGraphicalModule::parseKeyboard() {
    return;
}

void NcursesGraphicalModule::displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color) {
    (void)text;
    (void)pos;
    (void)size;
    (void)color;
    return;
}

std::any NcursesGraphicalModule::initText(const std::string& text) {
    (void)text;
    return std::any();
}

void NcursesGraphicalModule::setTextColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextFont(const std::any& text, const std::string& path) {
    (void)text;
    (void)path;
    return;
}

void NcursesGraphicalModule::setTextOutline(const std::any& text, const bool& hasOutline) {
    (void)text;
    (void)hasOutline;
    return;
}

void NcursesGraphicalModule::setTextOutlineThickness(const std::any& text, const int& thickness) {
    (void)text;
    (void)thickness;
    return;
}

void NcursesGraphicalModule::setTextOutlineColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextFillColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void NcursesGraphicalModule::setTextSize(const std::any& text, const int& size) {
    (void)text;
    (void)size;
    return;
}

void NcursesGraphicalModule::setTextPosition(const std::any& text, const std::vector<int>& pos) {
    (void)text;
    (void)pos;
    return;
}

void NcursesGraphicalModule::setTextOrigin(const std::any& text, const std::vector<int>& origin) {
    (void)text;
    (void)origin;
    return;
}

void NcursesGraphicalModule::drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color) {
    (void)size;
    (void)pos;
    (void)color;
    return;
}

void NcursesGraphicalModule::setRectangleColor(std::any& rect, const Color& color) {
    (void)rect;
    (void)color;
    return;
}

void NcursesGraphicalModule::setRectangleSize(std::any& rect, const std::vector<int>& size) {
    (void)rect;
    (void)size;
    return;
}

void NcursesGraphicalModule::setRectanglePosition(std::any& rect, const std::vector<int>& pos) {
    (void)rect;
    (void)pos;
    return;
}

void NcursesGraphicalModule::drawCircle(const int& rad, const std::vector<int>& pos, const Color& color) {
    (void)rad;
    (void)pos;
    (void)color;
    return;
}

void NcursesGraphicalModule::setCircleColor(std::any& circle, const Color& color) {
    (void)circle;
    (void)color;
    return;
}

void NcursesGraphicalModule::setCircleRadius(std::any& circle, const int& rad) {
    (void)circle;
    (void)rad;
    return;
}

void NcursesGraphicalModule::setCirclePosition(std::any& circle, const std::vector<int>& pos) {
    (void)circle;
    (void)pos;
    return;
}

void NcursesGraphicalModule::displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color) {
    (void)path;
    (void)pos;
    (void)scale;
    (void)rotation;
    (void)origin;
    (void)color;
    return;
}

std::any NcursesGraphicalModule::initSprite(const std::string& path) {
    (void)path;
    return std::any();
}

void NcursesGraphicalModule::setSpriteTexture(std::any sprite, const std::string& path) {
    (void)sprite;
    (void)path;
    return;
}

void NcursesGraphicalModule::setSpritePosition(std::any sprite, const std::vector<int>& pos) {
    (void)sprite;
    (void)pos;
    return;
}

void NcursesGraphicalModule::setSpriteScale(std::any sprite, const std::vector<float>& scale) {
    (void)sprite;
    (void)scale;
    return;
}

void NcursesGraphicalModule::setSpriteRotation(std::any sprite, const float& rotation) {
    (void)sprite;
    (void)rotation;
    return;
}
