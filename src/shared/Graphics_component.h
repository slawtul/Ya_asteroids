#pragma once

#include "Graphics.h"

struct Game_object;

struct Graphics_component
{
    Graphics_component() = default;

    virtual ~Graphics_component() = default;

    virtual void update(Game_object &obj, Graphics &graphics) = 0;

    static bool off_screen(
        int rect_x,
        int rect_y,
        const Graphics &graphics
    );

    // If object crosses screen edge it appears on the opposite edge
    static std::pair<int, int> calc_position_if_edge_screen_reached(
        int rect_x,
        int rect_y,
        int rect_w,
        int rect_h,
        const Graphics &graphics
    );
};
