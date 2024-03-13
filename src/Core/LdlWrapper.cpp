/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#include "../../include/Core/LdlWrapper.hpp"

LdlWrapper::LdlWrapper(const std::string filename) :
    _handle(dlopen(filename.c_str(), RTLD_LAZY), dlclose) {
    void *handle = dlopen(filename.c_str(), RTLD_LAZY);

    if (!handle)
        throw FileError("Failed to load library '" + filename + "'\n" + dlerror(), 84);
}

template<typename T>
T LdlWrapper::getFunction(const std::string& name) {
    T func = reinterpret_cast<T>(dlsym(_handle.get(), name.c_str()));

    if (!func)
        throw FileError("Failed to load symbol '" + name + "'\n" + dlerror(), 84);
    return func;
}

std::unique_ptr<AGraphicalModule> LdlWrapper::createModule() {
    using create_t = std::unique_ptr<AGraphicalModule> (*)();
    create_t create = this->getFunction<create_t>("createModule");

    return create();
}
