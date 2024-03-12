/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesGraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include "NcursesWrapper.hpp"
#include <memory>

class NcursesGraphicalModule : public AGraphicalModule {
    public:
        ~NcursesGraphicalModule() = default;

        void initWindow();
        void destroyWindow();
    private:
        std::shared_ptr<WINDOW> _window;
};