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
#include "../../Entities/Player/Player.hpp"
#include "../../Entities/Player/PlayerHead/PlayerHead.hpp"
#include "../../Entities/Player/PlayerBody/PlayerBody.hpp"
#include "../../Entities/Player/PlayerTail/PlayerTail.hpp"
#include "../../Entities/Entities.hpp"

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
        void updateGame();

    private:
        Direction _direction = Direction::EAST;
        Direction _lastDirection = Direction::EAST;
        Player _player;
        int _mapNb = 1;
        int _fruitNb = 0;
        bool _loadingMap = true;
        unsigned int _chronoRefresh = 200;
        unsigned int _lastChronoRefresh = 200;
        bool _speedBoost = false;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !SNAKE_HPP_ */
