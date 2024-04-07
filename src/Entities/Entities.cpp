/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Entities
*/

#include "../../include/Entities/Entities.hpp"

Wall::Wall(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Wall::getType() const
{
    return EntityType::BLOCK;
}

Fruit::Fruit(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Fruit::getType() const
{
    return EntityType::ITEM;
}

Empty::Empty(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Empty::getType() const
{
    return EntityType::EMPTY;
}

Button::Button(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name) { }

EntityType Button::getType() const {
    return EntityType::BUTTON;
}

Background::Background(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name) { }

EntityType Background::getType() const {
    return EntityType::BACKGROUND;
}
