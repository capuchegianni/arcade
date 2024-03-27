/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ICoreModule
*/

#pragma once

#include "../Libs.hpp"

class ICoreModule {
    public:
        virtual ~ICoreModule() = default;

        virtual void checkFile(const std::string& path) const = 0;
        virtual void loadGraphicalLibrary(const std::string& path, const std::string& func) = 0;
        virtual void loadGameLibrary(const std::string& path, const std::string& func) = 0;
        virtual void closeGraphicalLib() = 0;
        virtual void closeGameLib() = 0;
        virtual void startGame() = 0;
        virtual void initEntities(const std::vector<AEntities>& entities) = 0;
        virtual void changeGame(const std::string& path, const std::string& func) = 0;
        virtual void changeGraphics(const std::string& path, const std::string& func) = 0;
};
