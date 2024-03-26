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
    return std::make_shared<SfmlGraphicalModule>();
}

void SfmlGraphicalModule::initWindow(const std::string& name, const std::vector<int>& size) {
    this->_window.create(sf::VideoMode(size[0], size[1]), name);
    this->_isOpen = true;
}

void SfmlGraphicalModule::destroyWindow() {
    this->_window.close();
    this->_isOpen = false;
}

void SfmlGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    this->initWindow(name, size);
    this->setWindowTitle(name);
    this->setWindowSize(size);
}

void SfmlGraphicalModule::setWindowSize(const std::vector<int> &size) {
    this->_window.setSize(sf::Vector2u(size[0], size[1]));
}

void SfmlGraphicalModule::setWindowTitle(const std::string &title) {
    this->_window.setTitle(title);
}

void SfmlGraphicalModule::displayWindow() {
    this->_window.display();
}

void SfmlGraphicalModule::clearWindow(Color color) {
    this->_window.clear(sf::Color(color.r, color.g, color.b, color.a));
}

bool SfmlGraphicalModule::isWindowOpen() {
    return this->_window.isOpen();
}

void SfmlGraphicalModule::parseKeyboard() {
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed || this->_event.key.code == sf::Keyboard::Escape)
            this->destroyWindow();
    }
}

void SfmlGraphicalModule::displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color) {
    (void)text;
    (void)pos;
    (void)size;
    (void)color;
    return;
}

std::any SfmlGraphicalModule::initText(const std::string& text) {
    (void)text;
    return std::any();
}

void SfmlGraphicalModule::setTextColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextFont(const std::any& text, const std::string& path) {
    (void)text;
    (void)path;
    return;
}

void SfmlGraphicalModule::setTextOutline(const std::any& text, const bool& hasOutline) {
    (void)text;
    (void)hasOutline;
    return;
}

void SfmlGraphicalModule::setTextOutlineThickness(const std::any& text, const int& thickness) {
    (void)text;
    (void)thickness;
    return;
}

void SfmlGraphicalModule::setTextOutlineColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextFillColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextSize(const std::any& text, const int& size) {
    (void)text;
    (void)size;
    return;
}

void SfmlGraphicalModule::setTextPosition(const std::any& text, const std::vector<int>& pos) {
    (void)text;
    (void)pos;
    return;
}

void SfmlGraphicalModule::setTextOrigin(const std::any& text, const std::vector<int>& origin) {
    (void)text;
    (void)origin;
    return;
}

void SfmlGraphicalModule::drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color) {
    (void)size;
    (void)pos;
    (void)color;
    return;
}

void SfmlGraphicalModule::setRectangleColor(std::any& rect, const Color& color) {
    (void)rect;
    (void)color;
    return;
}

void SfmlGraphicalModule::setRectangleSize(std::any& rect, const std::vector<int>& size) {
    (void)rect;
    (void)size;
    return;
}

void SfmlGraphicalModule::setRectanglePosition(std::any& rect, const std::vector<int>& pos) {
    (void)rect;
    (void)pos;
    return;
}

void SfmlGraphicalModule::drawCircle(const int& rad, const std::vector<int>& pos, const Color& color) {
    (void)rad;
    (void)pos;
    (void)color;
    return;
}

void SfmlGraphicalModule::setCircleColor(std::any& circle, const Color& color) {
    (void)circle;
    (void)color;
    return;
}

void SfmlGraphicalModule::setCircleRadius(std::any& circle, const int& rad) {
    (void)circle;
    (void)rad;
    return;
}

void SfmlGraphicalModule::setCirclePosition(std::any& circle, const std::vector<int>& pos) {
    (void)circle;
    (void)pos;
    return;
}

void SfmlGraphicalModule::displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color) {
    (void)path;
    (void)pos;
    (void)scale;
    (void)rotation;
    (void)origin;
    (void)color;
    return;
}

std::any SfmlGraphicalModule::initSprite(const std::string& path) {
    (void)path;
    return std::any();
}

void SfmlGraphicalModule::setSpriteTexture(std::any sprite, const std::string& path) {
    (void)sprite;
    (void)path;
    return;
}

void SfmlGraphicalModule::setSpritePosition(std::any sprite, const std::vector<int>& pos) {
    (void)sprite;
    (void)pos;
    return;
}

void SfmlGraphicalModule::setSpriteScale(std::any sprite, const std::vector<float>& scale) {
    (void)sprite;
    (void)scale;
    return;
}

void SfmlGraphicalModule::setSpriteRotation(std::any sprite, const float& rotation) {
    (void)sprite;
    (void)rotation;
    return;
}
