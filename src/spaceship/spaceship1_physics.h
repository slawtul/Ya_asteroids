#pragma once

#include <cmath>

#include "game_object.h"
#include "init/constants.h"

struct spaceship1_physics : physics_comp
{
    void update(game_object& obj) override
    {
        obj.motion.dx += std::cos(obj.motion.angle * constants::DEG_TO_RAD) *
          obj.motion.acceleration;
        obj.motion.dy += std::sin(obj.motion.angle * constants::DEG_TO_RAD) *
          obj.motion.acceleration;

        if (double speed = current_speed(obj.motion.dx, obj.motion.dy);
          speed > obj.motion.max_speed)
        {
            obj.motion.dx *= obj.motion.max_speed / speed;
            obj.motion.dy *= obj.motion.max_speed / speed;
        }
    }
};
