/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerHead
*/

#include "../../../include/Entities/PlayerHead/PlayerHead.hpp"

EntityType PlayerHead::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHead::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
