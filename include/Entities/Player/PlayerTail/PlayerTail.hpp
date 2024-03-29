/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerTail
*/

#pragma once

#include "../../AEntities.hpp"

class PlayerTail : public AEntities {
    public:
        PlayerTail() = default;
        PlayerTail(std::pair<int, int> pos);
        PlayerTail(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};
