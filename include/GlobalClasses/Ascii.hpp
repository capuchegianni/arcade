/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ascii
*/

#pragma once

#include "Color.hpp"

class ASCII {
    public:
        ASCII() = default;
        ASCII(char ascii, Color color);

        Color getColor() const;
        char getAscii() const;

    private:
        char _ascii = 0;
        Color _color = Color(255, 255, 255);
};
