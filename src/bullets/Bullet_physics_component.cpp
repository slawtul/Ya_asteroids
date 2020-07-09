#include "Bullet_physics_component.h"

void Bullet_physics_component::update(Game_object &obj)
{
  obj.motion.dx += std::cos(obj.motion.angle * Constants::DEG_TO_RAD) *
    obj.motion.acceleration;
  obj.motion.dy += std::sin(obj.motion.angle * Constants::DEG_TO_RAD) *
    obj.motion.acceleration;

  if (double speed = current_speed(obj.motion.dx, obj.motion.dy);
    speed > obj.motion.max_speed)
  {
    obj.motion.dx *= obj.motion.max_speed / speed;
    obj.motion.dy *= obj.motion.max_speed / speed;
  }
}