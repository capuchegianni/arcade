/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "../Errors.hpp"
#include "LdlWrapper.hpp"
#include <iostream>
#include <memory>
#include <array>
#include <algorithm>
#include <filesystem>
#include <dlfcn.h>

class CoreModule {
    public:
        ~CoreModule() = default;

        void checkFile(const std::string& path) const;
        void loadLibrary(const std::string& path, const std::string& func);
        void checkLibrary();

    private:
        std::unique_ptr<AGraphicalModule> _module;
};
