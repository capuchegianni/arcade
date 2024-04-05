/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#include "../../../include/Entities/Wall/Wall.hpp"

Wall::Wall(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Wall::getType() const
{
    return EntityType::BLOCK;
}
