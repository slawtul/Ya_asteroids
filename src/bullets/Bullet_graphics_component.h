#pragma once

#include "Game_object.h"

struct Bullet_graphics_component : Graphics_component {
  void update(Game_object &obj, Graphics &graphics) override;
};
