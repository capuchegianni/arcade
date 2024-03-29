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
        AEntities(double speed = 1, std::pair<int, int> pos = {0, 0}, std::string texturePath = "", ASCII ascii = ASCII(' ', Color(255, 255, 255)), std::string name = "entity");

        double getSpeed() const;
        void setSpeed(double speed);
        std::pair<int, int> getPos() const;
        void setPos(std::pair<int, int> pos);
        virtual std::pair<std::string, ASCII> imageToDisplay() const = 0;
        virtual EntityType getType() const = 0;
        std::string getName() const;
        void setName(std::string name);

    protected:
        std::string _name;
        double _speed;
        std::pair<int, int> _pos;
        std::string _texturePath;
        ASCII _ascii;
};
