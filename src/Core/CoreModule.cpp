/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

void CoreModule::checkFile(const std::string& path) const {
    if (path.empty())
        throw FileError("Invalid empty filename", 84);
    if (path.rfind(".so") != path.size() - 3)
        throw FileError("Invalid file extension", 84);
    if (!std::filesystem::exists("lib"))
        throw FileError("Directory 'lib' not found", 84);
    if (!std::filesystem::exists(path))
        throw FileError("File '" + path + "' not found", 84);
}

void CoreModule::loadLibrary(const std::string& path, const std::string& func) {
    LdlWrapper lib(path);

    this->_module = lib.createLib(func);
    this->checkLibrary();
}

void CoreModule::checkLibrary() {
    std::array<std::string, 3> libs = {
        "Ncurses",
        "SFML",
        "SDL2"
    };

    if (std::find(libs.begin(), libs.end(), this->_module->getLibraryType()) == libs.end())
        throw FileError("Invalid library type '" + this->_module->getLibraryType() + "'", 84);
}
