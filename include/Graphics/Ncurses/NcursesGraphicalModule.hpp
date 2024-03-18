/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesGraphicalModule
*/

#pragma once

#include "../AGraphicalModule.hpp"
#include "NcursesWrapper.hpp"

class NcursesGraphicalModule : public AGraphicalModule {
    public:
        NcursesGraphicalModule();
        ~NcursesGraphicalModule() = default;

        void initWindow();
        void destroyWindow();
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
