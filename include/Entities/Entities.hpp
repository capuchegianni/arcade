/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Entities
*/

#pragma once

#include "AEntities.hpp"

class Wall : public AEntities {
    public:
        Wall(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class Fruit : public AEntities {
    public:
        Fruit(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class Empty : public AEntities {
    public:
        Empty(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class Button : public AEntities {
    public:
        Button(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class Background : public AEntities {
    public:
        Background(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};
