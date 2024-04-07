/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerHead
*/

#include "../../../../include/Entities/Player/PlayerHead/PlayerHead.hpp"

PlayerHead::PlayerHead(std::pair<int, int> pos)
{
    this->_pos = pos;
}

PlayerHead::PlayerHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerHead::getType() const
{
    return EntityType::PLAYER;
}