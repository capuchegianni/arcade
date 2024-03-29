/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Empty
*/

#include "../../../include/Entities/Empty/Empty.hpp"

Empty::Empty(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii)
    : AEntities(speed, pos, texturePath, ascii)
{
}

EntityType Empty::getType() const
{
    return EntityType::EMPTY;
}

std::pair<std::string, ASCII> Empty::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
