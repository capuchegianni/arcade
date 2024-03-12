/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Error
*/

#include "Errors.hpp"

Error::Error(std::string const& message, int status) :
    _message(message),
    _status(status) { }

const char *Error::what() const noexcept {
    return this->_message.c_str();
}

int Error::getStatus() const {
    return this->_status;
}

FileError::FileError(std::string const& message, int status) :
    Error(message, status) { }

NcursesError::NcursesError(std::string const& message, int status) :
    Error(message, status) { }

SfmlError::SfmlError(std::string const& message, int status) :
    Error(message, status) { }

Sdl2Error::Sdl2Error(std::string const& message, int status) :
    Error(message, status) { }
