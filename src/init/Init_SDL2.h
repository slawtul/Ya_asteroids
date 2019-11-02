#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Init_SDL2
{
    static void init_SDL2(const Uint32 flags)
    {
        SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
        if (SDL_Init(flags) != 0) {
            SDL_Log("Unable to initialize SDL2 %s", SDL_GetError());
            SDL_Quit();
        }
    }

    static SDL_Window *create_window(const char *title, int screen_width, int screen_height, const Uint32 flags)
    {
        const auto window = SDL_CreateWindow(
            title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, flags
        );
        if (window == nullptr) {
            SDL_Log("Unable to create a window %s", SDL_GetError());
            SDL_Quit();
        }
        return window;
    }

    static SDL_Renderer *create_renderer(SDL_Window *window, Uint32 flags)
    {
        const auto renderer = SDL_CreateRenderer(window, -1, flags);
        if (renderer == nullptr) {
            SDL_Log("Unable to create renderer_ %s", SDL_GetError());
            SDL_Quit();
        }
        return renderer;
    }

    static SDL_Surface *load_image(const char *file)
    {
        const auto surface = IMG_Load(file);
        if (surface == nullptr) {
            SDL_Log("Unable to load image %s", file);
            SDL_Quit();
        }
        return surface;
    }
};
