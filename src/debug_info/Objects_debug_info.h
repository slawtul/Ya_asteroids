#pragma once

#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <text/Render_text.h>

struct Objects_debug_info
{
    uint8_t objs_on_screen{0};
    uint8_t max_objs_on_screen{0};

    uint8_t count_objs()
    {
        if (objs_on_screen > max_objs_on_screen)
        {
            max_objs_on_screen = objs_on_screen;
        }
        return max_objs_on_screen;
    }

    void render_obj_qty(
        TTF_Font *font,
        SDL_Color color,
        SDL_Renderer *renderer) const
    {
        auto rect = SDL_Rect{20, 56, 120, 16};
        Render_text rt;
        rt.render(
            rect, font, color, renderer,
            "Obj_qty: " + std::to_string(objs_on_screen));
    }

    void render_max_obj_qty(
        TTF_Font *font,
        SDL_Color color,
        SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 72, 120, 16};
        Render_text rt;
        rt.render(
            rect, font, color, renderer,
            "Max_qty: " + std::to_string(count_objs()));
    }
};
