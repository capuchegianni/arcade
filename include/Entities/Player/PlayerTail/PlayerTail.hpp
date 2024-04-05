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
        PlayerTail(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        void setLastPos(std::pair<int, int> pos);
        std::pair<int, int> getLastPos() const;

    private:
        std::pair<int, int> _lastPos;
};
