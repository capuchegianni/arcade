/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Empty
*/

#pragma once

#include "../AEntities.hpp"

class Empty : public AEntities {
    public:
        Empty(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;

    private:
        std::string _texturePath;
        ASCII _ascii;
};
