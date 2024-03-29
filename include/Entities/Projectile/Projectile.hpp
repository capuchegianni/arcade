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
        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;

    private:
        std::string _texturePath;
        ASCII _ascii;
};
