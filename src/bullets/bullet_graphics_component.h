#pragma once

#include "game_object.h"

struct bullet_graphics_component : graphics_component {
  void update(game_object &obj, graphics &graphics) override;
};
