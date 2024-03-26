/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Tiles
*/

#pragma once

#include "Libs.hpp"
#include "./Entities/AEntities.hpp"

class Tiles {
    public:
        Tiles(std::vector<AEntities> entities, int size);

        std::vector<AEntities> getEntities() const;
        void setEntities(std::vector<AEntities> entities);
        int getSize() const;
        void setSize(int size);

    private:
        std::vector<AEntities> _entities;
        int _size = 1;
};
