#pragma once

#include "graphics.h"

struct game_object;

struct gfx_comp
{
    gfx_comp() = default;
    virtual ~gfx_comp() = default;
    virtual void update(game_object& obj, graphics& gfx) = 0;
    static bool off_screen(int rect_x, int rect_y, const graphics& gfx);

    // If object crosses screen edge it appears on the opposite edge
    static std::pair<int, int> recalculate_position(
      int rect_x,
      int rect_y,
      int rect_w,
      int rect_h,
      const graphics& graphics);
};
