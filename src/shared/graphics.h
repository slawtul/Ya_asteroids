#pragma once

#include "../images/texture_shelf.h"
#include <SDL.h>

struct graphics
{
    SDL_Renderer *renderer;
    texture_shelf tex_shelf;
};
