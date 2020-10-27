#include <iostream>
#include "bullet.h"


bullet::bullet(
    SDL_Renderer *renderer,
    SDL_Rect &rect,
    texture_shelf &ts,
    obj_meta &meta,
    obj_motion &motion,
    spaceship &ship)
    : renderer(renderer), rect(rect), ts(ts), meta(meta), motion(motion), ship(ship)
{
}

void bullet::update()
{
    input();
    physics();
    gfx();
}

void bullet::input()
{
    // no user input for bullet
}

void bullet::physics()
{
    motion.dx += std::cos(motion.angle * constants::DEG_TO_RAD)
        * motion.acceleration;
    motion.dy += std::sin(motion.angle * constants::DEG_TO_RAD) *
        motion.acceleration;

    if (double speed = physics_helpers::current_speed(motion.dx, motion.dy);
        speed > motion.max_speed)
    {
        motion.dx *= motion.max_speed / speed;
        motion.dy *= motion.max_speed / speed;
    }
}

void bullet::gfx()
{
    rect.x += static_cast<int>(motion.dx);
    rect.y += static_cast<int>(motion.dy);

    if (gfx_helpers::is_off_screen(rect.x, rect.y, renderer))
    {
        meta.is_active = false;
        return;
    }

    SDL_RenderCopyEx(
        renderer,
        ts.get_texture("bullet_short_single"),
        nullptr,
        &rect,
        motion.angle + 90,
        nullptr,
        SDL_FLIP_NONE);
}
