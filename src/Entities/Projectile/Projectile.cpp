/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Projectile
*/

#include "../../../include/Entities/Projectile/Projectile.hpp"

EntityType Projectile::getType() const
{
    return EntityType::PROJECTILE;
}

std::pair<std::string, ASCII> Projectile::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
