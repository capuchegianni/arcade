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
        void initWindow(const std::string& name, const std::vector<int>& size);
        void setWindowSize(const std::vector<int>& size);
        void setWindowTitle(const std::string& title);
        void displayWindow();
        void destroyWindow();
        void clearWindow(Color color);
        bool isWindowOpen();
        void parseKeyboard();

        // Text methods
        void displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color);
        std::any initText(const std::string& text);
        void setTextColor(const std::any& text, const Color& color);
        void setTextFont(const std::any& text, const std::string& path);
        void setTextOutline(const std::any& text, const bool& hasOutline);
        void setTextOutlineThickness(const std::any& text, const int& thickness);
        void setTextOutlineColor(const std::any& text, const Color& color);
        void setTextFillColor(const std::any& text, const Color& color);
        void setTextSize(const std::any& text, const int& size);
        void setTextPosition(const std::any& text, const std::vector<int>& pos);
        void setTextOrigin(const std::any& text, const std::vector<int>& origin);

        // Shapes methods
        void drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color);
        void setRectangleColor(std::any& rect, const Color& color);
        void setRectangleSize(std::any& rect, const std::vector<int>& size);
        void setRectanglePosition(std::any& rect, const std::vector<int>& pos);
        void drawCircle(const int& rad, const std::vector<int>& pos, const Color& color);
        void setCircleColor(std::any& circle, const Color& color);
        void setCircleRadius(std::any& circle, const int& rad);
        void setCirclePosition(std::any& circle, const std::vector<int>& pos);

        // Sprite methods
        void displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color);
        std::any initSprite(const std::string& path);
        void setSpriteTexture(std::any sprite, const std::string& path);
        void setSpritePosition(std::any sprite, const std::vector<int>& pos);
        void setSpriteScale(std::any sprite, const std::vector<float>& scale);
        void setSpriteRotation(std::any sprite, const float& rotation);
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
