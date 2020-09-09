#pragma once

#include "game_object.h"

struct bullet_input_component : input_component {
  void update(game_object &obj) override;
};
