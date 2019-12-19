#pragma once

#include <SDL.h>
#include <SDL_image.h>

SDL_Surface *load_image(const char *file)
{
    const auto surface = IMG_Load(file);
    if (surface == nullptr) {
        SDL_Log("Unable to load image %s", file);
        SDL_Quit();
    }
    return surface;
}
