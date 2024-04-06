/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerBody
*/

#include "../../../../include/Entities/Player/PlayerBody/PlayerBody.hpp"

PlayerBody::PlayerBody(std::pair<int, int> pos)
{
    this->_pos = pos;
}

PlayerBody::PlayerBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerBody::getType() const
{
    return EntityType::PLAYER;
}
