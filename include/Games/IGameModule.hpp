/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include "../Libs.hpp"
#include "../Enums.hpp"
#include "../Tiles.hpp"

class IGameModule {
    public:
        ~IGameModule() = default;

        // score
        virtual void setScore(int score, std::string = "") = 0;
        virtual int getScore() const = 0;
        virtual void setHighScore(int score, std::string = "") = 0;
        virtual int getHighScore() const = 0;

        // game status
        virtual void setGameStatus(GameStatus status) = 0;
        virtual GameStatus getGameStatus() const = 0;
        virtual std::vector<std::vector<Tiles>> getMap() = 0;

        // inputs
        virtual void parseInput(Input key = NONE) = 0;
};


#endif /* !IGAMES_HPP_ */
