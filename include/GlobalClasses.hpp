/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** GlobalClasses
*/

#pragma once

#include "./Libs.hpp"
#include "./Enums.hpp"

class Tiles {
    public:
        bool isType(TilesType type);
        void setType(TilesType type);
        TilesType getType() const;

    private:
        TilesType _type = EMPTY;
};
