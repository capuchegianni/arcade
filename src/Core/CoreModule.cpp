/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#include "../../include/Core/CoreModule.hpp"

CoreModule::~CoreModule() {
    this->closeLib();
    std::cout << "Library closed" << std::endl;
}

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
    this->_graphicalLib.openLib(path);
    this->_handle = this->_graphicalLib.getHandle();
    this->_module = this->getLib().createLib(func);
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

std::unique_ptr<AGraphicalModule>& CoreModule::getModule() {
    return this->_module;
}

LdlWrapper& CoreModule::getLib() {
    return this->_graphicalLib;
}

void CoreModule::closeLib() {
    if (this->_handle) {
        this->_module->destroyWindow();
        this->_module.release();
        dlclose(this->_handle);
    }
}
