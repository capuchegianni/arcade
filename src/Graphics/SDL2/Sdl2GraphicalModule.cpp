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
    for (auto &asset : this->_assets) {
        SDL2Wrapper::SDL_DestroyTexture(asset.second);
    }
    this->_assets.clear();
    if (this->_renderer) {
        SDL2Wrapper::SDL_DestroyRenderer(this->_renderer);
        this->_renderer = nullptr;
    }
    if (this->_window) {
        SDL2Wrapper::SDL_DestroyWindow(this->_window);
        this->_window = nullptr;
    }
    SDL2Wrapper::SDL_Quit();
    SDL2Wrapper::SDL_TTF_Quit();
    this->_isOpen = false;
}

void Sdl2GraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    if (SDL2Wrapper::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
        throw Sdl2Error(SDL2Wrapper::SDL_GetError());
    this->_window = SDL2Wrapper::SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size[0], size[1], SDL_WINDOW_SHOWN);
    if (!this->_window)
        throw Sdl2Error(SDL2Wrapper::SDL_GetError());
    this->_renderer = SDL2Wrapper::SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->_renderer)
        throw Sdl2Error(SDL2Wrapper::SDL_GetError());
    if (SDL2Wrapper::SDL_TTF_Init() < 0)
        throw Sdl2Error(SDL2Wrapper::SDL_GetError());
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
            if (this->_event.key.keysym.sym == SDLK_r)
                return RELOAD;
            if (this->_event.key.keysym.sym == SDLK_RETURN)
                return ENTER;
            if (this->_event.key.keysym.sym == SDLK_SPACE)
                return SPACE;
            if (this->_event.key.keysym.sym == SDLK_z)
                return UP;
            if (this->_event.key.keysym.sym == SDLK_s)
                return DOWN;
            if (this->_event.key.keysym.sym == SDLK_q)
                return LEFT;
            if (this->_event.key.keysym.sym == SDLK_d)
                return RIGHT;
        }
    }
    return NONE;
}

static void displayBackground(SDL_Window *win, const std::map<std::string, SDL_Texture*> &assets, SDL_Renderer *renderer) {
    if (assets.empty() || assets.find("Background") == assets.end())
        return;

    SDL_Texture *texture = assets.at("Background");
    int windowX = 0;
    int windowY = 0;

    SDL2Wrapper::SDL_GetWindowSize(win, &windowX, &windowY);
    SDL_Rect rect = {0, 0, windowX, windowY};
    SDL2Wrapper::SDL_RenderCopy(renderer, texture, &rect);
}

static void displayButton(const std::shared_ptr<AEntities>& entity, const std::map<std::string, SDL_Texture*>& assets, SDL_Renderer *renderer) {
    if (assets.empty() || assets.find(entity->getName()) == assets.end())
        return;

    SDL_Texture* texture = assets.at(entity->getName());
    if (entity->getName() == "Arrow") {
        SDL_Rect rect = {entity->getPos().first + 15, entity->getPos().second + 8, 25, 25};

        SDL2Wrapper::SDL_RenderCopy(renderer, texture, &rect);
    } else {
        TTF_Font *font = SDL2Wrapper::SDL_TTF_OpenFont("assets/fonts/arial/arial_bold.ttf", 12);
        if (!font)
            throw Sdl2Error(SDL2Wrapper::SDL_GetError());
        SDL_Surface *surface = SDL2Wrapper::SDL_TTF_RenderText_Solid(font, entity->imageToDisplay().first.c_str(), Color(0, 0, 0));
        if (!surface)
            throw Sdl2Error(SDL2Wrapper::SDL_GetError());
        SDL_Texture *textTexture = SDL2Wrapper::SDL_CreateTextureFromSurface(renderer, surface);
        if (!textTexture)
            throw Sdl2Error(SDL2Wrapper::SDL_GetError());
        SDL_Rect rect = {entity->getPos().first + 15, entity->getPos().second + 8, 150, 32};

        SDL2Wrapper::SDL_RenderCopy(renderer, texture, &rect);
        SDL2Wrapper::SDL_RenderCopy(renderer, textTexture, &rect);
        SDL2Wrapper::SDL_FreeSurface(surface);
        SDL2Wrapper::SDL_TTF_CloseFont(font);
        SDL2Wrapper::SDL_DestroyTexture(textTexture);
    }
}

void Sdl2GraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map) {
    int windowX = 0;
    int windowY = 0;

    SDL2Wrapper::SDL_GetWindowSize(this->_window, &windowX, &windowY);
    SDL2Wrapper::SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL2Wrapper::SDL_RenderClear(this->_renderer);
    displayBackground(this->_window, this->_assets, this->_renderer);
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            SDL_Rect rect = {
                static_cast<int>(j * (windowX / map[0].size())),
                static_cast<int>(i * (windowY / map.size())),
                static_cast<int>(windowX / map[0].size()),
                static_cast<int>(windowY / map.size())
            };

            for (size_t k = 0; k < map[i][j].getEntities().size(); k++) {
                std::shared_ptr<AEntities> entity = map[i][j].getEntities()[k];

                if (entity->getType() == BUTTON)
                    displayButton(entity, this->_assets, this->_renderer);
                else
                    SDL2Wrapper::SDL_RenderCopy(this->_renderer, this->_assets[entity->getName()], &rect);
            }
        }
    }
}

void Sdl2GraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities) {
    this->_assets.clear();
    for (int i = entities.size() - 1; i >= 0; i--) {
        std::shared_ptr<AEntities> entity = entities[i];

        if (entity->getType() == BUTTON || entity->getType() == BACKGROUND) {
            SDL_Surface *surface = SDL2Wrapper::SDL_Img_Load(entity->imageToDisplay().first.c_str());

            if (!surface)
                throw Sdl2Error(SDL2Wrapper::SDL_Img_GetError());
            SDL_Texture *texture = SDL2Wrapper::SDL_CreateTextureFromSurface(this->_renderer, surface);

            if (!texture)
                throw Sdl2Error(SDL2Wrapper::SDL_GetError());
            this->_assets[entity->getName()] = texture;
            SDL2Wrapper::SDL_FreeSurface(surface);
        } else {
            Color color = entity->imageToDisplay().second.getColor();
            SDL_Surface *surface = SDL2Wrapper::SDL_CreateSurfaceWithColor(1, 1, color);
            SDL_Texture *texture = SDL2Wrapper::SDL_CreateTextureFromSurface(this->_renderer, surface);

            if (!texture)
                throw Sdl2Error(SDL2Wrapper::SDL_GetError());
            this->_assets[entity->getName()] = texture;
            SDL2Wrapper::SDL_FreeSurface(surface);
        }
    }
}
