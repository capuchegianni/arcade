/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

void CoreModule::checkFile(const std::string path) const {
    if (path.empty())
        throw FileError("Invalid empty filename", 84);
    if (path.rfind(".so") != path.size() - 3)
        throw FileError("Invalid file extension", 84);
    if (!std::filesystem::exists("lib"))
        throw FileError("Directory 'lib' not found", 84);
    if (!std::filesystem::exists(path))
        throw FileError("File '" + path + "' not found", 84);
}
