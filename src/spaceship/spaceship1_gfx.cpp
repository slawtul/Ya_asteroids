#include "spaceship1_gfx.h"

void spaceship1_gfx::update(game_object& obj, graphics& graphics)
{
    obj.rect.x += static_cast<int>(obj.motion.dx);
    obj.rect.y += static_cast<int>(obj.motion.dy);

    auto[x, y] = recalculate_position(
        obj.rect.x,
        obj.rect.y,
        obj.rect.w,
        obj.rect.h,
        graphics);

    obj.rect.x = x;
    obj.rect.y = y;

    SDL_RenderCopyEx(
        graphics.renderer,
        graphics.tex_shelf.get_texture("WO84-wu-X1"),
        nullptr,
        &obj.rect,
        obj.motion.angle + 90,
        nullptr,
        SDL_FLIP_NONE);
}
