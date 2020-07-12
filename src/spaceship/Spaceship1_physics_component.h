#pragma once

#include <cmath>

#include "Game_object.h"
#include "init/Constants.h"

struct Spaceship1_physics_component : Physics_component {
  void update(Game_object &obj) override {
    obj.motion.dx += std::cos(obj.motion.angle * Constants::DEG_TO_RAD) *
                     obj.motion.acceleration;
    obj.motion.dy += std::sin(obj.motion.angle * Constants::DEG_TO_RAD) *
                     obj.motion.acceleration;

    if (double speed = current_speed(obj.motion.dx, obj.motion.dy);
        speed > obj.motion.max_speed) {
      obj.motion.dx *= obj.motion.max_speed / speed;
      obj.motion.dy *= obj.motion.max_speed / speed;
    }
  }
};
