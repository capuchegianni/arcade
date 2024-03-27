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
        Nibbler();
        ~Nibbler() = default;

        void parseInput(Input key = NONE);
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !NIBBLER_HPP_ */