#pragma once

#include <SDL2/SDL.h>
#include "images/Texture_shelf.h"

struct Graphics
{
    SDL_Renderer *renderer{nullptr};
    Texture_shelf texture_shelf;
};
