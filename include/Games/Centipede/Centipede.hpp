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

        void parseInput(Input key = NONE);
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !CENTIPEDE_HPP_ */
