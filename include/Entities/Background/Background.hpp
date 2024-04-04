/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Background
*/

#pragma once

#include "../AEntities.hpp"

class Background : public AEntities {
    public:
        Background(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};
