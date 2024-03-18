/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "LdlWrapper.hpp"

class CoreModule {
    public:
        ~CoreModule();

        void checkFile(const std::string& path) const;
        void loadLibrary(const std::string& path, const std::string& func);
        void checkLibrary();
        std::shared_ptr<AGraphicalModule>& getModule();
        LdlWrapper& getLib();
        void closeLib();

    private:
        void *_handle = nullptr;
        std::shared_ptr<AGraphicalModule> _module = nullptr;
        LdlWrapper _graphicalLib;
};
