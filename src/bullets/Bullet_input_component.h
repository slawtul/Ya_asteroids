#pragma once

#include "Game_object.h"

struct Bullet_input_component: Input_component
{
  void update(Game_object &obj) override;
};
