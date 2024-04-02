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
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHead::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}

PlayerHeadNorth::PlayerHeadNorth(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerHeadNorth::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHeadNorth::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}

PlayerHeadSouth::PlayerHeadSouth(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerHeadSouth::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHeadSouth::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}

PlayerHeadWest::PlayerHeadWest(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerHeadWest::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHeadWest::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}

PlayerHeadEast::PlayerHeadEast(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType PlayerHeadEast::getType() const
{
    return EntityType::PLAYER_HEAD;
}

std::pair<std::string, ASCII> PlayerHeadEast::imageToDisplay() const
{
    return {this->_texturePath, this->_ascii};
}
