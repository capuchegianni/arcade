/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../AGameModule.hpp"

class Nibbler : public AGameModule {
    public:
        std::vector<std::vector<Tiles>> tick(Input key = NONE) override;
        void setMap() override;
        void reset() override;
        void changeDirection(Input key) override;
        void movePlayer() override;
        void autoTurn() override;
        bool checkCollision(Input key) override;
        bool eatFruit() override;
};

#endif /* !NIBBLER_HPP_ */
