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

PlayerBody::PlayerBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii)
    : AEntities(speed, pos, texturePath, ascii)
{
}

EntityType PlayerBody::getType() const
{
    return EntityType::PLAYER_BODY;
}

std::pair<std::string, ASCII> PlayerBody::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
