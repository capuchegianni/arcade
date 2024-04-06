/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2Wrapper
*/

#ifndef SDL2WRAPPER_HPP_
#define SDL2WRAPPER_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_video.h>
#include "../../Libs.hpp"

class SDL2Wrapper {
    public:
        SDL2Wrapper() = default;
        ~SDL2Wrapper() = default;

        static int SDL_Init(Uint32 flags);
        static void SDL_Quit();
        static SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
        static SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags);
        static int SDL_PollEvent(SDL_Event *event);
        static void SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        static void SDL_RenderClear(SDL_Renderer *renderer);
        static void SDL_RenderPresent(SDL_Renderer *renderer);
        static void SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h);
        static void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h);
        static void SDL_SetWindowSize(SDL_Window *window, int w, int h);
        static void SDL_SetWindowTitle(SDL_Window *window, std::string title);
        static void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
        static void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
        static void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
        static void SDL_ShowWindow(SDL_Window *window);
        static void SDL_HideWindow(SDL_Window *window);
        static void SDL_DestroyRenderer(SDL_Renderer *renderer);
        static void SDL_DestroyWindow(SDL_Window *window);
        static const char *SDL_GetError();
        static SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
        static void SDL_FreeSurface(SDL_Surface *surface);
        static SDL_Surface *SDL_LoadBMPFile(const char *file);
        static void SDL_FillRect(SDL_Surface *surface, SDL_Rect *rect, Uint32 color);
        static Uint32 SDL_MapRGB(const SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b);
        static SDL_Surface *SDL_CreateSurfaceWithColor(int width, int height, Color color);
        static SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
        static void SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* rect);
        static void SDL_DestroyTexture(SDL_Texture* texture);
        static SDL_Surface *SDL_Img_Load(const char *file);
        static const char *SDL_Img_GetError();
        static TTF_Font *SDL_TTF_OpenFont(const char *file, int size);
        static void SDL_TTF_CloseFont(TTF_Font *font);
        static SDL_Surface *SDL_TTF_RenderText_Solid(TTF_Font *font, const char *text, Color color);
        static int SDL_TTF_Init();
        static void SDL_TTF_Quit();
};

#endif /* !SDL2WRAPPER_HPP_ */
