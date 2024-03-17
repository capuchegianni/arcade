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
        static SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
        static SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags);
        static void SDL_RenderClear(SDL_Renderer *renreder);
        static void SDL_RenderPresent(SDL_Renderer *renreder);
        static void SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h);
        static void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h);
        static void SDL_SetWindowSize(SDL_Window *window, int w, int h);
        static void SDL_SetWindowTitle(SDL_Window *window, std::string title);
        static void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
        static void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
        static void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
        static void SDL_ShowWindow(SDL_Window *window);
        static void SDL_HideWindow(SDL_Window *window);
        static void SDL_DestroyWindow(SDL_Window *window);
};

#endif /* !SDL2WRAPPER_HPP_ */
