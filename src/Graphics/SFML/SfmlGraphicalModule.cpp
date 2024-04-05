/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#include "../../../include/Graphics/SFML/SfmlGraphicalModule.hpp"
#include "../../../include/Entities/AEntities.hpp"
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
    {sf::Keyboard::R, RELOAD},
    {sf::Keyboard::Enter, ENTER},
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

static void displayBackground(const std::map<std::string, std::pair<sf::Sprite, sf::Texture>> &assets, sf::RenderWindow &window)
{
    if (assets.find("Background") == assets.end())
        return;
    sf::Sprite sprite = assets.at("Background").first;
    sf::Texture texture = assets.at("Background").second;
    float scaleFactorX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleFactorY = static_cast<float>(window.getSize().y) / texture.getSize().y;

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(scaleFactorX, scaleFactorY);
    window.draw(sprite);
}

static void displayButton(const std::shared_ptr<AEntities>& entity, sf::RenderWindow& window, const std::map<std::string, std::pair<sf::Sprite, sf::Texture>>& assets) {
    if (assets.empty() || assets.find(entity->getName()) == assets.end())
        return;
    sf::Sprite sprite = assets.at(entity->getName()).first;
    sf::Texture texture = assets.at(entity->getName()).second;
    std::string text = entity->imageToDisplay().first;
    sf::Text textToDisplay;
    sf::Font font;

    if (!font.loadFromFile("assets/fonts/arial/arial.ttf"))
        throw SfmlError("Error loading font path");
    textToDisplay.setFont(font);
    textToDisplay.setString(text);
    textToDisplay.setCharacterSize(15);
    textToDisplay.setFillColor(sf::Color::Black);
    textToDisplay.setPosition(entity->getPos().first + 15, entity->getPos().second + 8);

    sprite.setTexture(texture);
    sprite.setPosition(entity->getPos().first, entity->getPos().second);
    sprite.setScale(1.2, 1.2);
    window.draw(sprite);
    window.draw(textToDisplay);
}

void SfmlGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map)
{
    if (map.empty() || this->_assets.empty())
        return;
    this->_window.clear();
    displayBackground(this->_assets, this->_window);
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i].empty())
            continue;
        for (int j = map[i].size() - 1; j >= 0; j--) {
            Tiles tile = map[i][j];

            if (tile.getEntities().empty())
                continue;
            for (size_t k = 0; k < tile.getEntities().size(); k++) {
                std::shared_ptr<AEntities> entity = tile.getEntities()[k];
                if (entity->getType() == BUTTON) {
                    displayButton(entity, this->_window, this->_assets);
                    continue;
                }
                sf::Sprite sprite = this->_assets[entity->getName()].first;
                sf::Texture texture = this->_assets[entity->getName()].second;
                float scaleFactorX = static_cast<float>(this->_window.getSize().x) / (texture.getSize().x * map[0].size());
                float scaleFactorY = static_cast<float>(this->_window.getSize().y) / (texture.getSize().y * map.size());

                sprite.setTexture(texture);
                sprite.setPosition(j * texture.getSize().x * scaleFactorX, i * texture.getSize().y * scaleFactorY);
                sprite.setScale(scaleFactorX, scaleFactorY);
                this->_window.draw(sprite);
            }
        }
    }
}

void SfmlGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    this->_assets.clear();
    for (int i = entities.size() - 1; i >= 0; i--) {
        std::shared_ptr<AEntities> entity = entities[i];
        sf::Sprite sprite;
        sf::Texture texture;

        if (!texture.loadFromFile(entity->imageToDisplay().first))
            throw SfmlError("Error loading image path");
        this->_assets[entity->getName()] = {sprite, texture};
    }
}
