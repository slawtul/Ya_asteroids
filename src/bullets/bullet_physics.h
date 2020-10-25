#ifndef BULLET_PHYSICS_H
#define BULLET_PHYSICS_H

#include "game_object.h"

struct bullet_physics: physics_comp
{
  void update(game_object &obj) override;
};

#endif // BULLET_PHYSICS_H
