/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enemy
*/

#pragma once

#include "../AEntities.hpp"

class Enemy : public AEntities {
    public:
        Enemy(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};
