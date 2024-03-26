/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "LdlWrapper.hpp"

class CoreModule {
    public:
        ~CoreModule();

        // Graphical libraries
        void loadGraphicalLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGraphicalModule>& getGraphicalModule();
        LdlWrapper& getGraphicalLib();
        std::shared_ptr<AGraphicalModule>& changeGraphicalLib(const std::string& path, const std::string& func);
        void closeGraphicalLib();

        // Game libraries
        void loadGameLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGameModule>& getGameModule();
        LdlWrapper& getGameLib();
        std::shared_ptr<AGameModule>& changeGameLib(const std::string& path, const std::string& func);
        void closeGameLib();

        // Misc
        void checkFile(const std::string& path) const;
        void startGame();

    private:
        std::shared_ptr<AGraphicalModule> _graphicalModule = nullptr;
        std::shared_ptr<AGameModule> _gameModule = nullptr;
        LdlWrapper _graphicalLib;
        LdlWrapper _gameLib;
};
