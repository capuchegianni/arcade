/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#include "../../include/Core/LdlWrapper.hpp"

LdlWrapper::LdlWrapper(const std::string& filename) :
    _handle(dlopen(filename.c_str(), RTLD_LAZY), dlclose) {
    if (!this->_handle.get()) {
        this->_handle.get_deleter();
        throw FileError("Failed to load library '" + filename + "'\n" + dlerror(), 84);
    }
}

template<typename T>
T LdlWrapper::getFunction(const std::string& name) {
    T func = reinterpret_cast<T>(dlsym(_handle.get(), name.c_str()));

    if (!func) {
        this->_handle.get_deleter();
        throw FileError("Failed to load symbol '" + name + "'\n" + dlerror(), 84);
    }
    return func;
}

std::unique_ptr<AGraphicalModule> LdlWrapper::createLib(const std::string& func) {
    using create_t = std::unique_ptr<AGraphicalModule> (*)();
    create_t create = this->getFunction<create_t>(func);

    return create();
}
