#include "spaceship1_input.h"
#include "SDL.h"

void spaceship1_input::update(game_object& obj)
{
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT])
    {
        obj.motion.angle += 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT])
    {
        obj.motion.angle -= 4.0;
    }
    if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP])
    {
        obj.motion.acceleration = 0.6;
        obj.motion.max_speed = 8.0;
    }
    else
    {
        obj.motion.acceleration = 0.2;
        obj.motion.max_speed = 6.0;
    }
}
