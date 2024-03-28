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
        Centipede();
        ~Centipede() = default;

        void reset();
        void changeDirection(Input key);
        void movePlayer();
        void autoTurn();
        bool checkCollision(Input key);
        bool eatFruit();
        void parseInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> getAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !CENTIPEDE_HPP_ */
