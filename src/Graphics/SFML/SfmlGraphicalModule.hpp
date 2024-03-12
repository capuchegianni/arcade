/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include <SFML/Graphics.hpp>

class SfmlGraphicalModule : public AGraphicalModule {
    public:
        ~SfmlGraphicalModule() = default;

        void initWindow();
        void destroyWindow();
    private:
        sf::RenderWindow _window;
};
