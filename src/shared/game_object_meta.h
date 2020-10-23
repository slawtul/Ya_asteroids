#pragma once

#include "object_name.h"

struct game_object_meta
{
  object_name name{object_name::NONE};

  // You can do physics and gfx calculations on 'active' object only
  // If game object is not active - it's removed from game objects vector
  bool is_active{true};
};
