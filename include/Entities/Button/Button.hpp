/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Button
*/

#pragma once

#include "../AEntities.hpp"

class Button : public AEntities {
    public:
        Button(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};

