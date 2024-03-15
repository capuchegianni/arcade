/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "../Errors.hpp"
#include "LdlWrapper.hpp"
#include "../Graphics/AGraphicalModule.hpp"
#include <iostream>
#include <memory>
#include <array>
#include <algorithm>
#include <filesystem>
#include <dlfcn.h>

class CoreModule {
    public:
        ~CoreModule();

        void checkFile(const std::string& path) const;
        void loadLibrary(const std::string& path, const std::string& func);
        void checkLibrary();
        std::unique_ptr<AGraphicalModule>& getModule();

    private:
        std::unique_ptr<AGraphicalModule> _module;
        LdlWrapper _graphicalLib;
};
