/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl2GraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include "SDL2Wrapper.hpp"
#include <memory>

class Sdl2GraphicalModule : public AGraphicalModule {
    public:
        ~Sdl2GraphicalModule() = default;

        void initWindow();
        void destroyWindow();
    private:
        std::shared_ptr<SDL_Window> _window;
};
