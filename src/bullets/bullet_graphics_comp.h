#pragma once

#include "game_object.h"

struct bullet_graphics_comp : graphics_comp {

  void update(game_object &obj, graphics &graphics) override;
};
