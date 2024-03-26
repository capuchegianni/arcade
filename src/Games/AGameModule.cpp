/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/

#include "../../include/Games/AGameModule.hpp"

AGameModule::AGameModule(const std::string gameName)
{
    this->gameName = gameName;
    this->score = 0;
    this->velocity = 0.1;
    this->wave = 1;
    this->direction = EAST;
}

int AGameModule::getScore() const
{
    return this->score;
}

std::string AGameModule::getGameName() const
{
    return this->gameName;
}
