/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Fruit
*/

#pragma once

#include "../AEntities.hpp"

class Fruit : public AEntities {
    public:
        Fruit(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
};
