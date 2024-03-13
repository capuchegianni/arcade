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
#include <array>
#include <algorithm>
#include <filesystem>

class CoreModule {
    public:
        ~CoreModule() = default;

        void checkFile(const std::string path) const;
};
