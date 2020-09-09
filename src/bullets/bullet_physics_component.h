#ifndef BULLET_PHYSICS_COMPONENT_H
#define BULLET_PHYSICS_COMPONENT_H

#include "game_object.h"

struct bullet_physics_component : physics_component {
  void update(game_object &obj) override;
};

#endif // BULLET_PHYSICS_COMPONENT_H
