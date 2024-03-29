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
