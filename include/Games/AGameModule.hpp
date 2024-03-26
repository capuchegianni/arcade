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

    protected:
        std::vector<std::vector<Tiles>> _map {};
        std::string _playerName = "";
        GameStatus _gameStatus = GameStatus::RUNNING;
        std::string _gameName = "";
        int _score = 0;
};


#endif /* !AGAMES_HPP_ */
