/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "../AGameModule.hpp"

class Centipede : public AGameModule {
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

#endif /* !CENTIPEDE_HPP_ */
