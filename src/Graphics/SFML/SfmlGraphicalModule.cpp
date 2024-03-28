/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#include "../../../include/Graphics/SFML/SfmlGraphicalModule.hpp"

SfmlGraphicalModule::SfmlGraphicalModule() :
    AGraphicalModule("SFML") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib()
{
    return std::make_shared<SfmlGraphicalModule>();
}

void SfmlGraphicalModule::destroyWindow()
{
    this->_window.close();
    this->_isOpen = false;
}

void SfmlGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size)
{
    this->_window.create(sf::VideoMode(size[0], size[1]), name);
    this->_isOpen = true;
    this->setWindowTitle(name);
    this->setWindowSize(size);
}

void SfmlGraphicalModule::setWindowSize(const std::vector<int> &size)
{
    this->_window.setSize(sf::Vector2u(size[0], size[1]));
}

void SfmlGraphicalModule::setWindowTitle(const std::string &title)
{
    this->_window.setTitle(title);
}

void SfmlGraphicalModule::displayWindow()
{
    this->_window.display();
}

bool SfmlGraphicalModule::isWindowOpen()
{
    return this->_window.isOpen();
}

Input SfmlGraphicalModule::parseKeyboard() {
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            return ESC;
        if (this->_event.type == sf::Event::KeyPressed) {
            if (this->_event.key.code == sf::Keyboard::Escape)
                return ESC;
            if (this->_event.key.code == sf::Keyboard::Up)
                return CHANGE_GAME;
            if (this->_event.key.code == sf::Keyboard::Right)
                return CHANGE_LIB;
            if (this->_event.key.code == sf::Keyboard::Tab)
                return MENU;
            if (this->_event.key.code == sf::Keyboard::Space)
                return SPACE;
            if (this->_event.key.code == sf::Keyboard::Z)
                return UP;
            if (this->_event.key.code == sf::Keyboard::Q)
                return LEFT;
            if (this->_event.key.code == sf::Keyboard::S)
                return DOWN;
            if (this->_event.key.code == sf::Keyboard::D)
                return RIGHT;
            if (this->_event.key.code == sf::Keyboard::R)
                return RELOAD;
        }
    }
    return NONE;
}

void SfmlGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map)
{
    (void)map;
    return;
}

void SfmlGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    (void)entities;
    return;
}
