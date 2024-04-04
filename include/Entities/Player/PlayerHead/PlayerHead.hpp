/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** PlayerHead
*/

#pragma once

#include "../../AEntities.hpp"

class PlayerHead : public AEntities {
    public:
        PlayerHead() = default;
        PlayerHead(std::pair<int, int> pos);
        PlayerHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};

class PlayerHeadNorth : public AEntities {
    public:
        PlayerHeadNorth() = default;
        PlayerHeadNorth(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};

class PlayerHeadSouth : public AEntities {
    public:
        PlayerHeadSouth() = default;
        PlayerHeadSouth(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};

class PlayerHeadWest : public AEntities {
    public:
        PlayerHeadWest() = default;
        PlayerHeadWest(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};

class PlayerHeadEast : public AEntities {
    public:
        PlayerHeadEast() = default;
        PlayerHeadEast(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const override;
        std::pair<std::string, ASCII> imageToDisplay() const;
};
