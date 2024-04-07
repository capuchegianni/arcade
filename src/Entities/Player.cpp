/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#include "../../include/Entities/Player.hpp"

Player::Player()
{
    this->_head = PlayerHead();
    this->_body = std::vector<PlayerBody>();
    this->_tail = PlayerTail();
}

void Player::setHead(PlayerHead head)
{
    this->_head = head;
}

void Player::setBody(PlayerBody body)
{
    this->_body.push_back(body);
}

void Player::setTail(PlayerTail tail)
{
    this->_tail = tail;
}

PlayerHead &Player::getHead()
{
    return this->_head;
}

std::vector<PlayerBody> &Player::getBody()
{
    return this->_body;
}

PlayerTail &Player::getTail()
{
    return this->_tail;
}

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
