/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerTail
*/

#include "../../../../include/Entities/Player/PlayerTail/PlayerTail.hpp"

EntityType PlayerTail::getType() const
{
    return EntityType::PLAYER_TAIL;
}

std::pair<std::string, ASCII> PlayerTail::imageToDisplay() const
{
    return std::make_pair(_texturePath, _ascii);
}
