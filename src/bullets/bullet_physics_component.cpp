#include "bullet_physics_component.h"
#include <init/constants.h>

void bullet_physics_component::update(game_object &obj) {
  obj.motion.dx += std::cos(obj.motion.angle * constants::DEG_TO_RAD) *
                   obj.motion.acceleration;
  obj.motion.dy += std::sin(obj.motion.angle * constants::DEG_TO_RAD) *
                   obj.motion.acceleration;

  if (double speed = current_speed(obj.motion.dx, obj.motion.dy);
      speed > obj.motion.max_speed) {
    obj.motion.dx *= obj.motion.max_speed / speed;
    obj.motion.dy *= obj.motion.max_speed / speed;
  }
}
