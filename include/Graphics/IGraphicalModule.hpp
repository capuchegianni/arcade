/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

#include <iostream>

class IGraphicalModule {
    public:
        virtual ~IGraphicalModule() = default;

        virtual void initWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual std::string getLibraryType() const = 0;
};
