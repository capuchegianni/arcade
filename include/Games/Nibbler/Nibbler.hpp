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
#include "../../Entities/Empty/Empty.hpp"
#include "../../Entities/Enemy/Enemy.hpp"
#include "../../Entities/Fruit/Fruit.hpp"
#include "../../Entities/Player/Player.hpp"
#include "../../Entities/Player/PlayerHead/PlayerHead.hpp"
#include "../../Entities/Player/PlayerBody/PlayerBody.hpp"
#include "../../Entities/Player/PlayerTail/PlayerTail.hpp"
#include "../../Entities/Projectile/Projectile.hpp"
#include "../../Entities/Wall/Wall.hpp"

class Nibbler : public AGameModule {
    public:
        Nibbler();
        ~Nibbler() = default;

        void loadMap();
        void reset();
        void changeDirection(Input key);
        void movePlayer();
        void autoTurn();
        void playerWin();
        void clearPlayer();
        void placePlayer();
        void eatFruit();
        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !NIBBLER_HPP_ */
