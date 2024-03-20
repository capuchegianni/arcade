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
        /**
         * @brief Create the window
         * @param name Title of the window
         * @param size Size of the window (default: 1920x1080)
        */
        virtual void createWindow(const std::string& name, const std::vector<int>& size = {1920, 1080}) = 0;

        /**
         * @brief Initialize the window
         * @return The newly created window
        */
        virtual void initWindow() = 0;

        /**
         * @brief Set the window size
         * @param size Size of the window (default: 1920x1080)
        */
        virtual void setWindowSize(const std::vector<int>& size = {1920, 1080}) = 0;

        /**
         * @brief Set the window title
         * @param title Title of the window
        */
        virtual void setWindowTitle(const std::string& title) = 0;

        /**
         * @brief Display the window
        */
        virtual void displayWindow() = 0;

        /**
         * @brief Destroy the window
        */
        virtual void destroyWindow() = 0;

        /**
         * @brief Clear the window
         * @param color Color to clear the window with (default: white)
        */
        virtual void clearWindow(Color color = {255, 255, 255}) = 0;

        /**
         * @brief Return the window state
         * @return True if the window is open, false otherwise
        */
        virtual bool isWindowOpen() = 0;

        /**
         * @brief Parse keyboard events
        */
        virtual void pollEvents() = 0;


        // Text methods
        /**
         * @brief Display text on the window
         * @param text Text to display
         * @param x X position of the text
         * @param y Y position of the text
         * @param size Size of the text
        */
        virtual void displayText(const std::string& text) = 0;

        /**
         * @brief Initialize text
         * @return std::any
        */
        virtual std::any initText() = 0;

        /**
         * @brief Set text color
         * @param color Color of the text
        */
        virtual void setTextColor(const Color& color) = 0;

        /**
         * @brief Set text font
         * @param path Path to the font
        */
        virtual void setTextFont(const std::string& path) = 0;

        /**
         * @brief Set text outline
         * @param hasOutline Boolean to set outline
        */
        virtual void setTextOutline(const bool& hasOutline) = 0;

        /**
         * @brief Set text outline thickness
         * @param thickness Thickness of the outline
        */
        virtual void setTextOutlineThickness(const int& thickness) = 0;

        /**
         * @brief Set text outline color
         * @param color Color of the outline
        */
        virtual void setTextOutlineColor(const Color& color) = 0;

        /**
         * @brief Set text fill color
         * @param color Color of the fill
        */
        virtual void setTextFillColor(const Color& color) = 0;

        /**
         * @brief Set text size
         * @param size Size of the text
        */
        virtual void setTextSize(const int& size) = 0;

        /**
         * @brief Set text position
         * @param x X position of the text
         * @param y Y position of the text
        */
        virtual void setTextPosition(const int& x, const int& y) = 0;

        /**
         * @brief Set text origin
         * @param x X origin of the text
         * @param y Y origin of the text
        */
        virtual void setTextOrigin(const int& x, const int& y) = 0;

        // virtual void drawRectangle(const int& x1, const int& y1, const int& x2, const int& y2) = 0;
        // virtual void drawCircle(const int& x, const int& y, const int& rad) = 0;
        // virtual void drawLine(const int& x1, const int& y1, const int& x2, const int& y2) = 0;
        // virtual void setLineWidth(const int& width) = 0;
        // virtual void setOutlineColor(const Color& color) = 0;
        // virtual void setFillColor(const Color& color) = 0;
        // virtual void setSprite(const std::string& path) = 0;
        // virtual void setSpriteRect(const int& x, const int& y, const int& w, const int& h) = 0;
        // virtual void setSpriteScale(const float& x, const float& y) = 0;
        // virtual void setSpriteRotation(const float& angle) = 0;
        // virtual void setSpriteColor(const Color& color) = 0;
        // virtual void setSpritePosition(const int& x, const int& y) = 0;
        // virtual void setSpriteOrigin(const int& x, const int& y) = 0;
        // virtual void setSpriteTextureRect(const int& x, const int& y, const int& w, const int& h) = 0;
        // virtual void setSpriteTexture(const std::string& path) = 0;
        // virtual void drawSprite() = 0;

        std::string getLibraryType() const;
    protected:
        std::string _librabryType;
};
