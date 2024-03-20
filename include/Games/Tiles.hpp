/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** Tiles
*/

#ifndef TILES_HPP_
#define TILES_HPP_

#include "../Libs.hpp"
#include "../Enums.hpp"

class Tiles {
    public:
        bool isType(TilesType type);
        void setType(TilesType type);
        TilesType getType() const;

    private:
        TilesType _type = EMPTY;
};

#endif /* !TILES_HPP_ */
