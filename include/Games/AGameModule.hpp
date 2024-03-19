/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** AGames
*/

#ifndef AGAMES_HPP_
#define AGAMES_HPP_

#include "../Libs.hpp"

#include "Tiles.hpp"
#include "IGameModule.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule(const std::string gameName);
        virtual ~AGameModule() = default;

        virtual std::vector<std::vector<Tiles>> tick(Input key = NONE) = 0;
        virtual void reset() = 0;
        virtual int getScore() = 0;
        std::string getGameName() const;

    protected:
        std::vector<std::vector<Tiles>> map;
        std::string gameName;
};

#endif /* !AGAMES_HPP_ */
