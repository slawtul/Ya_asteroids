#pragma once

#include <SDL2/SDL.h>

struct Graphics_debug_info
{
    static void log_screen_size(SDL_Renderer *renderer)
    {
        int screen_width, screen_height;
        int result = SDL_GetRendererOutputSize(renderer, &screen_width, &screen_height);
        if (result != 0) {
            SDL_Log("Unable to get render output size %s", SDL_GetError());
            SDL_Quit();
        }
        SDL_LogInfo(0, "Init screen size %dx%d", screen_width, screen_height);
    }

};