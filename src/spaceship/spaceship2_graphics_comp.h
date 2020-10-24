#ifndef SPACESHIP2_GRAPHICS_COMPONENT_H
#define SPACESHIP2_GRAPHICS_COMPONENT_H

#include "game_object.h"

struct spaceship2_graphics_comp
{
  void update();

  spaceship2_graphics_comp(const game_object &go, const graphics &gfx);

  game_object go;
  graphics gfx;
};

#endif // SPACESHIP2_GRAPHICS_COMPONENT_H
