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
            throw FileError("Invalid number of arguments\nUSAGE: ./arcade path_to_graphical_library.so");
        core.checkFile(av[1]);
        core.loadGraphicalLibrary(av[1], "createLib");
        core.getGraphicalModule()->createWindow("Arcade", {500, 500});
        std::cout << core.getGraphicalModule()->getLibraryType() << " window created" << std::endl;
        while (core.getGraphicalModule()->isWindowOpen()) {
            core.getGraphicalModule()->displayWindow();
            core.getGraphicalModule()->parseKeyboard();
        }
    } catch (const Error& e) {
        std::cerr << e.getType() << ": " << e.what() << std::endl;
        std::cerr << "Exiting with status " << e.getStatus() << std::endl;
        return 84;
    }
}
