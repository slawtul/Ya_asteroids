#pragma once

#include <vector>
#include <SDL.h>
#include "Graphics.h"
#include "Game_object.h"

struct Destroy_asteroids_scene
{
    void update(
        SDL_Event &event,
        Graphics &graphics,
        std::vector<Game_object> &game_objects
    );
};
