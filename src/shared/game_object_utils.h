#pragma once

#include "game_object.h"

struct game_object_utils
{
  game_object create_spaceship1();
  game_object create_spaceship2();
  game_object create_bullet();
  game_object &fire_bullet(game_object &bullet, const game_object &spaceship);
};
