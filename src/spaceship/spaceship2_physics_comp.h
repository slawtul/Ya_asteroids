#ifndef SPACESHIP2_PHYSICS_COMPONENT_H
#define SPACESHIP2_PHYSICS_COMPONENT_H

#include <cmath>

#include "game_object.h"
#include "init/constants.h"
#include "physics_comp.h"

struct spaceship2_physics_comp
{
  void update();
  spaceship2_physics_comp(const game_object &go);
  game_object go;
};

#endif // SPACESHIP2_PHYSICS_COMPONENT_H
