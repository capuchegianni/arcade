/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "LdlWrapper.hpp"
#include "ICoreModule.hpp"
#include "Menu.hpp"

class CoreModule : public ICoreModule {
    public:
        CoreModule();
        ~CoreModule();

        // Graphical libraries
        void startWindow();
        void loadGraphicalLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGraphicalModule>& getGraphicalModule();
        LdlWrapper& getGraphicalLib();
        void changeGraphics(const std::string& func);
        void closeGraphicalLib();
        void getGraphicsList();

        // Game libraries
        void startGame();
        void loadGameLibrary(const std::string& path, const std::string& func);
        std::shared_ptr<AGameModule>& getGameModule();
        LdlWrapper& getGameLib();
        void changeGame(const std::string& func);
        void closeGameLib();
        void getGameList();

        // Misc
        void checkFile(const std::string& path) const;
        void handleEvents(const Input& input);
        void reloadGame(bool isChanging);
        void startMenu();

    private:
        std::shared_ptr<AGraphicalModule> _graphicalModule = nullptr;
        std::shared_ptr<AGameModule> _gameModule = nullptr;
        LdlWrapper _graphicalLib;
        LdlWrapper _gameLib;
        std::map<int, std::string> _gameLibs = {};
        std::map<int, std::string> _graphicalLibs = {};
        std::pair<int, std::string> _currentGame = {0, ""};
        std::pair<int, std::string> _currentGraphic = {0, ""};
        bool _menuIsGame = false;
        Menu _menu;
};
