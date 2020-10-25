#ifndef SPACESHIP1_GRAPHICS_COMPONENT_H
#define SPACESHIP1_GRAPHICS_COMPONENT_H

#include "game_object.h"

struct spaceship1_gfx: gfx_comp
{
  void update(game_object &obj, graphics &graphics) override;
};

#endif // SPACESHIP1_GRAPHICS_COMPONENT_H
