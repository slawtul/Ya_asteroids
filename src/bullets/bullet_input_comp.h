#pragma once

#include "game_object.h"

struct bullet_input_comp
{
  bullet_input_comp(const game_object &go);

  void update();

  game_object go;
};
