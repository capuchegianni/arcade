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

using DlCloseType = int (*)(void *);

class LdlWrapper {
    public:
        LdlWrapper(const std::string filename);
        ~LdlWrapper() = default;

        std::unique_ptr<AGraphicalModule> createModule();
        template<typename T>
        T getFunction(const std::string& name);

    private:
        std::unique_ptr<void, DlCloseType> _handle;
};
