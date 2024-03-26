/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AEntities
*/

#pragma once

#include "../Libs.hpp"
#include "IEntities.hpp"
#include "../Ascii.hpp"

class AEntities : public IEntities {
    public:
        virtual ~AEntities() = default;

        float getSpeed() const = 0;
        void setSpeed(float speed) = 0;
        std::pair<int, int> getPos() const = 0;
        void setPos(std::pair<int, int> pos) = 0;
        std::pair<std::string, ASCII> imageToDisplay() const = 0;

    protected:
        float _speed = 0;
        std::pair<int, int> _pos = {0, 0};
        std::string _texturePath = "";
        ASCII _ascii = ASCII(' ', Color(255, 255, 255));

    private:
};
