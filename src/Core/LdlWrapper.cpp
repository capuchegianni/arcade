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

template <typename T>
T LdlWrapper::createLib(const std::string& name) {
    typedef T (*func_t)();
    func_t func = reinterpret_cast<func_t>(dlsym(this->_handle, name.c_str()));

    if (!func)
        throw FileError("Failed to load symbol '" + name + "'\n" + dlerror(), 84);
    return func();
}

template std::shared_ptr<AGraphicalModule> LdlWrapper::createLib<std::shared_ptr<AGraphicalModule>>(const std::string& name);
template std::shared_ptr<AGameModule> LdlWrapper::createLib<std::shared_ptr<AGameModule>>(const std::string& name);

void *LdlWrapper::getHandle() const {
    return this->_handle;
}

void LdlWrapper::closeLib() {
    if (this->_handle)
        dlclose(this->_handle);
}
