/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGraphicalModule
*/

#pragma once

#include "IGraphicalModule.hpp"

class AGraphicalModule : public IGraphicalModule {
    public:
        AGraphicalModule(const std::string type);
        virtual ~AGraphicalModule() = default;

        virtual void initWindow() = 0;
        virtual void destroyWindow() = 0;
        std::string getLibraryType() const;
    protected:
        std::string _librabryType;
};
