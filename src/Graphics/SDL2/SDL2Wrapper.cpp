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

std::shared_ptr<SDL_Window> SDL2Wrapper::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    return std::shared_ptr<SDL_Window>(::SDL_CreateWindow(title, x, y, w, h, flags), SDL_DestroyWindow);
}

std::shared_ptr<SDL_Renderer> SDL2Wrapper::SDL_CreateRenderer(std::shared_ptr<SDL_Window> window, int index, Uint32 flags)
{
    return std::shared_ptr<SDL_Renderer>(::SDL_CreateRenderer(window.get(), index, flags), SDL_DestroyRenderer);
}

void SDL2Wrapper::SDL_RenderClear(std::shared_ptr<SDL_Renderer> renderer)
{
    ::SDL_RenderClear(renderer.get());
}

void SDL2Wrapper::SDL_RenderPresent(std::shared_ptr<SDL_Renderer> renderer)
{
    ::SDL_RenderPresent(renderer.get());
}

void SDL2Wrapper::SDL_SetWindowMaximumSize(std::shared_ptr<SDL_Window> window, int max_w, int max_h)
{
    ::SDL_SetWindowMaximumSize(window.get(), max_w, max_h);
}

void SDL2Wrapper::SDL_SetWindowMinimumSize(std::shared_ptr<SDL_Window> window, int min_w, int min_h)
{
    ::SDL_SetWindowMinimumSize(window.get(), min_w, min_h);
}

void SDL2Wrapper::SDL_SetWindowSize(std::shared_ptr<SDL_Window> window, int w, int h)
{
    ::SDL_SetWindowSize(window.get(), w, h);
}

void SDL2Wrapper::SDL_SetWindowTitle(std::shared_ptr<SDL_Window> window, std::string title)
{
    ::SDL_SetWindowTitle(window.get(), title.c_str());
}

void SDL2Wrapper::SDL_SetWindowPosition(std::shared_ptr<SDL_Window> window, int x, int y)
{
    ::SDL_SetWindowPosition(window.get(), x, y);
}

void SDL2Wrapper::SDL_GetWindowSize(std::shared_ptr<SDL_Window> window, std::shared_ptr<int> w, std::shared_ptr<int> h)
{
    ::SDL_GetWindowSize(window.get(), w.get(), h.get());
}

void SDL2Wrapper::SDL_GetWindowPosition(std::shared_ptr<SDL_Window> window, std::shared_ptr<int> x, std::shared_ptr<int> y)
{
    ::SDL_GetWindowPosition(window.get(), x.get(), y.get());
}

void SDL2Wrapper::SDL_ShowWindow(std::shared_ptr<SDL_Window> window)
{
    ::SDL_ShowWindow(window.get());
}

void SDL2Wrapper::SDL_HideWindow(std::shared_ptr<SDL_Window> window)
{
    ::SDL_HideWindow(window.get());
}
