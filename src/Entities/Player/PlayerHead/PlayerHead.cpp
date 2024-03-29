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

PlayerHead::PlayerHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii)
    : AEntities(speed, pos, texturePath, ascii)
{
}

EntityType PlayerHead::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHead::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
