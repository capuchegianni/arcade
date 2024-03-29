/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#include "../../../include/Entities/Player/Player.hpp"

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

PlayerHead Player::getHead() const
{
    return this->_head;
}

std::vector<PlayerBody> Player::getBody() const
{
    return this->_body;
}

PlayerTail Player::getTail() const
{
    return this->_tail;
}
