#ifndef BULLET_PHYSICS_COMPONENT_H
#define BULLET_PHYSICS_COMPONENT_H

#include "game_object.h"

struct bullet_physics_comp
{
  void update();
  bullet_physics_comp(const game_object &go);
  game_object go;
};

#endif // BULLET_PHYSICS_COMPONENT_H
