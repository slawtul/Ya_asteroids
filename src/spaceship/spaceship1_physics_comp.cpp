#include "spaceship1_physics_comp.h"

spaceship1_physics_comp::spaceship1_physics_comp(const game_object &go)
  : go(go)
{}

void spaceship1_physics_comp::update()
{
  go.motion.dx += std::cos(go.motion.angle * constants::DEG_TO_RAD) *
    go.motion.acceleration;
  go.motion.dy += std::sin(go.motion.angle * constants::DEG_TO_RAD) *
    go.motion.acceleration;

  if (double speed = physics_comp::current_speed(go.motion.dx, go.motion.dy);
    speed > go.motion.max_speed) {
    go.motion.dx *= go.motion.max_speed / speed;
    go.motion.dy *= go.motion.max_speed / speed;
  }

}
