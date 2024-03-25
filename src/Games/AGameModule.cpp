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
}

std::string AGameModule::getGameName() const
{
    return this->gameName;
}
