#pragma once

#include "Game_object.h"
#include "Graphics.h"
#include <SDL.h>
#include <vector>

struct Destroy_asteroids_scene {
  void update(SDL_Event &event, Graphics &graphics,
              std::vector<Game_object> &game_objects);
};
