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
        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;

    private:
        std::string _texturePath;
        ASCII _ascii;
};
