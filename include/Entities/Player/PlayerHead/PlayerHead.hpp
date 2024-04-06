/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerHead
*/

#pragma once

#include "../../AEntities.hpp"

class PlayerHead : public AEntities {
    public:
        PlayerHead() = default;
        PlayerHead(std::pair<int, int> pos);
        PlayerHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};
