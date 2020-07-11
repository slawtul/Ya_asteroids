#pragma once

#include "Game_object.h"

struct Spaceship2_input_component: Input_component
{
    void update(Game_object &obj) override
    {
        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_D])
        {
            obj.motion.angle += 4.0;
        }
        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_A])
        {
            obj.motion.angle -= 4.0;
        }
        if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_W])
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
};
