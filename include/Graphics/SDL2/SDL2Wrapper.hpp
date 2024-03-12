/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2Wrapper
*/

#ifndef SDL2WRAPPER_HPP_
#define SDL2WRAPPER_HPP_

#include <SDL2/SDL.h>

class SDL2Wrapper {
    public:
        SDL2Wrapper() = default;
        ~SDL2Wrapper() = default;

        int SDL_Init(Uint32 flags);
        void SDL_Quit();
        SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
        void SDL_DestroyWindow(SDL_Window *window);
        SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags);
        void SDL_DestroyRenderer(SDL_Renderer *renderer);
        void SDL_RenderClear(SDL_Renderer *renderer);
        void SDL_RenderPresent(SDL_Renderer *renderer);
        void SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h);
        void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h);
        void SDL_SetWindowSize(SDL_Window *window, int w, int h);
        void SDL_SetWindowTitle(SDL_Window *window, const char *title);
        void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
        void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
        void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
        void SDL_ShowWindow(SDL_Window *window);
        void SDL_HideWindow(SDL_Window *window);
};

#endif /* !SDL2WRAPPER_HPP_ */
