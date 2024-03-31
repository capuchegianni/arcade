/*
** EPITECH PROJECT, 2024
** arcade
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

void ASCII::setAscii(char ascii) {
    this->_ascii = ascii;
}

void ASCII::setColor(Color color) {
    this->_color = color;
}
