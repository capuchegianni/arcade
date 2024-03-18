/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class SfmlGraphicalModule : public AGraphicalModule {
    public:
        SfmlGraphicalModule();
        ~SfmlGraphicalModule() = default;

        void initWindow();
        void destroyWindow();
    private:
        std::shared_ptr<sf::RenderWindow> _window;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
