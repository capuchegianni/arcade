/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Fruit
*/

#include "../../../include/Entities/Fruit/Fruit.hpp"

EntityType Fruit::getType() const
{
    return EntityType::FRUIT;
}

std::pair<std::string, ASCII> Fruit::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
