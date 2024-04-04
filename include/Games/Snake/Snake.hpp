/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../AGameModule.hpp"
#include "../../GlobalClasses/Errors.hpp"
#include "../../Entities/Empty/Empty.hpp"
#include "../../Entities/Fruit/Fruit.hpp"
#include "../../Entities/Player/Player.hpp"
#include "../../Entities/Player/PlayerHead/PlayerHead.hpp"
#include "../../Entities/Player/PlayerBody/PlayerBody.hpp"
#include "../../Entities/Player/PlayerTail/PlayerTail.hpp"
#include "../../Entities/Wall/Wall.hpp"

class Snake : public AGameModule {
    public:
        Snake();
        ~Snake() = default;

        void loadMap();
        void changeDirection(Input key);
        void movePlayer();
        void playerLose();
        void clearPlayer();
        void placePlayer();
        void spawnFruit();
        void eatFruit();
        void speedBoost(Input key = NONE);
        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !SNAKE_HPP_ */
