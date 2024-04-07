/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../AGameModule.hpp"
#include "../../GlobalClasses/Errors.hpp"
#include "../../Entities/Player/Player.hpp"
#include "../../Entities/Player/PlayerHead/PlayerHead.hpp"
#include "../../Entities/Player/PlayerBody/PlayerBody.hpp"
#include "../../Entities/Player/PlayerTail/PlayerTail.hpp"
#include "../../Entities/Entities.hpp"

class Nibbler : public AGameModule {
    public:
        Nibbler();
        ~Nibbler() = default;

        void loadMap();
        void changeDirection(Input key);
        void movePlayer();
        void autoTurn();
        void playerWin();
        void playerLose();
        void clearPlayer();
        void placePlayer();
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

#endif /* !NIBBLER_HPP_ */
