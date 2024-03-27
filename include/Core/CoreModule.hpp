/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "LdlWrapper.hpp"
#include "ICoreModule.hpp"

class CoreModule : public ICoreModule {
    public:
        ~CoreModule();

        // Graphical libraries
        void loadGraphicalLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGraphicalModule>& getGraphicalModule();
        LdlWrapper& getGraphicalLib();
        void changeGraphics(const std::string& path, const std::string& func);
        void closeGraphicalLib();

        // Game libraries
        void loadGameLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGameModule>& getGameModule();
        LdlWrapper& getGameLib();
        void changeGame(const std::string& path, const std::string& func);
        void closeGameLib();

        // Misc
        void checkFile(const std::string& path) const;
        void startGame();
        void initEntities(const std::vector<AEntities>& entities);
        void handleEvents(const Input& input);
        void getLibraries();

    private:
        std::shared_ptr<AGraphicalModule> _graphicalModule = nullptr;
        std::shared_ptr<AGameModule> _gameModule = nullptr;
        LdlWrapper _graphicalLib;
        LdlWrapper _gameLib;
        std::deque<std::string> _gameLibs = {};
        std::deque<std::string> _graphicalLibs = {};
};
