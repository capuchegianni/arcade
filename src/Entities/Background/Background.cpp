/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Background
*/

#include "../../../include/Entities/Background/Background.hpp"

Background::Background(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name) { }

EntityType Background::getType() const {
    return EntityType::BACKGROUND;
}

std::pair<std::string, ASCII> Background::imageToDisplay() const {
    return {this->_texturePath, this->_ascii};
}
