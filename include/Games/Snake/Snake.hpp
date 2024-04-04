/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../AGameModule.hpp"

class Snake : public AGameModule {
    public:
        Snake();
        ~Snake() = default;

        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !SNAKE_HPP_ */
