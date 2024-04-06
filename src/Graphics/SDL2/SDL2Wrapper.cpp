/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2Wrapper
*/

#include "../../../include/Graphics/SDL2/SDL2Wrapper.hpp"

int SDL2Wrapper::SDL_Init(Uint32 flags)
{
    return ::SDL_Init(flags);
}

void SDL2Wrapper::SDL_Quit()
{
    ::SDL_Quit();
}

SDL_Window *SDL2Wrapper::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    return (::SDL_CreateWindow(title, x, y, w, h, flags));
}

SDL_Renderer *SDL2Wrapper::SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags)
{
    return (::SDL_CreateRenderer(window, index, flags));
}

int SDL2Wrapper::SDL_PollEvent(SDL_Event *event)
{
    return ::SDL_PollEvent(event);
}

void SDL2Wrapper::SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    ::SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDL2Wrapper::SDL_RenderClear(SDL_Renderer *renderer)
{
    ::SDL_RenderClear(renderer);
}

void SDL2Wrapper::SDL_RenderPresent(SDL_Renderer *renderer)
{
    ::SDL_RenderPresent(renderer);
}

void SDL2Wrapper::SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h)
{
    ::SDL_SetWindowMaximumSize(window, max_w, max_h);
}

void SDL2Wrapper::SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h)
{
    ::SDL_SetWindowMinimumSize(window, min_w, min_h);
}

void SDL2Wrapper::SDL_SetWindowSize(SDL_Window *window, int w, int h)
{
    ::SDL_SetWindowSize(window, w, h);
}

void SDL2Wrapper::SDL_SetWindowTitle(SDL_Window *window, std::string title)
{
    ::SDL_SetWindowTitle(window, title.c_str());
}

void SDL2Wrapper::SDL_SetWindowPosition(SDL_Window *window, int x, int y)
{
    ::SDL_SetWindowPosition(window, x, y);
}

void SDL2Wrapper::SDL_GetWindowSize(SDL_Window *window, int *w, int *h)
{
    ::SDL_GetWindowSize(window, w, h);
}

void SDL2Wrapper::SDL_GetWindowPosition(SDL_Window *window, int *x, int *y)
{
    ::SDL_GetWindowPosition(window, x, y);
}

void SDL2Wrapper::SDL_ShowWindow(SDL_Window *window)
{
    ::SDL_ShowWindow(window);
}

void SDL2Wrapper::SDL_HideWindow(SDL_Window *window)
{
    ::SDL_HideWindow(window);
}

void SDL2Wrapper::SDL_DestroyRenderer(SDL_Renderer *renderer)
{
    ::SDL_DestroyRenderer(renderer);
}

void SDL2Wrapper::SDL_DestroyWindow(SDL_Window *window)
{
    ::SDL_DestroyWindow(window);
}

const char *SDL2Wrapper::SDL_GetError()
{
    return ::SDL_GetError();
}

SDL_Surface *SDL2Wrapper::SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
    return ::SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);
}

void SDL2Wrapper::SDL_FreeSurface(SDL_Surface *surface)
{
    ::SDL_FreeSurface(surface);
}

SDL_Surface *SDL2Wrapper::SDL_LoadBMPFile(const char *file)
{
    return ::SDL_LoadBMP(file);
}

void SDL2Wrapper::SDL_FillRect(SDL_Surface *surface, SDL_Rect *rect, Uint32 color)
{
    ::SDL_FillRect(surface, rect, color);
}

Uint32 SDL2Wrapper::SDL_MapRGB(const SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b)
{
    return ::SDL_MapRGB(format, r, g, b);
}

SDL_Surface *SDL2Wrapper::SDL_CreateSurfaceWithColor(int width, int height, Color color)
{
    SDL_Surface *surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, color.r, color.g, color.b));
    return surface;
}

SDL_Texture *SDL2Wrapper::SDL_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return ::SDL_CreateTextureFromSurface(renderer, surface);
}

void SDL2Wrapper::SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *rect)
{
    ::SDL_RenderCopy(renderer, texture, NULL, rect);
}

void SDL2Wrapper::SDL_DestroyTexture(SDL_Texture *texture)
{
    ::SDL_DestroyTexture(texture);
}

SDL_Surface *SDL2Wrapper::SDL_Img_Load(const char *file)
{
    return ::IMG_Load(file);
}

const char *SDL2Wrapper::SDL_Img_GetError()
{
    return ::IMG_GetError();
}

TTF_Font *SDL2Wrapper::SDL_TTF_OpenFont(const char *file, int size) {
    return ::TTF_OpenFont(file, size);
}

void SDL2Wrapper::SDL_TTF_CloseFont(TTF_Font *font) {
    ::TTF_CloseFont(font);
}

SDL_Surface *SDL2Wrapper::SDL_TTF_RenderText_Solid(TTF_Font *font, const char *text, Color color) {
    SDL_Color sdl_color;

    sdl_color.r = (color.r >= 0 && color.r <= 255) ? color.r : 255;
    sdl_color.g = (color.g >= 0 && color.g <= 255) ? color.g : 255;
    sdl_color.b = (color.b >= 0 && color.b <= 255) ? color.b : 255;
    sdl_color.a = (color.a >= 0 && color.a <= 255) ? color.a : 255;
    return ::TTF_RenderText_Solid(font, text, sdl_color);
}

void SDL2Wrapper::SDL_TTF_Quit() {
    return ::TTF_Quit();
}

int SDL2Wrapper::SDL_TTF_Init() {
    return ::TTF_Init();
}
