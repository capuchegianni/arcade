/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Main
*/

#include "../../include/Core/CoreModule.hpp"

int main(int ac, char **av) {
    CoreModule core;

    try {
        if (ac != 2)
            throw FileError("Invalid number of arguments");
        core.checkFile(av[1]);
        core.loadLibrary(av[1], "createLib");
        core.getModule()->initWindow();
    } catch (const Error& e) {
        std::cerr << e.getType() << ": " << e.what() << std::endl;
        std::cerr << "Exiting with status " << e.getStatus() << std::endl;
        return 84;
    }
    std::cout << "Hello, Core!" << std::endl;
}
