/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl2GraphicalModule
*/

#include "../../../include/Graphics/SDL2/Sdl2GraphicalModule.hpp"

Sdl2GraphicalModule::Sdl2GraphicalModule() :
    AGraphicalModule("SDL2") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib() {
    return std::make_shared<Sdl2GraphicalModule>();
}

void Sdl2GraphicalModule::destroyWindow() {
    if (this->_renderer) {
        SDL2Wrapper::SDL_DestroyRenderer(this->_renderer);
        this->_renderer = nullptr;
    }
    if (this->_window) {
        SDL2Wrapper::SDL_DestroyWindow(this->_window);
        this->_window = nullptr;
    }
    SDL2Wrapper::SDL_Quit();
    this->_isOpen = false;
}

void Sdl2GraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    SDL2Wrapper::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    this->_window = SDL2Wrapper::SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size[0], size[1], SDL_WINDOW_SHOWN);
    this->_renderer = SDL2Wrapper::SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    this->_isOpen = true;
    this->setWindowTitle(name);
    this->setWindowSize(size);
}

void Sdl2GraphicalModule::setWindowSize(const std::vector<int> &size) {
    SDL2Wrapper::SDL_SetWindowSize(this->_window, size[0], size[1]);
}

void Sdl2GraphicalModule::setWindowTitle(const std::string &title) {
    SDL2Wrapper::SDL_SetWindowTitle(this->_window, title.c_str());
}

void Sdl2GraphicalModule::displayWindow() {
    SDL2Wrapper::SDL_RenderPresent(this->_renderer);
}

bool Sdl2GraphicalModule::isWindowOpen() {
    return this->_isOpen;
}

Input Sdl2GraphicalModule::parseKeyboard() {
    while (SDL2Wrapper::SDL_PollEvent(&this->_event)) {
        if (this->_event.type == SDL_QUIT)
            return ESC;
        if (this->_event.type == SDL_WINDOWEVENT && this->_event.window.event == SDL_WINDOWEVENT_CLOSE)
            return ESC;
        if (this->_event.type == SDL_KEYDOWN) {
            if (this->_event.key.keysym.sym == SDLK_ESCAPE)
                return ESC;
            if (this->_event.key.keysym.sym == SDLK_UP)
                return CHANGE_GAME;
            if (this->_event.key.keysym.sym == SDLK_RIGHT)
                return CHANGE_LIB;
            if (this->_event.key.keysym.sym == SDLK_TAB)
                return MENU;
        }
    }
    return NONE;
}

void Sdl2GraphicalModule::showMap(std::vector<std::vector<Tiles>> &map) {
    (void)map;
    return;
}

void Sdl2GraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities) {
    (void)entities;
    return;
}
