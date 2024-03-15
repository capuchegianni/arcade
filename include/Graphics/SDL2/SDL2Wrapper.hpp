/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2Wrapper
*/

#ifndef SDL2WRAPPER_HPP_
#define SDL2WRAPPER_HPP_

#include <SDL2/SDL.h>
#include <memory>
#include <string>

class SDL2Wrapper {
    public:
        SDL2Wrapper() = default;
        ~SDL2Wrapper() = default;

        static int SDL_Init(Uint32 flags);
        static void SDL_Quit();
        static std::shared_ptr<SDL_Window> SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
        static std::shared_ptr<SDL_Renderer> SDL_CreateRenderer(std::shared_ptr<SDL_Window> window, int index, Uint32 flags);
        static void SDL_RenderClear(std::shared_ptr<SDL_Renderer> renderer);
        static void SDL_RenderPresent(std::shared_ptr<SDL_Renderer> renderer);
        static void SDL_SetWindowMaximumSize(std::shared_ptr<SDL_Window> window, int max_w, int max_h);
        static void SDL_SetWindowMinimumSize(std::shared_ptr<SDL_Window> window, int min_w, int min_h);
        static void SDL_SetWindowSize(std::shared_ptr<SDL_Window> window, int w, int h);
        static void SDL_SetWindowTitle(std::shared_ptr<SDL_Window> window, std::string title);
        static void SDL_SetWindowPosition(std::shared_ptr<SDL_Window> window, int x, int y);
        static void SDL_GetWindowSize(std::shared_ptr<SDL_Window> window, std::shared_ptr<int> w, std::shared_ptr<int> h);
        static void SDL_GetWindowPosition(std::shared_ptr<SDL_Window> window, std::shared_ptr<int> x, std::shared_ptr<int> y);
        static void SDL_ShowWindow(std::shared_ptr<SDL_Window> window);
        static void SDL_HideWindow(std::shared_ptr<SDL_Window> window);
};

#endif /* !SDL2WRAPPER_HPP_ */
