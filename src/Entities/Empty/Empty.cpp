/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Empty
*/

#include "../../../include/Entities/Empty/Empty.hpp"

Empty::Empty(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType Empty::getType() const
{
    return EntityType::EMPTY;
}
