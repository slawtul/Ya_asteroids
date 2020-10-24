#pragma once

#include <iostream>
#include <memory>

#include "game_object_meta.h"
#include "game_object_motion.h"
#include "graphics_comp.h"
#include "input_comp.h"
#include "physics_comp.h"

struct game_object
{
  game_object_meta meta{};
  game_object_motion motion{};
  SDL_Rect rect{};

  game_object() = default;
};
