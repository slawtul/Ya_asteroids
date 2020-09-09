#pragma once

#include "../images/texture_shelf.h"
#include <SDL.h>

struct graphics {
  SDL_Renderer *renderer{nullptr};
  texture_shelf texture_shelf;
};
