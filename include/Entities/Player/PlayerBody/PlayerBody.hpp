/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerBody
*/

#pragma once

#include "../../AEntities.hpp"

class PlayerBody : public AEntities {
    public:
        PlayerBody() = default;
        PlayerBody(std::pair<int, int> pos);
        PlayerBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};
