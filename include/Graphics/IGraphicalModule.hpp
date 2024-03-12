/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

class IGraphicalModule {
    public:
        virtual ~IGraphicalModule() = default;

        virtual void initWindow() = 0;
        virtual void destroyWindow() = 0;
};
