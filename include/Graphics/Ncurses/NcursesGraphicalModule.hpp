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

        void initWindow();
        void destroyWindow();
        void createWindow(const std::string &name, const std::vector<int> &size);
        void setWindowSize(const std::vector<int> &size);
        void setWindowTitle(const std::string &title);
        void displayWindow();
        void clearWindow(Color color);
        bool isWindowOpen();
        void pollEvents();
        void displayText(const std::string& text);
        std::any initText();
        void setTextColor(const Color& color);
        void setTextFont(const std::string& path);
        void setTextOutline(const bool& hasOutline);
        void setTextOutlineThickness(const int& thickness);
        void setTextOutlineColor(const Color& color);
        void setTextFillColor(const Color& color);
        void setTextSize(const int& size);
        void setTextPosition(const int& x, const int& y);
        void setTextOrigin(const int& x, const int& y);
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
