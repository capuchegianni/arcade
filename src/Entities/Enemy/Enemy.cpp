/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enemy
*/

#include "../../../include/Entities/Enemy/Enemy.hpp"

EntityType Enemy::getType() const
{
    return EntityType::ENEMY;
}

std::pair<std::string, ASCII> Enemy::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
