/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesGraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include "NcursesWrapper.hpp"

class NcursesGraphicalModule : public AGraphicalModule {
    public:
        NcursesGraphicalModule();
        ~NcursesGraphicalModule() = default;

        // Window methods
        void createWindow(const std::string& name, const std::vector<int>& size);
        void setWindowSize(const std::vector<int>& size);
        void setWindowTitle(const std::string& title);
        void displayWindow();
        void destroyWindow();
        bool isWindowOpen();
        Input parseKeyboard();
        void showMap(const std::vector<std::vector<Tiles>>& map);
        void initAssets(const std::vector<std::shared_ptr<AEntities>>& entities);

    private:
        int _tick = 0;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
