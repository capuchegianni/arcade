/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IEntities
*/

#pragma once

#include "../Libs.hpp"
#include "../Ascii.hpp"

class IEntities {
    public:
        virtual ~IEntities() = default;

        virtual float getSpeed() const = 0;
        virtual void setSpeed(float speed) = 0;
        virtual std::pair<int, int> getPos() const = 0;
        virtual void setPos(std::pair<int, int> pos) = 0;
        virtual std::pair<std::string, ASCII> imageToDisplay() const = 0;
};
