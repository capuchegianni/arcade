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

        // Graphical libraries
        virtual void startWindow() = 0;
        virtual void loadGraphicalLibrary(const std::string& path, const std::string& func) = 0;
        virtual std::shared_ptr<AGraphicalModule>& getGraphicalModule() = 0;
        virtual LdlWrapper& getGraphicalLib() = 0;
        virtual void changeGraphics(const std::string& func) = 0;
        virtual void closeGraphicalLib() = 0;
        virtual void getGraphicsList() = 0;

        // Game libraries
        virtual void startGame() = 0;
        virtual void loadGameLibrary(const std::string& path, const std::string& func) = 0;
        virtual std::shared_ptr<AGameModule>& getGameModule() = 0;
        virtual LdlWrapper& getGameLib() = 0;
        virtual void changeGame(const std::string& func) = 0;
        virtual void closeGameLib() = 0;
        virtual void getGameList() = 0;

        // Misc
        virtual void checkFile(const std::string& path) const = 0;
        virtual void handleEvents(const Input& input) = 0;
        virtual void reloadGame(bool isChanging) = 0;
        virtual void startMenu() = 0;
};
