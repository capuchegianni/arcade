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

bool SfmlGraphicalModule::isWindowOpen() {
    return this->_window.isOpen();
}

Input SfmlGraphicalModule::parseKeyboard() {
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed || this->_event.key.code == sf::Keyboard::Escape)
            this->destroyWindow();
    }
    return NONE;
}

void SfmlGraphicalModule::showMap(std::vector<std::vector<Tiles>> &map) {
    (void)map;
    return;
}
