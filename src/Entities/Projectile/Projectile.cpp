/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Projectile
*/

#include "../../../include/Entities/Projectile/Projectile.hpp"

Projectile::Projectile(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Projectile::getType() const
{
    return EntityType::PROJECTILE;
}

std::pair<std::string, ASCII> Projectile::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
