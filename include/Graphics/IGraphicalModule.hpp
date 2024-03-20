/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

#include "../Libs.hpp"

class Color {
    public:
        Color(int r = 255, int g = 255, int b = 255, int a = 255) : r(r), g(g), b(b), a(a) {}
        int r;
        int g;
        int b;
        int a;
};

class IGraphicalModule {
    public:
        virtual ~IGraphicalModule() = default;

        // Window methods
        /**
         * @brief Create the window
         * @param name Title of the window
         * @param size Size of the window (default: 1920x1080)
        */
        virtual void createWindow(const std::string& name, const std::vector<int>& size) = 0;

        /**
         * @brief Initialize the window and return it
        */
        virtual void initWindow() = 0;

        /**
         * @brief Set the window size
         * @param size Size of the window (default: 1920x1080)
        */
        virtual void setWindowSize(const std::vector<int>& size) = 0;

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
        virtual void clearWindow(Color color) = 0;

        /**
         * @brief Return true if the window is open, false otherwise
         * @return bool
        */
        virtual bool isWindowOpen() = 0;

        /**
         * @brief Parse keyboard events
        */
        virtual void parseKeyboard() = 0;


        // Text methods
        /**
         * @brief Display text on the window
         * @param text Text to display
         * @param pos Position of the text (default: 0x0)
         * @param size Size of the text (default: 30)
         * @param color Color of the text (default: white)
        */
        virtual void displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color) = 0;

        /**
         * @brief Initialize text and return it
         * @param text Text to initialize
         * @return std::any
        */
        virtual std::any initText(const std::string& text) = 0;

        /**
         * @brief Set text color
         * @param text Text to set the color
         * @param color Color of the text (default: white)
        */
        virtual void setTextColor(const std::any& text, const Color& color) = 0;

        /**
         * @brief Set text font
         * @param text Text to set the font
         * @param path Path to the font
        */
        virtual void setTextFont(const std::any& text, const std::string& path) = 0;

        /**
         * @brief Set text outline
         * @param text Text to set the outline
         * @param hasOutline Boolean to set outline (default: true)
        */
        virtual void setTextOutline(const std::any& text, const bool& hasOutline) = 0;

        /**
         * @brief Set text outline thickness
         * @param text Text to set the outline thickness
         * @param thickness Thickness of the outline (default: 0)
        */
        virtual void setTextOutlineThickness(const std::any& text, const int& thickness) = 0;

        /**
         * @brief Set text outline color
         * @param text Text to set the outline color
         * @param color Color of the outline (default: white)
        */
        virtual void setTextOutlineColor(const std::any& text, const Color& color) = 0;

        /**
         * @brief Set text fill color
         * @param text Text to set the fill color
         * @param color Color of the fill (default: white)
        */
        virtual void setTextFillColor(const std::any& text, const Color& color) = 0;

        /**
         * @brief Set text size
         * @param text Text to set the size
         * @param size Size of the text (default: 30)
        */
        virtual void setTextSize(const std::any& text, const int& size) = 0;

        /**
         * @brief Set text position
         * @param text Text to set the position
         * @param pos Position of the text (default: 0x0)
        */
        virtual void setTextPosition(const std::any& text, const std::vector<int>& pos) = 0;

        /**
         * @brief Set text origin
         * @param text Text to set the origin
         * @param origin Origin of the text (default: 0x0)
        */
        virtual void setTextOrigin(const std::any& text, const std::vector<int>& origin) = 0;


        // Shapes methods
        /**
         * @brief Draw a rectangle on the window
         * @param size Size of the rectangle (default: 10x10)
         * @param pos Position of the rectangle (default: 0x0)
         * @param color Color of the rectangle (default: white)
        */
        virtual void drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color) = 0;

        /**
         * @brief Set the color of a rectangle
         * @param rect Rectangle to set the color
         * @param color Color of the rectangle
        */
        virtual void setRectangleColor(std::any& rect, const Color& color) = 0;

        /**
         * @brief Set the rectangle size
         * @param rect Rectangle to set the size
         * @param size Size of the rectangle
        */
        virtual void setRectangleSize(std::any& rect, const std::vector<int>& size) = 0;

        /**
         * @brief Set the rectangle position
         * @param rect Rectangle to set the position
         * @param pos Position of the rectangle
        */
        virtual void setRectanglePosition(std::any& rect, const std::vector<int>& pos) = 0;

        /**
         * @brief Draw a circle on the window
         * @param rad Radius of the circle (default: 10)
         * @param pos Position of the circle (default: 0x0)
         * @param color Color of the circle (default: white)
        */
        virtual void drawCircle(const int&, const std::vector<int>& pos, const Color& color) = 0;

        /**
         * @brief Set the color of a circle
         * @param circle Circle to set the color
         * @param color Color of the circle
        */
        virtual void setCircleColor(std::any& circle, const Color& color) = 0;

        /**
         * @brief Set the circle radius
         * @param circle Circle to set the radius
         * @param rad Radius of the circle
        */
        virtual void setCircleRadius(std::any& circle, const int& rad) = 0;

        /**
         * @brief Set the circle position
         * @param circle Circle to set the position
         * @param pos Position of the circle
        */
        virtual void setCirclePosition(std::any& circle, const std::vector<int>& pos) = 0;


        // Sprite methods
        /**
         * @biref Display a sprite on the window
         * @param path Path for the texture of the sprite
         * @param pos Position of the sprite (default: 0x0)
         * @param scale Scale of the sprite (default: 1x1)
         * @param rotation Rotation of the sprite (default: 0)
         * @param origin Origin of the sprite (default: 0x0)
         * @param color Color of the sprite (default: white)
        */
        virtual void displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color) = 0;

        /**
         * @brief Init and return the created sprite
         * @param path Path for the texture of the sprite
         * @return std::any
        */
        virtual std::any initSprite(const std::string& path) = 0;

        /**
         * @brief Set a new texture for the sprite
         * @param sprite Sprite to set the texture
         * @param path Path for the new texture
        */
        virtual void setSpriteTexture(std::any sprite, const std::string& path) = 0;

        /**
         * @brief Set the sprite position
         * @param sprite Sprite to set the position
         * @param pos Position of the sprite
        */
        virtual void setSpritePosition(std::any sprite, const std::vector<int>& pos) = 0;

        /**
         * @brief Set the sprite scale
         * @param sprite Sprite to set the scale
         * @param scale Scale of the sprite
        */
        virtual void setSpriteScale(std::any sprite, const std::vector<float>& scale) = 0;

        /**
         * @brief Set the sprite rotation
         * @param sprite Sprite to set the rotation
         * @param rotation Rotation of the sprite
        */
        virtual void setSpriteRotation(std::any sprite, const float& rotation) = 0;


        // Misc methods
        /**
         * @brief Return the library type
         * @return std::string
        */
        virtual std::string getLibraryType() const = 0;
};
