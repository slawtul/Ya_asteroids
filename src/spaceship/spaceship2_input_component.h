#pragma once

#include "game_object.h"

struct spaceship2_input_component: input_comp
{
  void update(game_object &obj) override
  {
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_D]) {
      obj.motion.angle += 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_A]) {
      obj.motion.angle -= 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_W]) {
      obj.motion.acceleration = 0.6;
      obj.motion.max_speed = 8.0;
    }
    else {
      obj.motion.acceleration = 0.2;
      obj.motion.max_speed = 6.0;
    }
  }
};
