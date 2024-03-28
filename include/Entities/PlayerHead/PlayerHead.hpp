/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerHead
*/

#pragma once

#include "../AEntities.hpp"

class PlayerHead : public AEntities {
    public:
        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;

    private:
        std::string _texturePath;
        ASCII _ascii;
};
