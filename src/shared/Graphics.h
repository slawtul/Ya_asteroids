#pragma once

#include "images/Texture_shelf.h"
#include <SDL.h>

struct Graphics {
  SDL_Renderer *renderer{nullptr};
  Texture_shelf texture_shelf;
};
