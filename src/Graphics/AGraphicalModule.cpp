/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGraphicalModule
*/

#include "../../include/Graphics/AGraphicalModule.hpp"

AGraphicalModule::AGraphicalModule(const std::string type) :
    _librabryType(type) { }

std::string AGraphicalModule::getLibraryType() const {
    return this->_librabryType;
}
