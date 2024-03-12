/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Error
*/

#pragma once

#include <iostream>

class Error : public std::exception {
    public:
        Error(std::string const message, int status = 84);
        ~Error() = default;

        const char *what() const noexcept;
        int getStatus() const;

    protected:
        std::string _message;
        int _status;
};

class FileError : public Error {
    public:
        FileError(std::string const message, int status = 84);
        ~FileError() = default;
};

class NcursesError : public Error {
    public:
        NcursesError(std::string const message, int status = 84);
        ~NcursesError() = default;
};

class SfmlError : public Error {
    public:
        SfmlError(std::string const message, int status = 84);
        ~SfmlError() = default;
};

class Sdl2Error : public Error {
    public:
        Sdl2Error(std::string const message, int status = 84);
        ~Sdl2Error() = default;
};
