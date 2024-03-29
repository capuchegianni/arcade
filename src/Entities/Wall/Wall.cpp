/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#include "../../../include/Entities/Wall/Wall.hpp"

Wall::Wall(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii)
    : AEntities(speed, pos, texturePath, ascii)
{
}

EntityType Wall::getType() const
{
    return EntityType::WALL;
}

std::pair<std::string, ASCII> Wall::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
