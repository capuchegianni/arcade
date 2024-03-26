/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

#include "../Libs.hpp"
#include "../GlobalClasses.hpp"

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
        virtual void initWindow(const std::string& name, const std::vector<int>& size) = 0;

        /**
         * @brief Display the window
        */
        virtual void displayWindow() = 0;

        /**
         * @brief Destroy the window
        */
        virtual void destroyWindow() = 0;

        /**
         * @brief Return true if the window is open, false otherwise
         * @return bool
        */
        virtual bool isWindowOpen() = 0;

        /**
         * @brief Parse keyboard events
        */
        virtual void parseKeyboard() = 0;

        /**
         * @brief Display the map passed as parameter onto the window
         * @param map Map to show
        */
        virtual void showMap(std::vector<std::vector<Tiles>>& map) = 0;


        // Misc methods
        /**
         * @brief Return the library type
         * @return std::string
        */
        virtual std::string getLibraryType() const = 0;
};
