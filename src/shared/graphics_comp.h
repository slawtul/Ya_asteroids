#pragma once

#include "graphics.h"

struct game_object;

struct graphics_comp
{
  graphics_comp() = default;
  virtual ~graphics_comp() = default;
  virtual void update(game_object &obj, graphics &gfx) = 0;
  static bool off_screen(int rect_x, int rect_y, const graphics &gfx);

  // If object crosses screen edge it appears on the opposite edge
  static std::pair<int, int>
  calc_position_if_edge_screen_reached(int rect_x, int rect_y, int rect_w,
                                       int rect_h, const graphics &gfx);
};
