/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enemy
*/

#include "../../../include/Entities/Enemy/Enemy.hpp"

Enemy::Enemy(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii)
    : AEntities(speed, pos, texturePath, ascii)
{
}

EntityType Enemy::getType() const
{
    return EntityType::ENEMY;
}

std::pair<std::string, ASCII> Enemy::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
