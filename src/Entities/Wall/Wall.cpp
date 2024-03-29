/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#include "../../../include/Entities/Wall/Wall.hpp"

EntityType Wall::getType() const
{
    return EntityType::WALL;
}

std::pair<std::string, ASCII> Wall::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
