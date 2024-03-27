/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AEntities
*/

#pragma once

#include "IEntities.hpp"

class AEntities : public IEntities {
    public:
        AEntities(double speed = 1, std::pair<int, int> pos = {0, 0}, std::string texturePath = "", ASCII ascii = ASCII(' ', Color(255, 255, 255)));

        double getSpeed() const;
        void setSpeed(double speed);
        std::pair<int, int> getPos() const;
        void setPos(std::pair<int, int> pos);
        std::pair<std::string, ASCII> imageToDisplay() const;

    protected:
        double _speed;
        std::pair<int, int> _pos;
        std::string _texturePath;
        ASCII _ascii;
};