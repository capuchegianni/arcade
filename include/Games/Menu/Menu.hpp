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

        void parseInput(Input key = NONE);
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !MENU_HPP_ */
