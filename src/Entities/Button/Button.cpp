/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Button
*/

#include "../../../include/Entities/Button/Button.hpp"

Button::Button(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name) { }

EntityType Button::getType() const {
    return EntityType::BUTTON;
}

std::pair<std::string, ASCII> Button::imageToDisplay() const {
    return {this->_texturePath, this->_ascii};
}
