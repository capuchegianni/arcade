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

        // Window methods
        void createWindow(const std::string& name, const std::vector<int>& size);
        void setWindowSize(const std::vector<int>& size);
        void setWindowTitle(const std::string& title);
        void displayWindow();
        void destroyWindow();
        bool isWindowOpen();
        Input parseKeyboard();
        void showMap(std::vector<std::vector<Tiles>>& map);

    private:
        sf::RenderWindow _window;
        sf::Event _event;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
