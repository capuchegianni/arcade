/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "../Errors.hpp"
#include <iostream>
#include <memory>

class CoreModule {
    public:
        ~CoreModule() = default;

        void initCore();
        void checkFile(const std::string path);
};
