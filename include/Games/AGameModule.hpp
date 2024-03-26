/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** AGames
*/

#ifndef AGAMES_HPP_
#define AGAMES_HPP_

#include "../Libs.hpp"
#include "IGameModule.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule(const std::string gameName);
        virtual ~AGameModule() = default;

        virtual std::vector<std::vector<Tiles>> tick(Input key = NONE) = 0;
        virtual void setMap() = 0;
        virtual void reset() = 0;
        virtual void movePlayer() = 0;
        virtual void changeDirection(Input key) = 0;
        virtual void autoTurn() = 0;
        virtual bool checkCollision(Input key) = 0;
        virtual bool eatFruit() = 0;

        int getScore() const;
        std::string getGameName() const;

    protected:
        std::vector<std::vector<Tiles>> map;
        int score;
        std::string gameName;
        std::vector<std::pair<int, int>> playerPos;
        float velocity;
        int wave;
        Direction direction;
};

#endif /* !AGAMES_HPP_ */
