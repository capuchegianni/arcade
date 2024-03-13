/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Error
*/

#include "../../include/Errors.hpp"

Error::Error(std::string const message, int status) :
    _message(message),
    _status(status) {
    this->_type = "Error";
}

const char *Error::what() const noexcept {
    return this->_message.c_str();
}

int Error::getStatus() const {
    return this->_status;
}

std::string Error::getType() const {
    return this->_type;
}

FileError::FileError(std::string const message, int status) :
    Error(message, status) {
    this->_type = "FileError";
}

NcursesError::NcursesError(std::string const message, int status) :
    Error(message, status) {
    this->_type = "NcursesError";
}

SfmlError::SfmlError(std::string const message, int status) :
    Error(message, status) {
    this->_type = "SfmlError";
}

Sdl2Error::Sdl2Error(std::string const message, int status) :
    Error(message, status) {
    this->_type = "Sdl2Error";
}
