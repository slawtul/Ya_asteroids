#ifndef SPACESHIP2_GRAPHICS_COMPONENT_H
#define SPACESHIP2_GRAPHICS_COMPONENT_H

#include "game_object.h"

struct spaceship2_graphics_comp: graphics_comp
{
  void update(game_object &obj, graphics &graphics) override;
};

#endif // SPACESHIP2_GRAPHICS_COMPONENT_H
