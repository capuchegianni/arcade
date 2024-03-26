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
        virtual void setWindowSize(const std::vector<int>& size = {1920, 1080}) = 0;
        virtual void setWindowTitle(const std::string& title) = 0;
        virtual void displayWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual void clearWindow(Color color = {255, 255, 255}) = 0;
        virtual bool isWindowOpen() = 0;
        virtual void parseKeyboard() = 0;

        // Text methods
        virtual void displayText(const std::string& text, const std::vector<int>& pos = {0, 0}, const int& size = 30, const Color& color = {255, 255, 255}) = 0;
        virtual std::any initText(const std::string& text) = 0;
        virtual void setTextColor(const std::any& text, const Color& color) = 0;
        virtual void setTextFont(const std::any& text, const std::string& path) = 0;
        virtual void setTextOutline(const std::any& text, const bool& hasOutline = true) = 0;
        virtual void setTextOutlineThickness(const std::any& text, const int& thickness = 1) = 0;
        virtual void setTextOutlineColor(const std::any& text, const Color& color) = 0;
        virtual void setTextFillColor(const std::any& text, const Color& color) = 0;
        virtual void setTextSize(const std::any& text, const int& size = 30) = 0;
        virtual void setTextPosition(const std::any& text, const std::vector<int>& pos = {0, 0}) = 0;
        virtual void setTextOrigin(const std::any& text, const std::vector<int>& origin = {0, 0}) = 0;

        // Shapes methods
        virtual void drawRectangle(const std::vector<int>& size = {10, 10}, const std::vector<int>& pos = {0, 0}, const Color& color = {255, 255, 255}) = 0;
        virtual void setRectangleColor(std::any& rect, const Color& color) = 0;
        virtual void setRectangleSize(std::any& rect, const std::vector<int>& size) = 0;
        virtual void setRectanglePosition(std::any& rect, const std::vector<int>& pos) = 0;
        virtual void drawCircle(const int& rad = 10, const std::vector<int>& pos = {0, 0}, const Color& color = {255, 255, 255}) = 0;
        virtual void setCircleColor(std::any& circle, const Color& color) = 0;
        virtual void setCircleRadius(std::any& circle, const int& rad) = 0;
        virtual void setCirclePosition(std::any& circle, const std::vector<int>& pos) = 0;

        // Sprite methods
        virtual void displaySprite(const std::string& path, const std::vector<int>& pos = {0, 0}, const std::vector<float>& scale = {1, 1}, const float& rotation = 0, const std::vector<int>& origin = {0, 0}, const Color& color = {255, 255, 255}) = 0;
        virtual std::any initSprite(const std::string& path) = 0;
        virtual void setSpriteTexture(std::any sprite, const std::string& path) = 0;
        virtual void setSpritePosition(std::any sprite, const std::vector<int>& pos) = 0;
        virtual void setSpriteScale(std::any sprite, const std::vector<float>& scale) = 0;
        virtual void setSpriteRotation(std::any sprite, const float& rotation) = 0;

        // Misc methods
        std::string getLibraryType() const;
    protected:
        std::string _libraryType;
};
