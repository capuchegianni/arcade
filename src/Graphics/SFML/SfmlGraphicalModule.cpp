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
    this->_window.create(sf::VideoMode(size[0], size[1]), name, sf::Style::Close);
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
    if (map.empty())
        return;
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i].empty())
            continue;
        for (int j = map[i].size() - 1; j >= 0; j--) {
            Tiles tile = map[i][j];

            if (tile.getEntities().empty())
                continue;
            for (int k = tile.getEntities().size() - 1; k >= 0; k--) {
                std::shared_ptr<AEntities> entity = tile.getEntities()[k];
                sf::Sprite sprite = this->_assets[entity->getName()].first;
                sf::Texture texture = this->_assets[entity->getName()].second;

                sprite.setTexture(texture);
                sprite.setPosition(j * 26, i * 26);
                sprite.setScale(0.1, 0.1);
                this->_window.draw(sprite);
            }
        }
    }
}

void SfmlGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    for (int i = entities.size() - 1; i >= 0; i--) {
        std::shared_ptr<AEntities> entity = entities[i];
        sf::Sprite sprite;
        sf::Texture texture;
        Color color = entity->imageToDisplay().second.getColor();

        if (!texture.loadFromFile(entity->imageToDisplay().first))
            throw SfmlError("Error loading image path");
        this->_assets[entity->getName()] = {sprite, texture};
    }
}
