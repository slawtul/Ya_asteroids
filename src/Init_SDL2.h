#pragma once

#include <SDL2/SDL.h>

void init_SDL2(const Uint32 flags)
{
    if (SDL_Init(flags) != 0) {
        SDL_Log("Unable to initialize SDL2 %s", SDL_GetError());
        SDL_Quit();
    }
}

bool is_ESC_key_pressed()
{
    return SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_ESCAPE];
}

bool is_SPACE_key_pressed()
{
    return SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_SPACE];
}

bool is_ENTER_key_pressed()
{
    return SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RETURN];
}

SDL_Window *create_window(const char *title, int screen_width, int screen_height, const Uint32 flags)
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

SDL_Renderer *create_renderer(SDL_Window *window, Uint32 flags)
{
    const auto renderer = SDL_CreateRenderer(window, -1, flags);
    if (renderer == nullptr) {
        SDL_Log("Unable to create renderer_ %s", SDL_GetError());
        SDL_Quit();
    }
    return renderer;
}

void log_screen_size(SDL_Renderer *renderer)
{
    int screen_width, screen_height;
    int result = SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height);
    if (result != 0) {
        SDL_Log("Unable to get render output size %s", SDL_GetError());
        SDL_Quit();
    }
    SDL_LogInfo(0, "Init screen size %dx%d", screen_width, screen_height);
}
