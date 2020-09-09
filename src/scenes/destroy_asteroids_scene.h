#pragma once

#include "game_object.h"
#include "graphics.h"
#include <SDL.h>
#include <vector>

struct destroy_asteroids_scene {
  void update(SDL_Event &event, graphics &graphics,
              std::vector<game_object> &game_objects);
};
