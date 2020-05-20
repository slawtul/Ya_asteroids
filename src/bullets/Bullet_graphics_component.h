#pragma once

#include "Game_object.h"

struct Bullet_graphics_component: Graphics_component
{
    void update(Game_object &obj, Graphics &graphics) override
    {
        obj.rect.x += static_cast<int>(obj.motion.dx);
        obj.rect.y += static_cast<int>(obj.motion.dy);

        if (off_screen(obj.rect.x, obj.rect.y, graphics)) {
            obj.meta.is_active = false;
            return;
        }

        auto[x, y] = calc_position_if_edge_screen_reached(
            obj.rect.x, obj.rect.y, obj.rect.w, obj.rect.h, graphics
        );
        obj.rect.x = x;
        obj.rect.y = y;

        SDL_RenderCopyEx(
            graphics.renderer, graphics.texture_shelf.get_texture("bullet_short_single"),
            nullptr, &obj.rect, obj.motion.angle + 90, nullptr, SDL_FLIP_NONE
        );
    }
};

