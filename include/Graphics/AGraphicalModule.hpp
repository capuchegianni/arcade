/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGraphicalModule
*/

#pragma once

#include "IGraphicalModule.hpp"
#include <iostream>

class AGraphicalModule {
    public:
        AGraphicalModule(const std::string type);
        virtual ~AGraphicalModule() = default;

        std::string getLibraryType() const;
    protected:
        std::string _librabryType;
};
