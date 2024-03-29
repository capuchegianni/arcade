/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#include "../../../include/Graphics/SFML/SfmlGraphicalModule.hpp"
#include "../../../include/Entities/AEntities.hpp"

SfmlGraphicalModule::SfmlGraphicalModule() :
    AGraphicalModule("SFML") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib()
{
    return std::make_shared<SfmlGraphicalModule>();
}

void SfmlGraphicalModule::destroyWindow() {
    if (this->_isOpen)
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

std::unordered_map<sf::Keyboard::Key, Input> keymap = {
    {sf::Keyboard::Escape, ESC},
    {sf::Keyboard::Up, CHANGE_GAME},
    {sf::Keyboard::Right, CHANGE_LIB},
    {sf::Keyboard::Tab, MENU},
    {sf::Keyboard::Space, SPACE},
    {sf::Keyboard::Z, UP},
    {sf::Keyboard::Q, LEFT},
    {sf::Keyboard::S, DOWN},
    {sf::Keyboard::D, RIGHT},
    {sf::Keyboard::R, RELOAD}
};

Input SfmlGraphicalModule::parseKeyboard() {
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            return ESC;
        if (this->_event.type == sf::Event::KeyPressed) {
            auto it = keymap.find(this->_event.key.code);
            if (it != keymap.end())
                return it->second;
        }
    }
    return NONE;
}

void SfmlGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map)
{
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            Tiles tile = map[i][j].getEntities();

            sf::Sprite sprite = this->_assets[tile.getEntities()[tile.getEntities().size()]->getName()];
            sprite.setPosition(j, i);

            this->_window.draw(sprite);
        }
    }
}

void SfmlGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    for (int i = entities.size() - 1; i >= 0; i--) {
        std::shared_ptr<AEntities> entity = entities[i];
        sf::Sprite sprite;
        sf::Texture texture;
        ASCII color = entity->imageToDisplay().second;

        if (!texture.loadFromFile(entity->imageToDisplay().first)) {
            std::cerr << "Error loading texture" << std::endl;
            return;
        }

        sprite.setTexture(texture);
        sprite.setColor(sf::Color(color.getAscii(), color.getAscii(), color.getAscii(), color.getAscii()));
        this->_assets[entity->getName()] = sprite;
    }
}
