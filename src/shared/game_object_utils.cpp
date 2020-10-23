#include "game_object_utils.h"
#include "bullet_graphics_comp.h"
#include "bullet_input_comp.h"
#include "bullet_physics_comp.h"
#include "spaceship1_graphics_comp.h"
#include "spaceship1_input_comp.h"
#include "spaceship1_physics_comp.h"
#include "spaceship2_graphics_comp.h"
#include "spaceship2_input_component.h"
#include "spaceship2_physics_component.h"

game_object game_object_utils::create_spaceship1()
{
  auto go = game_object(
    std::make_unique<spaceship1_input_comp>(),
    std::make_unique<spaceship1_physics_comp>(),
    std::make_unique<spaceship1_graphics_comp>());
  go.meta.name = object_name::SPACESHIP1;
  go.motion.max_speed = 8.0;
  go.rect = {0, 0, 64, 64};
  return go;
}

game_object game_object_utils::create_spaceship2()
{
  auto go = game_object(
    std::make_unique<spaceship2_input_component>(),
    std::make_unique<spaceship2_physics_component>(),
    std::make_unique<spaceship2_graphics_comp>());
  go.meta.name = object_name::SPACESHIP2;
  go.motion.max_speed = 8.0;
  go.rect = {256, 1000, 64, 64};
  return go;
}

game_object game_object_utils::create_bullet()
{
  auto go = game_object(
    std::make_unique<bullet_input_comp>(),
    std::make_unique<bullet_physics_comp>(),
    std::make_unique<bullet_graphics_comp>());
  go.meta.name = object_name::BULLET;
  go.motion.acceleration = 32;
  go.rect = {0, 0, 4, 20};
  return go;
}

game_object &game_object_utils::fire_bullet(game_object &bullet,
                                            const game_object &spaceship)
{
  bullet.rect.x = spaceship.rect.x + (spaceship.rect.w - bullet.rect.w) / 2;
  bullet.rect.y = spaceship.rect.y + (spaceship.rect.h - bullet.rect.h) / 2;
  bullet.motion.angle = spaceship.motion.angle;
  bullet.motion.max_speed = spaceship.motion.max_speed * 4;
  return bullet;
}
