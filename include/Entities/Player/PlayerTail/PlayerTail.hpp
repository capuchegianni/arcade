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
        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;

    private:
        std::string _texturePath;
        ASCII _ascii;
};
