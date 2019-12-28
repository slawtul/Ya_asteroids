#pragma once

#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <text/Render_text.h>

struct Objects_debug_info
{
    size_t objects_on_screen{0};
    size_t max_objects_on_screen{0};

    size_t calc_max_objects_on_screen()
    {
        if (objects_on_screen > max_objects_on_screen) {
            max_objects_on_screen = objects_on_screen;
        }
        return max_objects_on_screen;
    }

    void render_obj_quantity(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 56, 120, 16};
        Render_text rt;
        rt.render_text(rect, font, color, renderer, "Obj_qty: " + std::to_string(objects_on_screen));
    }

    void render_max_obj_quantity(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
    {
        auto rect = SDL_Rect{20, 72, 120, 16};
        Render_text rt;
        rt.render_text(
            rect, font, color, renderer, "Max_qty: " + std::to_string(calc_max_objects_on_screen())
        );
    }
};
