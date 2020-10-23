#pragma once

#include "game_object.h"

struct bullet_input_comp: input_comp
{
  void update(game_object &obj) override;
};
