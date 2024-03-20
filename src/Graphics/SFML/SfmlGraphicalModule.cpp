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
    this->_window.create(sf::VideoMode(800, 600), "SFML window");
}

void SfmlGraphicalModule::destroyWindow() {
    this->_window.close();
}

void SfmlGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    this->initWindow();
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

void SfmlGraphicalModule::pollEvents() {
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed || this->_event.key.code == sf::Keyboard::Escape)
            this->destroyWindow();
    }
}

void SfmlGraphicalModule::displayText(const std::string &text) {
    (void)text;
    return;
}

std::any SfmlGraphicalModule::initText() {
    return std::any();
}

void SfmlGraphicalModule::setTextColor(const Color& color) {
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextFont(const std::string& path) {
    (void)path;
    return;
}

void SfmlGraphicalModule::setTextOutline(const bool& hasOutline) {
    (void)hasOutline;
    return;
}

void SfmlGraphicalModule::setTextOutlineThickness(const int& thickness) {
    (void)thickness;
    return;
}

void SfmlGraphicalModule::setTextOutlineColor(const Color& color) {
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextFillColor(const Color& color) {
    (void)color;
    return;
}

void SfmlGraphicalModule::setTextSize(const int& size) {
    (void)size;
    return;
}

void SfmlGraphicalModule::setTextPosition(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}

void SfmlGraphicalModule::setTextOrigin(const int& x, const int& y) {
    (void)x;
    (void)y;
    return;
}
