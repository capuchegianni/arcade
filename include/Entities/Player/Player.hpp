/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#pragma once

#include "./PlayerHead/PlayerHead.hpp"
#include "./PlayerBody/PlayerBody.hpp"
#include "./PlayerTail/PlayerTail.hpp"

class Player {
    public:
        Player();

        void setHead(PlayerHead head);
        void setBody(PlayerBody body);
        void setTail(PlayerTail tail);
        PlayerHead getHead() const;
        std::vector<PlayerBody> getBody() const;
        PlayerTail getTail() const;

    private:
        PlayerHead _head;
        std::vector<PlayerBody> _body;
        PlayerTail _tail;
};
