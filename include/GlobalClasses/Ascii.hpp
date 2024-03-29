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

        char getAscii() const;
        Color getColor() const;
        void setAscii(char ascii);
        void setColor(Color color);
        void setAscii(char ascii);
        void setColor(Color color);
        char getAscii() const;
        Color getColor() const;

    private:
        char _ascii = 0;
        Color _color = Color(255, 255, 255);
};
