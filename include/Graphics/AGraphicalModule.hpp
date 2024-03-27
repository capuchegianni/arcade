/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGraphicalModule
*/

#pragma once

#include "IGraphicalModule.hpp"

class AGraphicalModule : public IGraphicalModule {
    public:
        AGraphicalModule(const std::string type);
        virtual ~AGraphicalModule() = default;

        // Window methods
        virtual void createWindow(const std::string& name, const std::vector<int>& size = {1920, 1080}) = 0;
        virtual void initWindow(const std::string& name, const std::vector<int>& size = {1920, 1080}) = 0;
        virtual void displayWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual bool isWindowOpen() = 0;
        virtual Input parseKeyboard() = 0;
        virtual void showMap(std::vector<std::vector<Tiles>>& map) = 0;

        // Misc methods
        std::string getLibraryType() const;
    protected:
        std::string _libraryType;
        bool _isOpen = false;
};
