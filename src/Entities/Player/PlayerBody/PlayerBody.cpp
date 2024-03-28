/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerBody
*/

#include "../../../../include/Entities/Player/PlayerBody/PlayerBody.hpp"

EntityType PlayerBody::getType() const
{
    return EntityType::PLAYER_BODY;
}

std::pair<std::string, ASCII> PlayerBody::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
