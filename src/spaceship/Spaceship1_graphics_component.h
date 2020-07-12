#ifndef SPACESHIP1_GRAPHICS_COMPONENT_H
#define SPACESHIP1_GRAPHICS_COMPONENT_H

#include "Game_object.h"

struct Spaceship1_graphics_component : Graphics_component {
  void update(Game_object &obj, Graphics &graphics) override;
};

#endif // SPACESHIP1_GRAPHICS_COMPONENT_H
