/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl2GraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include "SDL2Wrapper.hpp"

class Sdl2GraphicalModule : public AGraphicalModule {
    public:
        Sdl2GraphicalModule();
        ~Sdl2GraphicalModule() = default;

        // Window methods
        void createWindow(const std::string& name, const std::vector<int>& size);
        void initWindow(const std::string& name, const std::vector<int>& size);
        void setWindowSize(const std::vector<int>& size);
        void setWindowTitle(const std::string& title);
        void displayWindow();
        void destroyWindow();
        bool isWindowOpen();
        Input parseKeyboard();
        void showMap(std::vector<std::vector<Tiles>>& map);

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
