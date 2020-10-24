#pragma once

#include "game_object.h"

struct bullet_graphics_comp
{
  void update();

  bullet_graphics_comp(game_object &go, const graphics &gfx);

  game_object go;
  graphics gfx;
};
