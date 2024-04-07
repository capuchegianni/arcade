/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#pragma once

#include "AEntities.hpp"

class PlayerBody : public AEntities {
    public:
        PlayerBody() = default;
        PlayerBody(std::pair<int, int> pos);
        PlayerBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class PlayerHead : public AEntities {
    public:
        PlayerHead() = default;
        PlayerHead(std::pair<int, int> pos);
        PlayerHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
};

class PlayerTail : public AEntities {
    public:
        PlayerTail() = default;
        PlayerTail(std::pair<int, int> pos);
        PlayerTail(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);

        EntityType getType() const;
        void setLastPos(std::pair<int, int> pos);
        std::pair<int, int> getLastPos() const;

    private:
        std::pair<int, int> _lastPos;
};

class Player {
    public:
        Player();

        void setHead(PlayerHead head);
        void setBody(PlayerBody body);
        void setTail(PlayerTail tail);
        PlayerHead &getHead();
        std::vector<PlayerBody> &getBody();
        PlayerTail &getTail();

    private:
        PlayerHead _head;
        std::vector<PlayerBody> _body;
        PlayerTail _tail;
};
