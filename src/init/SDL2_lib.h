#pragma once

#include <SDL.h>

struct SDL2_lib
{
    void init(const uint32_t flags)
    {
        SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
        if (SDL_Init(flags) != 0)
        {
            SDL_Log("Unable to initialize SDL2 %s", SDL_GetError());
            SDL_Quit();
        }
    }

    SDL_Window *create_window(
        const char *title,
        int screen_width,
        int screen_height,
        const uint32_t flags)
    {
        const auto window = SDL_CreateWindow(
            title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            screen_width, screen_height, flags);
        if (window == nullptr)
        {
            SDL_Log("Unable to create a window %s", SDL_GetError());
            SDL_Quit();
        }
        return window;
    }

    SDL_Renderer *create_renderer(SDL_Window *window, uint32_t flags)
    {
        const auto renderer = SDL_CreateRenderer(window, -1, flags);
        if (renderer == nullptr)
        {
            SDL_Log("Unable to create renderer_ %s", SDL_GetError());
            SDL_Quit();
        }
        return renderer;
    }
};
