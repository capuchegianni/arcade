/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Main
*/

#include <iostream>
#include "../../include/Errors.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2)
            throw FileError("Invalid number of arguments");
    } catch (const Error& e) {
        std::cerr << e.getType() << ": " << e.what() << std::endl;
        std::cerr << "Exiting with status " << e.getStatus() << std::endl;
        return 84;
    }
    std::cout << "Hello, Core!" << std::endl;
}
