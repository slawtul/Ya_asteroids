#pragma once

#include "Graphics.h"

struct Game_object;

struct Graphics_component
{
    Graphics_component() = default;

    virtual ~Graphics_component() = default;

    virtual void update(Game_object &obj, Graphics &graphics) = 0;

    static bool off_screen(int rect_x, int rect_y, const Graphics &graphics)
    {
        int screen_width, screen_height;
        SDL_GetRendererOutputSize(graphics.renderer, &screen_width, &screen_height);

        return rect_x < 0 || rect_y < 0 || rect_x > screen_width || rect_y > screen_height;
    }

    // If object crosses screen edge it appears on the opposite edge
    static std::pair<int, int> calc_position_if_edge_screen_reached(
        int rect_x, int rect_y, int rect_w, int rect_h, const Graphics &graphics
    )
    {
        int screen_width, screen_height;
        SDL_GetRendererOutputSize(graphics.renderer, &screen_width, &screen_height);

        if (rect_x > screen_width) rect_x = -rect_w;
        if (rect_y > screen_height) rect_y = -rect_h;
        if (rect_x < -rect_w) rect_x = screen_width;
        if (rect_y < -rect_h) rect_y = screen_height;

        return {rect_x, rect_y};
    }
};
