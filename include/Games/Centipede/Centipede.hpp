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
        bool eatFruit();
        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !CENTIPEDE_HPP_ */
