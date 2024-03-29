/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Empty
*/

#include "../../../include/Entities/Empty/EmptyEntity.hpp"

EntityType EmptyEntity::getType() const
{
    return EntityType::EMPTY;
}

std::pair<std::string, ASCII> EmptyEntity::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
