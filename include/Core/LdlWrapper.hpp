/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#pragma once

#include "../Graphics/AGraphicalModule.hpp"
#include "../Games/AGameModule.hpp"

class LdlWrapper {
    public:
        LdlWrapper() = default;
        LdlWrapper(const std::string& path);
        ~LdlWrapper() = default;

        void openLib(const std::string& path);
        template<typename T>
        T getFunction(const std::string& name);
        std::shared_ptr<AGraphicalModule> createGraphicalLib(const std::string& func);
        std::shared_ptr<AGameModule> createGameLib(const std::string& func);
        void *getHandle() const;

    private:
        void *_handle = nullptr;
};
