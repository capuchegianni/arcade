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

void Sdl2GraphicalModule::initWindow(const std::string& name, const std::vector<int>& size) {
    SDL2Wrapper::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    this->_window = SDL2Wrapper::SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size[0], size[1], SDL_WINDOW_SHOWN);
    this->_renderer = SDL2Wrapper::SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    this->_isOpen = true;
}

void Sdl2GraphicalModule::destroyWindow() {
    SDL2Wrapper::SDL_DestroyWindow(this->_window);
    SDL2Wrapper::SDL_Quit();
    this->_isOpen = false;
}

void Sdl2GraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    this->initWindow(name, size);
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

void Sdl2GraphicalModule::clearWindow(Color color) {
    SDL2Wrapper::SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
    SDL2Wrapper::SDL_RenderClear(this->_renderer);
}

bool Sdl2GraphicalModule::isWindowOpen() {
    return this->_isOpen;
}

void Sdl2GraphicalModule::parseKeyboard() {
    while (SDL2Wrapper::SDL_PollEvent(&this->_event)) {
        if (this->_event.type == SDL_QUIT || (this->_event.type == SDL_WINDOWEVENT && this->_event.window.event == SDL_WINDOWEVENT_CLOSE)) {
            this->destroyWindow();
        }
    }
}

void Sdl2GraphicalModule::displayText(const std::string& text, const std::vector<int>& pos, const int& size, const Color& color) {
    (void)text;
    (void)pos;
    (void)size;
    (void)color;
    return;
}

std::any Sdl2GraphicalModule::initText(const std::string& text) {
    (void)text;
    return std::any();
}

void Sdl2GraphicalModule::setTextColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFont(const std::any& text, const std::string& path) {
    (void)text;
    (void)path;
    return;
}

void Sdl2GraphicalModule::setTextOutline(const std::any& text, const bool& hasOutline) {
    (void)text;
    (void)hasOutline;
    return;
}

void Sdl2GraphicalModule::setTextOutlineThickness(const std::any& text, const int& thickness) {
    (void)text;
    (void)thickness;
    return;
}

void Sdl2GraphicalModule::setTextOutlineColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextFillColor(const std::any& text, const Color& color) {
    (void)text;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setTextSize(const std::any& text, const int& size) {
    (void)text;
    (void)size;
    return;
}

void Sdl2GraphicalModule::setTextPosition(const std::any& text, const std::vector<int>& pos) {
    (void)text;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::setTextOrigin(const std::any& text, const std::vector<int>& origin) {
    (void)text;
    (void)origin;
    return;
}

void Sdl2GraphicalModule::drawRectangle(const std::vector<int>& size, const std::vector<int>& pos, const Color& color) {
    (void)size;
    (void)pos;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setRectangleColor(std::any& rect, const Color& color) {
    (void)rect;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setRectangleSize(std::any& rect, const std::vector<int>& size) {
    (void)rect;
    (void)size;
    return;
}

void Sdl2GraphicalModule::setRectanglePosition(std::any& rect, const std::vector<int>& pos) {
    (void)rect;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::drawCircle(const int& rad, const std::vector<int>& pos, const Color& color) {
    (void)rad;
    (void)pos;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setCircleColor(std::any& circle, const Color& color) {
    (void)circle;
    (void)color;
    return;
}

void Sdl2GraphicalModule::setCircleRadius(std::any& circle, const int& rad) {
    (void)circle;
    (void)rad;
    return;
}

void Sdl2GraphicalModule::setCirclePosition(std::any& circle, const std::vector<int>& pos) {
    (void)circle;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::displaySprite(const std::string& path, const std::vector<int>& pos, const std::vector<float>& scale, const float& rotation, const std::vector<int>& origin, const Color& color) {
    (void)path;
    (void)pos;
    (void)scale;
    (void)rotation;
    (void)origin;
    (void)color;
    return;
}

std::any Sdl2GraphicalModule::initSprite(const std::string& path) {
    (void)path;
    return std::any();
}

void Sdl2GraphicalModule::setSpriteTexture(std::any sprite, const std::string& path) {
    (void)sprite;
    (void)path;
    return;
}

void Sdl2GraphicalModule::setSpritePosition(std::any sprite, const std::vector<int>& pos) {
    (void)sprite;
    (void)pos;
    return;
}

void Sdl2GraphicalModule::setSpriteScale(std::any sprite, const std::vector<float>& scale) {
    (void)sprite;
    (void)scale;
    return;
}

void Sdl2GraphicalModule::setSpriteRotation(std::any sprite, const float& rotation) {
    (void)sprite;
    (void)rotation;
    return;
}
