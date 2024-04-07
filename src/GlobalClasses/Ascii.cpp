/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** Ascii
*/

#include "../../include/GlobalClasses/Ascii.hpp"

ASCII::ASCII(char ascii, Color color) {
    this->_ascii = ascii;
    this->_color = color;
}

char ASCII::getAscii() const {
    return this->_ascii;
}

Color ASCII::getColor() const {
    return this->_color;
}
