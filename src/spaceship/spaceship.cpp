#include "spaceship.h"


spaceship::spaceship(
    SDL_Renderer *renderer,
    const SDL_Rect &rect,
    texture_shelf &ts,
    const obj_meta &meta,
    const obj_motion &motion)
    : renderer{ renderer }, rect{ rect }, ts{ ts }, meta{ meta },
      motion{ motion }
{
}

void spaceship::update()
{
    input();
    physics();
    gfx();
}

void spaceship::input()
{
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT])
    {
        motion.angle += 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT])
    {
        motion.angle -= 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP])
    {
        motion.acceleration = 0.6;
        motion.max_speed = 8.0;
    }
    else
    {
        motion.acceleration = 0.2;
        motion.max_speed = 6.0;
    }
}

void spaceship::physics()
{
    motion.dx += std::cos(motion.angle * constants::DEG_TO_RAD) *
        motion.acceleration;
    motion.dy += std::sin(motion.angle * constants::DEG_TO_RAD) *
        motion.acceleration;

    if (double speed = physics_helpers::current_speed(motion.dx, motion.dy);
        speed > motion.max_speed)
    {
        motion.dx *= motion.max_speed / speed;
        motion.dy *= motion.max_speed / speed;
    }
}

void spaceship::gfx()
{
    rect.x += static_cast<int>(motion.dx);
    rect.y += static_cast<int>(motion.dy);

    auto[x, y] = gfx_helpers::opposite_edge_position(
        rect.x,
        rect.y,
        rect.w,
        rect.h,
        renderer);

    rect.x = x;
    rect.y = y;

    SDL_RenderCopyEx(
        renderer,
        ts.get_texture("WO84-wu-X1"),
        nullptr,
        &rect,
        motion.angle + 90,
        nullptr,
        SDL_FLIP_NONE);
}

