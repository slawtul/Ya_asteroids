#ifndef SPACESHIP1_GRAPHICS_COMPONENT_H
#define SPACESHIP1_GRAPHICS_COMPONENT_H

#include "game_object.h"

struct spaceship1_graphics_comp
{
  void update();

  spaceship1_graphics_comp(const game_object &go, const graphics &gfx);

  game_object go;
  graphics gfx;
};

#endif // SPACESHIP1_GRAPHICS_COMPONENT_H
