#ifndef SPACESHIP1_PHYSICS_COMPONENT_H
#define SPACESHIP1_PHYSICS_COMPONENT_H

#include <cmath>

#include "game_object.h"
#include "init/constants.h"
#include "physics_comp.h"

struct spaceship1_physics_comp
{
  void update();

  game_object go;
  spaceship1_physics_comp(const game_object &go);
};

#endif
