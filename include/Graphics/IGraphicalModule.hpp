/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

#include "../Libs.hpp"

class IGraphicalModule {
    public:
        virtual ~IGraphicalModule() = default;

        virtual void initWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual std::string getLibraryType() const = 0;
};

class Color {
    public:
        Color(int r = 255, int g = 255, int b = 255, int a = 255) : r(r), g(g), b(b), a(a) {}
        int r;
        int g;
        int b;
        int a;
};
