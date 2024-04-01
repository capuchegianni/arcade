/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../AGameModule.hpp"

class Menu : public AGameModule {
    public:
        Menu();
        ~Menu() = default;

        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
        void initMap();
        void updateMap();

    private:
        int _selectedGame = 0;
        std::map<int, std::string> _graphicsLibs = {};
        std::map<int, std::string> _gameLibs = {};
};

extern "C" std::shared_ptr<AGameModule> createGame();

class AGraphicalModule;

#endif /* !MENU_HPP_ */
