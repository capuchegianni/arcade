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
    return ::SDL_CreateWindow(title, x, y, w, h, flags);
}

void SDL2Wrapper::SDL_DestroyWindow(SDL_Window *window)
{
    ::SDL_DestroyWindow(window);
}

SDL_Renderer *SDL2Wrapper::SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags)
{
    return ::SDL_CreateRenderer(window, index, flags);
}

void SDL2Wrapper::SDL_DestroyRenderer(SDL_Renderer *renderer)
{
    ::SDL_DestroyRenderer(renderer);
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

void SDL2Wrapper::SDL_SetWindowTitle(SDL_Window *window, const char *title)
{
    ::SDL_SetWindowTitle(window, title);
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
