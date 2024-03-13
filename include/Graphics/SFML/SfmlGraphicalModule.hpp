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
        SfmlGraphicalModule();
        ~SfmlGraphicalModule() = default;

        void initWindow();
        void destroyWindow();
    private:
        sf::RenderWindow _window;
};

extern "C" std::unique_ptr<AGraphicalModule> createModule();
