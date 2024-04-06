/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#pragma once

#include "../Libs.hpp"

class Menu {
    public:
        Menu();
        ~Menu() = default;

        int catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
        void initMap();
        void updateMap();
        void setGraphicsLibs(std::map<int, std::string> graphicsLibs);
        void setGameLibs(std::map<int, std::string> gameLibs);
        std::vector<std::vector<Tiles>> getMap() const;
        void setPlayer(const std::string& player);
        std::string getPlayer() const;
        void getScoreFileInfos();

    private:
        int _selectedGame = 0;
        std::string _player = "";
        std::map<int, std::string> _graphicsLibs = {};
        std::map<int, std::string> _gameLibs = {};
        std::vector<std::vector<Tiles>> _map = {};
        bool _isInitialized = false;
        std::map<std::pair<std::string, std::string>, std::string> _scores = {};
};
