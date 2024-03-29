/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Projectile
*/

#pragma once

#include "../AEntities.hpp"

class Projectile : public AEntities {
    public:
        Projectile(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};
