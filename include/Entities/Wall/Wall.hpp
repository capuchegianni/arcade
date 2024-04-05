/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#pragma once

#include "../AEntities.hpp"

class Wall : public AEntities {
    public:
        Wall(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
};
