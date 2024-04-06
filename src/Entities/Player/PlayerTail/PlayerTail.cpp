/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerTail
*/

#include "../../../../include/Entities/Player/PlayerTail/PlayerTail.hpp"

PlayerTail::PlayerTail(std::pair<int, int> pos)
{
    this->_pos = pos;
}

PlayerTail::PlayerTail(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerTail::getType() const
{
    return EntityType::PLAYER;
}

void PlayerTail::setLastPos(std::pair<int, int> pos)
{
    this->_lastPos = pos;
}

std::pair<int, int> PlayerTail::getLastPos() const
{
    return this->_lastPos;
}
