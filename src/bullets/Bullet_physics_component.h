#ifndef BULLET_PHYSICS_COMPONENT_H
#define BULLET_PHYSICS_COMPONENT_H

#include <cmath>
#include "init/Constants.h"
#include "Game_object.h"

struct Bullet_physics_component: Physics_component
{
    void update(Game_object &obj) override;
};

#endif //BULLET_PHYSICS_COMPONENT_H