/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#pragma once

#include <iostream>
#include <memory>
#include <dlfcn.h>
#include "../Errors.hpp"
#include "../Graphics/AGraphicalModule.hpp"

class LdlWrapper {
    public:
        LdlWrapper() = default;
        LdlWrapper(const std::string& path);
        ~LdlWrapper() = default;

        void openLib(const std::string& path);
        template<typename T>
        T getFunction(const std::string& name);
        std::unique_ptr<AGraphicalModule> createLib(const std::string& func);
        void *getHandle() const;

    private:
        void *_handle = nullptr;
};
