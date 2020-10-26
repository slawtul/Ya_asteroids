#pragma once

#include <SDL.h>
#include <vector>
#include "game_object.h"
#include "graphics.h"

struct destroy_asteroids_scene
{
    void update(SDL_Event& event,
        graphics& gfx,
        std::vector<game_object>& game_objects);
};
