/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** AGames
*/

#ifndef AGAMES_HPP_
#define AGAMES_HPP_

#include "Tiles.hpp"
#include <vector>
#include "IGames.hpp"

class AGames : public IGames {
    public:
    protected:
        std::vector<std::vector<Tiles>> Map;
    private:
};

#endif /* !AGAMES_HPP_ */
