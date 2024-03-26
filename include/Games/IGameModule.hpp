/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include "../Libs.hpp"
#include "../GlobalClasses.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual std::vector<std::vector<Tiles>> tick(Input key = NONE) = 0;
        virtual void reset() = 0;
        virtual int getScore() = 0;
        virtual std::string getGameName() const = 0;
};

#endif /* !IGAMES_HPP_ */
