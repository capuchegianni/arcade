/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#include "../../include/Core/LdlWrapper.hpp"

LdlWrapper::LdlWrapper(const std::string& path) :
    _handle(dlopen(path.c_str(), RTLD_LAZY)) {
    if (!this->_handle)
        throw FileError("Failed to open library '" + path + "'\n" + dlerror(), 84);
}

void LdlWrapper::openLib(const std::string& path) {
    if (this->_handle)
        dlclose(this->_handle);
    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!this->_handle)
        throw FileError("Failed to open library '" + path + "'\n" + dlerror(), 84);
}

template<typename T>
T LdlWrapper::getFunction(const std::string& name) {
    T func = reinterpret_cast<T>(dlsym(this->_handle, name.c_str()));

    if (!func)
        throw FileError("Failed to load symbol '" + name + "'\n" + dlerror(), 84);
    return func;
}

std::shared_ptr<AGraphicalModule> LdlWrapper::createLib(const std::string& func) {
    return this->getFunction<std::shared_ptr<AGraphicalModule> (*)()>(func)();
}

void *LdlWrapper::getHandle() const {
    return this->_handle;
}
